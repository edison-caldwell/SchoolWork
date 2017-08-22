// lab1.h


#ifndef _STR1
#define _STR1

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

class StrClass
{

	public:
		StrClass( );
		StrClass(const StrClass &);// copy construtor
		~StrClass( );

// ***Convert Constructors
		//StrClass(const char *); // convert from cstring
		StrClass(const string & s); // convert from string
		StrClass(const char c); // convert from char
		
// ***Operators
		const StrClass & operator=(const StrClass & );	
// ***Setters 
 		void SetStr(const char *);
// **Observers				
		string Str( ) const;
		void DisplayStr( ) const;
		bool IsPal( ) const;
		
	private:
		char * str;  // encapsulated pointer for cstring
		
		char * CopyStr(char *to_str, const char *from_str) const;
};

#endif




