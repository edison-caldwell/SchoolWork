// Name: 

// person9.cpp

#include "person9.h"


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
 return name == p.name;
}

bool PersonClass::operator!=(const PersonClass& p) const
{
 return name != p.name;
}

bool PersonClass::operator<=(const PersonClass& p) const
{
 return name <= p.name;
}

bool PersonClass::operator>=(const PersonClass& p) const
{
 return name >= p.name;
}

bool PersonClass::operator<(const PersonClass& p) const
{
 return name < p.name;
}

bool PersonClass::operator>(const PersonClass& p) const
{
 return name > p.name;
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

#include <set>
#include <queue>
#include <algorithm>


int main( )
{
  Person p;
  string name, bid;
  float gpa;
  char ch;

// Declare a set (mySet) and queue(myQ) of person
  
  set<Person> mySet;
  queue<Person> myQ;

  cout <<endl<<"Loading Data"<<endl;
//load the set and queue  
  for (int i = 0; i<5; i++)
  {
      cout << "What do you want Person or Student (P/S):"<<endl;
      cin >> ch;
      cout << "Enter data (name bid gpa)"; 
      cin >> name >> bid;
      if (toupper(ch) =='P')
        p = new PersonClass(name,bid);
      else
      {
        cin >>gpa;
        p = new StudentClass(name,bid,gpa);
      }
      cin.ignore(256,'\n');
// what Person constructor is used for p?
// answer: PersonClass
// add the Person p to the set and queue

      mySet.insert(p);
      myQ.push(p);
      
      cout<<endl;
  }
  cout <<endl<<endl;

  cout <<endl<<"Print the set"<<endl;
//Print the set, each element on a separate line 
  
  for(set<Person*>::iterator it = mySet.begin( ); it != mySet.end( ); it++)
  {
    it->Print(cout);
    cout << endl;
  }
    
  int qsize = myQ.size( );
  Person temp;
  
  for(int i = 0; i < myQ.size( ); i++)
  {
    temp = myQ.front( );
    
    temp->Print(cout);
    
    cout << endl;
    
    myQ.pop( );
    
    myQ.push(temp);
  }

  cout <<endl<<"Modify the bid of Person's in the set"<<endl;
//Modify the bid of each element in the set - if you can
  
  for(set<Person*>::iterator it = mySet.begin( ); it != mySet.end( ); it++)
    (*it)->SetBid("@999");

//Print each item's bid(only), each on a separate line
  
  for(set<Person*>::iterator it = mySet.begin( ); it != mySet.end( ); it++)
    cout << "BID: " << (*it)->Bid( ) << endl;

  cout <<endl<<"Find and Print \"Eve\" in the set"<<endl;
//Find Eve in the set
  
  if(find(mySet.begin( ), mySet.end( ), "Eve");
     cout << (*find(mySet.begin( ), mySet.end( ), "Eve"))->Name( );
    

  cout <<endl;

  cout <<endl<<"Erase \"Eve\" from the set and print the set"<<endl;
//Erase Eve from the set
  
  mySet.erase(find(mySet.begin( ), mySet.end( ), "Eve"));

//Print the set, each element on a separate line
  
  for(set<Person*>::iterator it = mySet.begin( ); it != mySet.end( ); it++)
  {
    (*it)->Print(cout);
    cout << endl;

  cout <<endl<<endl;
  cout <<"*******************************"<<endl;
  cout <<endl<<endl;

  cout <<endl<<"Print the queue"<<endl;
//Print the queue, each element on a separate line
  for(int i = 0; i < myQ.size( ); i++)
  {
    temp = myQ.front( );
    
    temp->Print(cout);
    
    cout << endl;
    
    myQ.pop( );
    
    myQ.push(temp);
  }


  cout <<endl<<"Modify the bid of Person's in the queue"<<endl;
//Modify the bid of each element in the queue
  
  int qsize2 = myQ.size( );
  
  for(int i = 0; i < qsize2; i++)
  {
    myQ.front()->SetBid("@999");
    cout << endl;
    
    Person* temp = myQ.front( );
    
    myQ.pop( );
    
    myQ.push(temp);
  }

//Print the queue, each element on a separate line
  for(int i = 0; i < myQ.size( ); i++)
  {
    temp = myQ.front( );
    
    temp->Print(cout);
    
    cout << endl;
    
    myQ.pop( );
    
    myQ.push(temp);
  }

  cout <<endl<<"Find and erase \"Eve\" in the queue"<<endl;
//Find and erase "Eve"from the queue 
  
  int qsize3 = myQ.size( );
  bool found = false;
  Person* eve = NULL;
  
  for(int i = 0; i < qsize3; i++)
  {
    eve = myQ.front( );
    
    if(eve->Name( ) == "Eve")
      found == true;
    
    myQ.pop( );
    myQ.push(eve);
  }
    
    

//Print the queue, each element on a separate line

  for(int i = 0; i < myQ.size( ); i++)
  {
    temp = myQ.front( );
    
    temp->Print(cout);
    
    cout << endl;
    
    myQ.pop( );
    
    myQ.push(temp);
  }

  cout <<endl<<endl;
  return 0;

}






