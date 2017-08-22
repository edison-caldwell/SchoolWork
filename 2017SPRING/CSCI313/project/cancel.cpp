/*
* This application cancels a reservation based on user input.
* Compile Line:  c++ -o cancel cancel.cpp $(mysql_config --libs)
*/
#include "/usr/include/mysql/mysql.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

const string DB = "teamF";
const string PASSWORD = "070396";
const string LOGIN_TABLE = "Guest";
const string RES_TABLE = "Reservation";
const string RES_ROOM_TABLE = "ResRooms";
const string ROOM_TABLE = "Room";
const float ROOM_COST = 49.99;

int main() 
{
   MYSQL * conn;
   MYSQL_RES * queryResult;
   MYSQL_ROW aRow;
   string command,
          memberID,
          resID,
          password,
          hotelID,
          dateIn,
          dateDiff;
   bool logged_in = false;
   int fieldCnt,
       diffNum;

   //Get user ID.
   cout << "Enter memberID=>";
   cin >> memberID;

   //Get user password.
   cout << "Enter password=>";
   cin >> password;
   cout << endl;
   
   //Connect to database.
   conn = mysql_init(NULL);
   if (mysql_real_connect(conn, "", "", PASSWORD.c_str(), DB.c_str(), 0, NULL, 0)
       == NULL)
   {
     cout << "Connection Failed: " << endl;
     cout << mysql_error(conn) << endl;
     return -1;
   }
   
   //Validate password.
   command = "SELECT password FROM " + LOGIN_TABLE + " WHERE memberID = " + memberID;
   if (mysql_query(conn, command.c_str()) != 0) 
   {
      cout << "Query failed: " << endl;
      cout << mysql_error(conn) << endl;
      return -1;
   }

   queryResult = mysql_store_result(conn);

   if ((aRow = mysql_fetch_row(queryResult)) != NULL) 
   {
      if(aRow[0] == password)
      {
        logged_in = true;  
        cout << "Login successful!" << endl;
      }else{
        cout << "MemberID or Password is incorrect. Login failed." << endl;
        return -1;
      }
   }
   mysql_free_result(queryResult);
   
   //Get reservation ID.
   cout << "Enter reservation ID=>";
   cin >> resID;
   cout << endl;
   
   //Check date. Cancellation can only be made within 1 day of reservation.
   //Get dateIn
   command = "SELECT dateIn FROM " + RES_TABLE + " WHERE reservationID = " + resID;
   if (mysql_query(conn, command.c_str()) != 0)
   {
      cout << "Query failed: " << endl;
      cout << mysql_error(conn) << endl;
      return -1;
   }
   queryResult = mysql_store_result(conn);
   if ((aRow = mysql_fetch_row(queryResult)) != NULL) 
   {
      dateIn = aRow[0];
   }else{
      cout << "Something is incorrect. Request denied." << endl;
      return -1;
   }
   
   mysql_free_result(queryResult);
   
   //Check to see if date is in range.
   command = "SELECT DATEDIFF('" + dateIn + "',CURDATE())";
   if (mysql_query(conn, command.c_str()) != 0)
   {
      cout << "Query failed: " << endl;
      cout << mysql_error(conn) << endl;
      return -1;
   }
   queryResult = mysql_store_result(conn);
   if ((aRow = mysql_fetch_row(queryResult)) != NULL) 
   {
      dateDiff = aRow[0];
      //convert date difference to int.
      stringstream  convert(dateDiff);
      convert >> diffNum;
      if(diffNum < 1){
        cout << "Reservations can only be cancelled up to the day before." << endl;
        return -1;
      }
   }else{
      cout << "Something is incorrect. Request denied." << endl;
      return -1;
   }
   
   mysql_free_result(queryResult);
   
   //Free rooms.
   //Get hotel ID.
   command = "SELECT hotelID FROM " + RES_TABLE + " WHERE reservationID = " + resID;
   if (mysql_query(conn, command.c_str()) != 0)
   {
      cout << "Query failed: " << endl;
      cout << mysql_error(conn) << endl;
      return -1;
   }
   queryResult = mysql_store_result(conn);
   if ((aRow = mysql_fetch_row(queryResult)) != NULL) 
   {
      hotelID = aRow[0];
   }else{
      cout << "Something is incorrect. Request denied." << endl;
      return -1;
   }
  
   mysql_free_result(queryResult);

   //Get room nums.
   command = "SELECT roomNum FROM " + RES_ROOM_TABLE + " WHERE reservationID = " + resID;
   if (mysql_query(conn, command.c_str()) != 0)
   {
      cout << "Query failed: " << endl;
      cout << mysql_error(conn) << endl;
      return -1;
   }
   queryResult = mysql_store_result(conn);
  
   //Free one room at a time.
   fieldCnt = mysql_num_fields(queryResult);
   while ((aRow = mysql_fetch_row(queryResult)) != NULL) 
   {
      for(int i = 0; i < fieldCnt; i++){ 
         if (aRow[i] != NULL){
            command = "UPDATE " + ROOM_TABLE + " SET open = 1 where roomNum = " + aRow[i] + " and hotelID = " + hotelID;
            if (mysql_query(conn, command.c_str()) != 0)
            {
              cout << "Query failed: " << endl;
              cout << mysql_error(conn) << endl;
              return -1;
            }
         }
      }
   } 

   mysql_free_result(queryResult);

   //Delete room reservation.
   command = "DELETE FROM " + RES_ROOM_TABLE + " WHERE reservationID = " + resID;
   if (mysql_query(conn, command.c_str()) != 0)
   {
      cout << "Query failed: " << endl;
      cout << mysql_error(conn) << endl;
      return -1;
   }

   //Delete reservation
   command = "DELETE FROM " + RES_TABLE + " WHERE reservationID = " + resID + " and memberID = " + memberID;
   if (mysql_query(conn, command.c_str()) != 0)
   {
      cout << "Query failed: " << endl;
      cout << mysql_error(conn) << endl;
      return -1;
   }else{
      cout << "Reservation " << resID << " has been cancelled!" << endl;
   }


   mysql_close(conn);
   
   return 0;
}
