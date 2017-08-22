// person3.cpp

#include "person3.h"

//************************************ PersonClass ******************
PersonClass::PersonClass( ):name("default"), bid("@000")
{
   cout << "PC:default const\n"; 
}

PersonClass::PersonClass(string initName):name(initName), bid("@111")
{
 cout<<"PC:parameterized const\n";
}

void PersonClass::SetName(string new_name)
{
  name = new_name;
}


void PersonClass::SetBid(string new_bid)
{
  bid = new_bid;
}


void PersonClass::Print(ostream& out) const
{
  out << name << ": " <<bid;
}

//************************************ StudentClass ******************

StudentClass::StudentClass( ):gpa(4)
{
  cout <<"SC:default const\n";
}

StudentClass::StudentClass(string name ):PersonClass(name),gpa(4)
{
  cout <<"SC:parameterized const\n";
}


void StudentClass::SetGPA(float new_gpa)
{
  gpa = new_gpa;
}


void StudentClass::Print(ostream& out) const
{
  PersonClass::Print(out);
  out<<" "<<gpa;
  // out << GetName( )<<   
}

//************************************ FacultyClass ******************
FacultyClass::FacultyClass( ):salary(25000)
{
  cout << "FC:default const\n";
}


void FacultyClass::SetSalary(float new_salary)
{
  salary = new_salary;
}


void FacultyClass::Print(ostream& out) const
{
  PersonClass::Print(out);
  out<<"  "<<salary;
}



//************************************ TESTING ******************

int main( )
{
 
  cout << "Create PC\n";
  PersonClass p;

  cout << "Create PC\n";
  PersonClass p1("Emily");
  p1.Print(cout);
  cout <<endl;

  
  //cout << "Create SC\n";
  /*StudentClass s;
  
  s.SetGPA(2.4);
 
  s.Print(cout);
  
  cout << endl << endl;*/
 
  /*
  cout << "Create SC\n";
  StudentClass s1("James");
  s1.Print(cout);
  cout <<endl;

  cout << "Create FC\n";
  FacultyClass f;
  
  cout << "Printing s\n";
  s.Print(cout);
  cout <<endl;

  cout << "Printing f\n";
  f.Print(cout);
  cout <<endl;
  */
  return 0;

}





