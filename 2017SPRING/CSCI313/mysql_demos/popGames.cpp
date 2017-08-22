
#include "/usr/include/mysql/mysql.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const string DB = "yourdatabase";
const string PASSWORD = "yourpwd";
const string TABLE = "tablename";

struct Game
{
  string game;;
  string comment;
};

int main() 
{
   MYSQL * conn;
   MYSQL_RES * queryResult;
   MYSQL_ROW aRow;
   string command;
   int fieldCnt;

   Game games[50];

   games[0].game = "Scrabble";
   games[0].comment = "Word enriching";
   games[1].game = "Pictionary";
   games[1].comment = "Fast paced and fun";
   games[2].game = "Golf cards";
   games[2].comment = "For all ages";
   int many = 3;
   
   conn = mysql_init(NULL);

   if (mysql_real_connect(conn, "", "", PASSWORD.c_str(), DB.c_str(), 0, NULL, 0)
       == NULL)
   {
     cout << "Connection Failed: " << endl;
     cout << mysql_error(conn) << endl;
     return -1;
   }

   for (int k = 0; k < many; k++)
   {
     command = "insert into " + TABLE + " values (";
     command += '"' + games[k].game + "\", ";
     command += '"' + games[k].comment + "\");";

     cout << endl << command << endl;
      
     if (mysql_query(conn, command.c_str()) != 0) 
     {
        cout << "Query failed: " << endl;
        cout << mysql_error(conn) << endl;
        return -1;
     }
   }
   cout << endl;
   
   command = "select * from " + TABLE;
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
   
   mysql_free_result(queryResult);
   mysql_close(conn);
   
   return 0;
}
