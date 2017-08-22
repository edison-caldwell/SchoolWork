
// maps

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>

using namespace std;

// 3. Declare PrintAuthor( )

// 4. Declare PrintAuthorList( )

int main( )
{
	ifstream fin;
	fin.open("authors.in");
	string lname, fname;

	// 1. Declare a map to hold the authors.  Use the last name as the key

	fin >>fname >> lname;
	while (fin)
	{
	  // 2. Insert the record into the map
	  
	   
	  fin >> fname >> lname;

	}
	cout << endl <<endl;
	
	// 4. Call PrintAuthorList- insert arguments
	PrintAuthorList(  );
	
	cout <<"*****"<<endl;	
	
	// 5. Using for_each algorithm, print each author pair in map


	
	cout <<endl <<endl;

	return 0;
}

// 3. Implement the function PrintAuthor( )
//    to print a single author pair 
//    firstname  \t  lastname
void PrintAuthor(pair<string,string> author)
{
	cout <<
	cout <<endl;
}


// 4. Implement the function PrintAuthorList( )
//    to print each of the author pairs in the map on a seperate line
//    firstname  \t  lastname
void PrintAuthorList(  )
{
	cout << "List of authors:"<<endl;



	cout <<endl<<endl;
}



