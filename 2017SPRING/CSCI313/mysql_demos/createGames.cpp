#include "/usr/include/mysql/mysql.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const string DB = "e737108c";
const string PASSWORD = "021093";
const string TABLE = "GOTANYGAMES?";

int main() 
{
   MYSQL * conn;
   MYSQL_RES * queryResult;
   MYSQL_ROW aRow;
   string command;
   int fieldCnt;

   conn = mysql_init(NULL);

   if (mysql_real_connect(conn, "", "", PASSWORD.c_str(), DB.c_str(), 0, NULL, 0)
       == NULL)
   {
     cout << "Connection Failed: " << endl;
     cout << mysql_error(conn) << endl;
     return -1;
   }

   command = "create table " + TABLE + " (";
   command += "game varchar(25) primary key, ";
   command += "comment varchar(25));";
 
   cout << endl << command << endl << endl;
 
   if (mysql_query(conn, command.c_str()) != 0) 
   {
      cout << "Query failed: " << endl;
      cout << mysql_error(conn) << endl;
      return -1;
   }

   mysql_free_result(queryResult);
   mysql_close(conn);
   
   return 0;
}
