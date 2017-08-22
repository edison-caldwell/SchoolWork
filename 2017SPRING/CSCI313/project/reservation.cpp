/*
* This application creates a reservation based on user input.
* Compile Line:  c++ -o reservation reservation.cpp $(mysql_config --libs)
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
const string HOTEL_TABLE = "Hotel";
const float ROOM_COST = 49.99;

int main() 
{
   MYSQL * conn;
   MYSQL_RES * queryResult;
   MYSQL_ROW aRow;
   string command,
          memberID,
          password,
          dateIn,
          dateOut,
          location,
          guests,
          hotelID,
          rooms_str,
          cost_str,
          roomNum,
          resID,
          dateDiff;
   int rooms,
       fieldCnt,
       diffNum;
   float cost;
   bool logged_in = false;
   ostringstream  convert1,
                  convert2;

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
      cout << "MemberID not valid. Login failed" << endl;
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
      }
   }
   mysql_free_result(queryResult);
   
   //Get reservation details.
   //Get date in.
   cout << "Enter date of reservation(YYYY-MM-DD)=>";
   cin >> dateIn;
   cout << endl;
   
   //Get date out.
   cout << "Enter date you plan to check out(YYYY-MM-DD)=>";
   cin >> dateOut;
   cout << endl;

   //Get # of guests.
   cout << "Enter number of guests=>";
   cin >> guests;
   cout << endl;
   
   //Get # of rooms.
   cout << "Enter number of rooms=>";
   cin >> rooms;
   cout << endl;
   
   //Get location.
   cout << "Enter desired location(Erie/Pittsburgh/Cleveland)=>";
   cin >> location;
   cout << endl;
   
   //Calculate number of nights.
   command = "SELECT DATEDIFF('" + dateOut + "','" + dateIn + "')";
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
        cout << "Date range not valid." << endl;
        return -1;
      }
   }else{
      cout << "Something is incorrect. Request denied." << endl;
      return -1;
   }
   
   mysql_free_result(queryResult);
   
   //Get hotel details.
   command = "SELECT hotelID FROM " + HOTEL_TABLE + " WHERE location = '" + location + "'";
   if (mysql_query(conn, command.c_str()) != 0) 
   {
      cout << location << " is not a valid location." << endl;
      cout << mysql_error(conn) << endl;
      return -1;
   }

   queryResult = mysql_store_result(conn);

   if ((aRow = mysql_fetch_row(queryResult)) != NULL) 
   {
      hotelID = aRow[0];
   }
   mysql_free_result(queryResult);
   
   //Calculate cost.
   cost = ROOM_COST*rooms*diffNum;
   
   //Convert numerical values to strings.
   convert1 << rooms;
   rooms_str = convert1.str();
   
   convert2 << cost;
   cost_str = convert2.str();
   
   //Insert details into reservation table.
   command = "INSERT INTO " + RES_TABLE + " VALUES(NULL," + memberID + ",'" + dateIn + "','" + dateOut + "'," + guests + "," + rooms_str + "," + hotelID + "," + cost_str + ");";
   if (mysql_query(conn, command.c_str()) != 0)
   {
      cout << "Query failed: " << endl;
      cout << mysql_error(conn) << endl;
      return -1;
   }

   cout << "Reservation approved!" << endl;
   
   //Get reservationID;
   command = "SELECT reservationID FROM " + RES_TABLE + " WHERE memberID = " + memberID + " and dateIn = '" + dateIn + "' and dateOut = '" + dateOut + "' and hotelID =" + hotelID;
   if (mysql_query(conn, command.c_str()) != 0) 
   {
       cout << "Query failed: " << endl;
       cout << mysql_error(conn) << endl;
       return -1;
   }
   queryResult = mysql_store_result(conn);
   if ((aRow = mysql_fetch_row(queryResult)) != NULL) 
   {
      resID = aRow[0];
   }else{
      cout << "Something is incorrect. Request denied." << endl;
      return -1;
   }
   mysql_free_result(queryResult);
   
   //Assign rooms.
   for(int i=0; i < rooms; i++)
   {
      //Find open room.
      command = "select roomNum from " + ROOM_TABLE + " WHERE hotelID = " + hotelID + " and open = 1";
      if (mysql_query(conn, command.c_str()) != 0) 
      {
        cout << "Query failed: " << endl;
        cout << mysql_error(conn) << endl;
        return -1;
      }
      queryResult = mysql_store_result(conn);
      aRow = mysql_fetch_row(queryResult);
      roomNum = aRow[0];
      mysql_free_result(queryResult);

      //Book room.
      command = "INSERT INTO " + RES_ROOM_TABLE + " VALUES("+ resID +","+ roomNum +");";
      if (mysql_query(conn, command.c_str()) != 0)
      {
        cout << "Query failed: " << endl;
        cout << mysql_error(conn) << endl;
        return -1;
      }

      //Close room.
      command = "UPDATE " + ROOM_TABLE + " SET open = 0 WHERE roomNum = " + roomNum + " and hotelID = " + hotelID;
      if (mysql_query(conn, command.c_str()) != 0)
      {
        cout << "Query failed: " << endl;
        cout << mysql_error(conn) << endl;
        return -1;
      }
   }

   //Display Reservation.
   cout << "Your reservation ID is " << resID << "." << endl;

   //Display rooms.
   command = "SELECT roomNum FROM " + RES_ROOM_TABLE + " WHERE reservationID = " + resID;
   if (mysql_query(conn, command.c_str()) != 0) 
   {
     cout << "Query failed: " << endl;
     cout << mysql_error(conn) << endl;
     return -1;
   }

   queryResult = mysql_store_result(conn);

   fieldCnt = mysql_num_fields(queryResult);
   cout << "Your room numbers are:" << endl;
   while ((aRow = mysql_fetch_row(queryResult)) != NULL) 
   {
     for(int i = 0; i < fieldCnt; i++) 
       if (aRow[i] != NULL)
         cout << "  Room " << aRow[i];
         cout << endl;
   } 
   
   mysql_free_result(queryResult);
   mysql_close(conn);

   return 0;
}
