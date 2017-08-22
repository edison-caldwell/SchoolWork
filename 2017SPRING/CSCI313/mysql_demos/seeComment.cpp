
#include "/usr/include/mysql/mysql.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const string DB = "yourdatabase";
const string PASSWORD = "yourpwd";
const string TABLE = "tablename";

int main() 
{
   MYSQL * conn;
   MYSQL_RES * queryResult;
   MYSQL_ROW aRow;
   string command;
   int fieldCnt;
   string aName;
   
   conn = mysql_init(NULL);

   if (mysql_real_connect(conn, "", "", PASSWORD.c_str(), DB.c_str(), 0, NULL, 0)
       == NULL)
   {
     cout << "Connection Failed: " << endl;
     cout << mysql_error(conn) << endl;
     return -1;
   }

   cout << endl << "Wamt to see a game comment? " << endl;
   cout << "Enter the game name: ";
   cin >> aName;   
   
   command = "select comment from " + TABLE +
             " where game = \"" + aName + '"';
             
   cout << endl << command << endl << endl;
             
   if (mysql_query(conn, command.c_str()) != 0) 
   {
      cout << "Query failed: " << endl;
      cout << mysql_error(conn) << endl;
      return -1;
   }

   queryResult = mysql_store_result(conn);

   fieldCnt = mysql_num_fields(queryResult);
   while ((aRow = mysql_fetch_row(queryResult)) != NULL) 
   {
      for(int i = 0; i < fieldCnt; i++) 
         if (aRow[i] != NULL)
            cout << " " << aRow[i] << " ";
      cout << endl;
   } 

   cout << endl;
   
   mysql_free_result(queryResult);
   mysql_close(conn);
   
   return 0;
}
