// person6.cpp

#include "_person6.h"


//************************************ PersonClass ******************
PersonClass* PersonClass::Clone() const  //  * THIS IS NEW
{
  return new PersonClass(*this);
}


PersonClass::PersonClass( ):name("Person"), bid("@000")  
{
//  cout << "PersonClass default constructor " <<endl;
}

PersonClass::PersonClass(string n, string b ):name(n), bid(b)
{
//  cout << "PersonClass constructor " <<endl;
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

bool PersonClass::operator==(const PersonClass& p) const
{
 return bid == p.bid;
}

bool PersonClass::operator!=(const PersonClass& p) const
{
 return bid != p.bid;
}

bool PersonClass::operator<=(const PersonClass& p) const
{
 return bid <= p.bid;
}

bool PersonClass::operator>=(const PersonClass& p) const
{
 return bid >= p.bid;
}

bool PersonClass::operator<(const PersonClass& p) const
{
 return bid < p.bid;
}

bool PersonClass::operator>(const PersonClass& p) const
{
 return bid > p.bid;
}



//************************************ StudentClass ******************

StudentClass* StudentClass::Clone() const  //  * THIS IS NEW
{
  return new StudentClass(*this);
}



StudentClass::StudentClass( ):PersonClass("Student","@111"), gpa(0.0)
{
//  cout << "StudentClass default constructor " <<endl;
}

StudentClass::StudentClass(string name, string bid, float g):
   PersonClass(name, bid), gpa(g)
{
//  cout << "StudentClass constructor " <<endl;
}

StudentClass::~StudentClass()
{
//  cout << "StudentClass dest"<<endl;
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
                                          //  * THIS IS NEW
Person::Person(PersonClass * ptr):p(ptr)  // client determines
{					// how to create something
}					// in the hierarchy

// the constructor above removes the necessity of the constructor
// below with the switch statement!!
Person::Person(char kind, const string name, const string bid, float gpa):p(NULL)
{
  switch(toupper(kind))
  {
    case 'P': p = new PersonClass(name,bid); break;
    case 'S': p = new StudentClass(name,bid, gpa);break;
  }
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
  if (this != &person)
  {
    CopyIntoMe(person);
  }
  return *this;
}

void Person::CopyIntoMe(const Person& person)
{
  delete p;
  p = NULL;
  if (person.p != NULL)
  {	                        //  * THIS IS NEW
       p = person.p->Clone(); // whatever the obj, make a copy
   }			      // Since Clone( ) is virtual in the
}			      // hierarchy this does that!!

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
  StudentClass * s;
  s = dynamic_cast<StudentClass *>(p);
  
  if (s)
    s->SetGPA(newGPA);
    
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
    return 0;
}

float Person::GPA() const
{
  /*********** insert code ***************/  
  StudentClass * s;
  s = dynamic_cast<StudentClass *>(p); // s=p
  
  if (s)
    return s->GPA( );
  else
    return 0;
  
}

void Person::Print(ostream& out) const
{
  /*********** insert code ***************/  
  if (p)
    p->Print(out);
}


bool Person::operator==(const Person& person) const
{
  if ((p)&& (person.p))
    return (*p == *person.p);
  else
    return false;
}


bool Person::operator!=(const Person& person) const
{
  if ((p)&& (person.p))
    return (*p != *person.p);
  else
    return false;
}

bool Person::operator<=(const Person& person) const
{
  if ((p)&& (person.p))
    return (*p <= *person.p);
  else
    return false;
}

bool Person::operator>=(const Person& person) const
{
  if ((p)&& (person.p))
    return (*p >= *person.p);
  else
    return false;
}

bool Person::operator<(const Person& person) const
{
  if ((p)&& (person.p))
    return (*p < *person.p);
  else
    return false;
}

bool Person::operator>(const Person& person) const
{
  if ((p)&& (person.p))
    return (*p > *person.p);
  else
    return false;
}



//************************************ TESTING ******************


int main( )
{
  cout <<endl<<endl;
 {
  Person p1('p',"n1","@n1");
  Person p2('s',"n2","@n2",2);

  p1.Print(cout);
  p2.Print(cout);
  cout <<endl;  
  {
    Person p3(p1);
    Person p4(p2);
    p3.Print(cout);
    p4.Print(cout);
    cout <<endl;
    {
      Person p5;
      p5 = p1;
      p5.Print(cout);
      cout <<endl;
      
      Person p6;
      Person p7;
      p6 = new PersonClass("n3","@n3");
      p7 = new StudentClass("n4","@n4",4);
      p6.Print(cout);
      p7.Print(cout);
      cout <<endl;
    }
  }

  p1.Print(cout);
  p2.Print(cout);
 }

  cout <<endl<<endl;
  return 0;

}






