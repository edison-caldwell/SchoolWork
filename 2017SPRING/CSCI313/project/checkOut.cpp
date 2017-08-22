/*
* This application ends a reservation and creates a bill for the guest.
* Compile Line:  c++ -o checkOut checkOut.cpp $(mysql_config --libs)
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
const string BILL_TABLE = "Bill";
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
          cost_str;
   bool logged_in = false;
   int fieldCnt;

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

   //Create guest bill.
   //Get cost.
   command = "SELECT cost FROM " + RES_TABLE + " WHERE reservationID = " + resID;
   if (mysql_query(conn, command.c_str()) != 0) 
   {
      cout << "An error has occured." << endl;
      cout << mysql_error(conn) << endl;
      return -1;
   }

   queryResult = mysql_store_result(conn);

   if ((aRow = mysql_fetch_row(queryResult)) != NULL) 
   {
      cost_str = aRow[0];
   }
   mysql_free_result(queryResult);
   
   //Create bill.
   command = "INSERT INTO " + BILL_TABLE + " VALUES(NULL," + resID + "," + memberID + "," + cost_str + ");";
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
      cout << "Check out complete." << endl;
      cout << "Amount due: " << cost_str << "." << endl;
   }
   
   mysql_close(conn);
   
   return 0;
}
