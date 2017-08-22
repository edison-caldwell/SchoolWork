// person4.cpp

#include "person4.h"

//************************************ PersonClass ******************
PersonClass::PersonClass( ):name("Person"),bid("@000")
{
  cout << "PC::Def_Const\n";
}

PersonClass::PersonClass(string n, string b ):name(n), bid(b)
{
  cout << "PC::Const\n";
}

PersonClass::~PersonClass( )
{
  cout << "PC::DEST\n";
}

void PersonClass::SetName(string new_name)
{
  name = new_name;
}


void PersonClass::SetBid(string new_bid)
{
  bid = new_bid;
}


string PersonClass::Name( ) const
{
  return name;
}


string PersonClass::Bid( ) const
{
  return bid;
}


void PersonClass::Print(ostream& out) const
{
  out << "Person!  " <<name << ": " <<bid<<endl;
}


//************************************ StudentClass ******************

StudentClass::StudentClass( ):PersonClass("Student","@111"), gpa(4.0)
{
  cout << "SC::Def_Cons\n";
}

StudentClass::~StudentClass( )
{
  cout << "SC::DEST\n";
}

StudentClass::StudentClass(string n, string b,float g ):PersonClass(n,b), gpa(g)
{
  cout << "SC::Const\n";
}


void StudentClass::SetGPA(float new_gpa)
{
  gpa = new_gpa;
}


float StudentClass::GPA( ) const
{
  return gpa;
}


void StudentClass::Print(ostream& out) const
{
  out << "Student! " <<Name( ) << ": " <<Bid( )<<"  " <<gpa <<endl;
}


//************************************ TESTING ******************

int main( )
{
  PersonClass* p_ptr;
  PersonClass* s_ptr;

  p_ptr = new PersonClass("Buddy", "@888");
  s_ptr = new StudentClass("Jill", "@999", 1.8);

  cout << endl << endl;

  p_ptr->Print(cout);
  s_ptr->Print(cout);

  cout << endl << endl;
  delete p_ptr;
  cout << endl << endl;
  delete s_ptr;

return 0;
}





