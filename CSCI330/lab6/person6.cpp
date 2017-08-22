// person6.cpp

#include "person6.h"


//************************************ PersonClass ******************
PersonClass* PersonClass::Clone( ) const
{
  return new PersonClass(*this);
}

PersonClass::PersonClass( ):name("Person"), bid("@0")  
{
//  cout << "PersonClass default constructor " <<endl;
}

PersonClass::PersonClass(string n, string b ):name(n), bid(b)
{
//  cout << "PersonClass constructor " <<endl;
}

PersonClass::PersonClass(const PersonClass& p ):name(p.name), bid(p.bid)
{
//  cout << "PC copy " <<endl;
}

PersonClass & PersonClass::operator=(const PersonClass& p )
{
//  cout << "PC assignment("<<Name()<<" <- "<<p.Name()<<")" <<endl;
  if (this != &p)
  {
    name = p.name;
    bid = p.bid;
  }
  return *this;
}

PersonClass::~PersonClass()
{
//  cout << "PersonClass dest"<<endl;
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
  out <<"P: " <<name << " " <<bid<<endl;
}


//************************************ StudentClass ******************
StudentClass* StudentClass::Clone( ) const
{
  return new StudentClass(*this);
}

StudentClass::StudentClass( ):PersonClass("Student","@1"), gpa(0.0)
{
//  cout << "SC default " <<endl;
}

StudentClass::StudentClass(string name, string bid, float g):
   PersonClass(name, bid), gpa(g)
{
//  cout << "SC parameter " <<endl;
}

StudentClass::StudentClass(const StudentClass& s ):PersonClass(s), gpa(s.gpa)
{
//  cout << "SC copy " <<endl;
}

StudentClass & StudentClass::operator=(const StudentClass& s )
{
//  cout << "SC assignment("<<Name()<<" <- "<<s.Name()<<")" <<endl;
  if (this != &s)
  {
   PersonClass::operator=(s);
   gpa = s.gpa;
  }

  return *this;
}


StudentClass::~StudentClass()
{
//  cout << "SC dest"<<endl;
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
//  PersonClass::Print(out);
  out<<"S: "<< Name()<<" " <<Bid()<< " " <<gpa <<endl;
}

//************************************ HandleClass ******************
Person::Person( ):p(NULL)
{
}

Person::Person(char type, const string name, 
                          const string bid, float gpa):p(NULL)
{
  switch(toupper(type))
  {
    case 'P' : p = new PersonClass(name, bid);
	break;
    case 'S' : p = new StudentClass(name, bid, gpa);
	break;
    default  : p = new StudentClass(name, bid, gpa);
	break; 
  }
}

Person::Person(PersonClass* ptr): handle(ptr)
{
  
}

Person::Person(const Person& person):p(NULL)
{
  CopyIntoMe(person);
}

Person::~Person( )
{
  delete p;
}

Person& Person::operator=(const Person& person)
{
  if(this != &person)
  {
    CopyIntoMe(person);
  }
  return *this;
}

void Person::CopyIntoMe(const Person& person)
{
  /*********** insert code ***************/

  delete p;

  p = NULL;

  p = person.p->Clone( ); //Calls the correct clone function from within the 
		      //heiarchy.
  

  /*if(typeid(PersonClass) == typeid(*person.p))
    p = new PersonClass(*person.p);
  else if (typeid(StudentClass) == typeid(*person.p))
    p = new StudentClass(*person.p);*/
}

void Person::SetName(const string newName)
{
  if (p)
    p->SetName(newName);
}

void Person::SetBid(const string newBID)
{
  if (p)
    p->SetBid(newBID);
}

void Person::SetGPA(float newGPA)
{
  /*********** insert code ***************/
  StudentClass *s;	//Declare a new pointer for whatever type you need
  s = dynamic_cast<StudentClass *>(p); //Cast p(private data) to studentclass ptr
  if (s)
    s->SetGPA(newGPA); //Can then directly call the student class functions through 									handle class
}

string Person::Name( ) const
{
  if (p)
    return p->Name();
  else
    return "";
}

string Person::Bid() const
{
  if (p)
    return p->Bid();
  else
    return "";
}

float Person::GPA() const
{
  /*********** insert code ***************/  
  StudentClass *s;
  s = dynamic_cast<StudentClass *>(p);
  if (s)
    return s->GPA();
  else
    return 0;
}

void Person::Print(ostream& out) const
{
  /*********** insert code ***************/  
  if(p)
    p->Print(out);

  return;
}

//************************************ TESTING ******************

int main( )
{
  Person p1('p',"n1","@n1");
  Person p2('s',"n2","@n2",2);

  cout << p1.GPA() <<  p2.GPA() << endl;  

  p1.Print(cout);
  p2.Print(cout);

  cout << endl << endl;
  return 0;

}





