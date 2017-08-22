// str2.cpp
// IsPal is implemented

#include "str2.h"


StrClass::StrClass( ): str(NULL)
{
  // members are set in the ctor
}

StrClass::~StrClass( )
{
	delete [] str;
}
	

StrClass::StrClass (const StrClass &s): str(NULL)
{
//  str = NULL; //done in ctor
  str = CopyStr(str, s.str);

}

// ************************************************CONVERT CONST
/*
StrClass::StrClass(const char * s): str(NULL)
{
//   str = NULL;  //done in ctor
   str = CopyStr(str,s);

}
*/

StrClass::StrClass(const string & s ): str(NULL)
{
   str = CopyStr(str,s.c_str());
}

StrClass::StrClass(const char c): str(NULL)
{
   if (c != '\0')
   {
     str = new char[2];
     str[0] = c;
     str[1] = '\0';
   }

} 


// ************************************************OPERATORS
const StrClass & StrClass::operator=(const StrClass &s )
{
	if (this != &s)
	{
	  
	  str = CopyStr(str, s.str);
	  
	}
	return *this;

}
                                
// ***********************************************TRANSFORMERS
void StrClass::SetStr(const char *s)
{
  str = CopyStr(str,s);

}
	

// ************************************************OBSERVERS		
string StrClass::Str( ) const
{
	if (str != NULL) // if (str)  
		return string(str); // do I need to explicitly convert?
	else
		return "";
}


void StrClass::DisplayStr( ) const
{
	  cout << Str();
	  
	  // below for testing only
	  if (str == NULL)
	   cout <<"NULL";
}

bool StrClass::IsPal( ) const
{
        //return CheckArrayPal(str);
        return CheckPtrPal(str);
}


char * StrClass::CopyStr(char * to_str, const char *from_str) const
{
    int len;
    if (to_str !=from_str) // make sure not same string!
    {
      delete[] to_str;
      to_str = NULL;
      if ((from_str != NULL) && (from_str[0] != '\0'))
      {
        len = strlen(from_str);
        to_str = new char[len+1];
        strcpy(to_str, from_str);
      }
      return to_str;
    }
}


bool StrClass::CheckArrayPal(const char * str) const
{
        bool pal = true;
        if (str == NULL) return false;

// Using array notation to move through strings
// Compares only alphanumeric
  int b, e;
  for (b = 0, e=strlen(str)-1; b<e && pal; b++,e--)
  {
        while (b<e && !isalpha(str[b])) b++;
//         cout << str[b]<<"=";
        while (e>b && !isalpha(str[e])) e--;
//         cout << str[e]<<"~";
        if ((b<e) && (toupper(str[b]) != toupper(str[e])))
           pal = false;
  }

  return pal;
}


bool StrClass::CheckPtrPal(const char * str) const
{
        bool pal = true;
        if (str == NULL) return false;
// Using pointers to move through strings
// compares only alphanumeric
        int len = strlen(str);
        const char * b=str;
        const char * e=str+len-1;
        while ((e > b) && pal)
        {
           while (b<e && !isalpha(*b)) b++;
           while (e>b && !isalpha(*e)) e--;
           if ((e>b) &&(toupper(*e) != toupper(*b)))
                        pal = false;
           e--;
           b++;
        }

  return pal;
}

//***************Testing Area 
//
// Naming convention for testing
// cstr1, cstr2 etc - used for objects of type StrClass
// s1, s2, s3 etc - used for parameter variables of type
// 			string or cstring
// c1, c2 etc - used for parameter variables of type char
/*
void PrintTest(ostream & out, string test="");
void TestConstructors( );
void TestGetters( );
void TestSetters( );
void TestOperators( );
void TestIsPal( );

int main( )
{
  TestConstructors( );
  TestGetters( );
  TestSetters( );
  TestOperators( );
  TestIsPal( );
  cout << endl<<endl;
 return 0;
}

void TestConstructors( )
{
        cout <<endl<< "****************************"<<endl;
	cout << "Test Constructors"<<endl<<endl;

	PrintTest(cout,"C");
	StrClass cstr1;// default
	cstr1.DisplayStr();
	cout <<endl;

	PrintTest(cout);
	StrClass cstr2(NULL); //convert const for NULL cstring
	cstr2.DisplayStr( );
	cout <<endl;

	PrintTest(cout);
	StrClass cstr3("Stanley"); //convert const for cstring
	cstr3.DisplayStr( );
	cout <<endl;
	
	PrintTest(cout);
	string s4 = "";
	StrClass cstr4(s4); //convert const for empty string
	cstr4.DisplayStr( );
	cout <<endl;

	PrintTest(cout);
	string s5 = "Stanley";
	StrClass cstr5(s5); //convert const for string
	cstr5.DisplayStr( );
	cout <<endl;

	PrintTest(cout);
	char c6 = '\0';
	StrClass cstr6(c6); //convert const for NULL char
	cstr6.DisplayStr( );
	cout <<endl;

	PrintTest(cout);
	char c7 = 'A';
	StrClass cstr7(c7); //convert const for char
	cstr7.DisplayStr( );
	cout <<endl;

	PrintTest(cout);
	StrClass cstr8(cstr1); //copy const from empty StrClass
	cstr8.DisplayStr( );
	cout <<endl;

	PrintTest(cout);
	StrClass cstr9(cstr3); //copy const non empty StrClass
	cstr9.DisplayStr( );
	cout <<endl;
}

void TestGetters( )
{
        cout <<endl<< "****************************"<<endl;
	cout << "Test Getters"<<endl<<endl;

	PrintTest(cout,"G");
	StrClass cstr1;
	cout << cstr1.Str( )<<endl;

	PrintTest(cout);
	StrClass cstr2("Stanley");
	cout << cstr2.Str( )<<endl;
  
}

void TestSetters( )
{
        cout <<endl<< "****************************"<<endl;
	cout << "Test Setters"<<endl<<endl;

	PrintTest(cout,"S");
	char * s1 = NULL;
	StrClass cstr1;
	cstr1.SetStr(s1);
	cstr1.DisplayStr( );
	cout <<endl;
	
	PrintTest(cout);
        char s2[] = "Stanley";
	StrClass cstr2;
	cstr2.SetStr(s2);
	cstr2.DisplayStr( );
	cout <<endl;

	PrintTest(cout);
	char * s3 = NULL;
	StrClass cstr3("Stanley");
	cstr3.SetStr(s3);
	cstr3.DisplayStr( );
	cout <<endl;

	PrintTest(cout);
        char s4[] = "Fred";
	StrClass cstr4("Stanley");
	cstr4.SetStr(s4);
	cstr4.DisplayStr( );
	cout <<endl;

}

void TestOperators( )
{
        cout << endl<<"****************************"<<endl;
	cout << "Test Operators"<<endl<<endl;
	
	PrintTest(cout,"O");
	StrClass cstr1, s_cstr1;
	cstr1 = s_cstr1;
	cstr1.DisplayStr( );
	cout <<endl;
	
	PrintTest(cout);
	StrClass cstr2, s_cstr2("Stanley");
	cstr2 = s_cstr2;
	cstr2.DisplayStr( );
	cout <<endl;

	PrintTest(cout);
	StrClass cstr3("Stanley"), s_cstr3;
	cstr3 = s_cstr3;
	cstr3.DisplayStr( );
	cout <<endl;

	PrintTest(cout);
	StrClass cstr4("Stanley"), s_cstr4("Fred");
	cstr4 = s_cstr4;
	cstr4.DisplayStr( );
	cout <<endl;

}

void TestIsPal( )
{
        cout << endl<<"****************************"<<endl;
	cout << "Test IsPal"<<endl<<endl;
	
	PrintTest(cout,"P");
	StrClass cstr;
	cout << cstr.IsPal( ) <<endl;
	
	
	PrintTest(cout);
	cstr.SetStr("RADAK");
	cout << cstr.IsPal( ) <<endl;

	PrintTest(cout);
	cstr.SetStr("RADER");
	cout << cstr.IsPal( ) <<endl;
	

	PrintTest(cout);
	cstr.SetStr("RADAR");
	cout << cstr.IsPal( ) <<endl;

	PrintTest(cout);
	cstr.SetStr("RAdaR");
	cout << cstr.IsPal( ) <<endl;

	PrintTest(cout);
	cstr.SetStr("Ra d123a&r");
	cout << cstr.IsPal( ) <<endl;

	PrintTest(cout);
	cstr.SetStr("12R ad3& ar45%");
	cout << cstr.IsPal( ) <<endl;

	PrintTest(cout);
	cstr.SetStr("Madam, I'm Adam");
	cout << cstr.IsPal( ) <<endl;
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
*/

