//prototypes
int OutputMod( ) // for _str1_v1.h
void PrintIfPal(bool temp, StrClass str)


int StrClass::OutputMod( )
//Output Modifier for PrintIsPal. Returns the length of the test string or 3 for NULL
{
  int len;
  if(str == NULL)
    len = 3;
  else len = strlen(str) - 1;

  return len;
}

bool StrClass::IsPal() const
{
  bool isPal = false;
  
  if(str != NULL) // check for null 
  {
    const char* end; 
    const char* head; 
    int len = strlen(str) - 1;
    
    end = (str + len); //pointer to last char in array
    head = str; //pointer to first char in array
    
    isPal = true;
    
    while((end > head) && (end != head) && (isPal == true))
    {
      while(isalpha(*head) == false) //whitespace and non alpha check for head pointer
        {head++;}
      while(isalpha(*end) == false) //whitespace and non alpha check for end pointer
        {end--;}
      
      if(isalpha(*head) && isalpha(*end))
      {
	if((toupper(*head)) != (toupper(*end))) // see if the chars are equal 
	{isPal = false;}
      }
      head++; //increment head
      end--; //decrement end
    }
    
    return isPal;
  }
}

/*bool StrClass::IsPal( ) const
{
  bool isPal = false;

  if(str != NULL)// check for null 
  {
    int end = strlen(str) - 1; //index for last element
    int head = 0; //index for first element
    
    isPal = true;
    
    while(end > head && end != head && isPal == true)
    {
      while(isalpha(str[head])) //check for whitespace and non alpha char
        {
	  head++;
	}
      while((isalpha(str[end])) == false) //check for whitespace and non aplha char
	{
	  end--;
	}
      
      if(isalpha(str[head]) && isalpha(str[end]))
      {  
        if(toupper(str[head]) != toupper(str[end])) //compare array elements to see if equal
          {isPal = false;}
      }
      head++; //increment head index
      end--; //decrement end index
     }
     return isPal;
   }
}*/


void TestIsPal( )
{
  
    cout << endl<<"****************************"<<endl;
	cout << "Test IsPal"<<endl<<endl;
	
	PrintTest(cout,"P");
	StrClass cstr1; //test for null
	cstr1.DisplayStr( );
	PrintIfPal(cstr1.IsPal( ), cstr1);
	
	PrintTest(cout);
	StrClass cstr2("tacocat"); //testing a palindrome
	cstr2.DisplayStr( );
	PrintIfPal(cstr2.IsPal( ), cstr2);
	
	ostream& flush();
	PrintTest(cout);
	StrClass cstr3("Stanley"); //testing none palindrome string
	cstr3.DisplayStr( );
	PrintIfPal(cstr3.IsPal( ), cstr3);
	
	PrintTest(cout);
	string s4 = "";
	StrClass cstr4(s4); //testing an empty string
	cstr4.DisplayStr( );
	PrintIfPal(cstr4.IsPal( ), cstr4);

	PrintTest(cout);
	string s5 = "taco cat";
	StrClass cstr5(s5); //testing string with whitespace
	cstr5.DisplayStr( );
	PrintIfPal(cstr5.IsPal( ), cstr5);

	PrintTest(cout);
	StrClass cstr6("TacoCat"); //testing for case sensetivity
	cstr6.DisplayStr( );
	PrintIfPal(cstr6.IsPal( ), cstr6);

	PrintTest(cout);
	char c7 = 'A';
	StrClass cstr7(c7); //testing single char
	cstr7.DisplayStr( );
	PrintIfPal(cstr7.IsPal( ), cstr7);

	PrintTest(cout);
	StrClass cstr8("taco!cat"); //testing for nonalpha chars
	cstr8.DisplayStr( );
	PrintIfPal(cstr8.IsPal( ), cstr8);

	PrintTest(cout);
	StrClass cstr9("Taco!  Cat"); //testing for case sensetivity, whitespace, and non alpha char
	cstr9.DisplayStr( );
	PrintIfPal(cstr9.IsPal( ), cstr9);

}

 void PrintIfPal(bool temp, StrClass str) 
 //function for redundant output and formatting
 //requires class method that returns the length
{
  if(temp == true)
  {
    cout << left << setw(10 - str.Length( )) << "" << " :Palindrome" << endl;
  }
  else if(temp == false)
  {
    cout << left << setw(10 - str.Length( )) << "" << " :Not Palindrome" << endl;
  }
}

