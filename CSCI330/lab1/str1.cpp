// str1.cpp


#include "str1.h"
#include <iomanip>

StrClass::StrClass( )
{
	str = NULL;
}

StrClass::~StrClass( )
{
	delete str;
}

StrClass::StrClass(const StrClass& s )
{
//s.str == NULL
	if(s.str == NULL)
		str = NULL;
//s.str != NULL
	else
	{
		int len = strlen(s.str)+1;
		str = new char[len];
		/*
		for (int i=0; i< strlen(s.str)+1;i++)
		*/
		strcpy(str, s.str);
	}
}

StrClass & StrClass::operator=(const StrClass& s )
{ 
	if(this  !=  s.this)
	{
	  delete [] str; //does nothing if str points to null
	  str = NULL;
	  
	  if(s.str != NULL)
	    {
	      int len = strlen(s.str)+1;
	      str = new char[len];
              strcpy(str, s.str);
	    }
	}

	return *this;
}

char* CopyStr(char* to, char* from) const
//top level function that copies one dynamic cstring to another
{
	if(to!= from)
	{
	  delete [] to;
	  to = NULL;	
	  if((from != NULL) && (from[0] != '\0')
	  {
	    int len = strlen(from)+ 1;
	    to = new [len];
	    strcpy(to,from);
	  }
  return to;
}

StrClass::StrClass(const string& s )
{
	str = NULL;
	str = CopyStr(str, s.str);
}


StrClass::StrClass(const char * s )
{
	str = NULL;
	if(s != NULL)
	{
	  str = CopyStr(str, s.str);
	}

}

string StrClass::Str( ) const
{
  return str;

}


void StrClass::SetStr(const char *s)
{

}
	

void StrClass::DisplayStr( ) const
{

}
	
bool StrClass::IsPal( ) const
{
  int len;
  
  len = strlen(str);

  char [len] tempStr;

  
}

void PrintTest(ostream & out, string test)
{
  static string testch = "T";
  static int testnum = 1;
  if ((test != testch) && (test !=""))
  {
     testch = test;
     testnum = 1;
  }
  out << testch<<left<<setw(3)<< testnum++<<": ";
}
