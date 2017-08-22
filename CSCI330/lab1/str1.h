// str1.h


#ifndef _STR1
#define _STR1

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

class StrClass
{

	public:
		StrClass( ); // default constructor
		StrClass(const StrClass & s); // copy constructor
		StrClass(const string & s); // convert constructor: string->char*
		StrClass(const char * s); // parameterized constructor		
		StrClass(char c); // convert constructor: char->char*

		~StrClass(); // destructor
		StrClass & operator=(const StrClass & s); // overloaded assignment op
		
		string Str( ) const; // Return data as string
		void SetStr(const char *); // modify data
		void DisplayStr( ) const; // output data to cout
		bool IsPal( ) const; // check if data is palindrome
				

	private:
		
		char* str;


};

#endif




