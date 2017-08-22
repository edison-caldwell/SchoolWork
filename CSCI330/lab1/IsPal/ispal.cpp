/*bool StrClass::IsPal() const
{
  bool isPal = false;
  
  if(str != NULL)
  {
    const char* end; 
    const char* head; 
    int len = strlen(str) - 1;
    
    end = (str + len);
    head = str;
    
    isPal = true;
    
    while((end > head) && (end != head) && (isPal == true))
    {
      while(isalpha(*head) == false)
        {head++;}
      while(isalpha(*end) == false)
        {end--;}
      
      if(isalpha(*head) && isalpha(*end))
      {
	//cout << *head << " " << *end << endl;
	if((toupper(*head)) != (toupper(*end)))
	{isPal = false;}
      }
      head++;
      end--;     
    }
    
    return isPal;
  }
}*/

bool StrClass::IsPal( ) const
{
  bool isPal = false;

  if(str != NULL)
  {
    int end = strlen(str) - 1;
    int head = 0;
    
    isPal = true;
    
    while((end > head) && (end != head) && (isPal == true))
    {
      while(isalpha(str[head]) == false)
        {
	  head++;
	}
      while((isalpha(str[end])) == false)
	{
	  end--;
	}
      
      if(isalpha(str[head]) && isalpha(str[end]))
      { 
        if(toupper(str[head]) != toupper(str[end]))
          isPal = false;
      }
      head++;
      end--;
     }
     return isPal;
   }
}

