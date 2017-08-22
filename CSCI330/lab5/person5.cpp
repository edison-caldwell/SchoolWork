// person5.cpp

#include "person5.h"
#include <cctype>
#include <vector>
#include <algorithm>

//************************************ PersonClass ******************
PersonClass::PersonClass( ):name("Person"),bid("@000")
{
//  cout << "PC::Def_Const " <<endl;
}

PersonClass::PersonClass(string n, string b ):name(n), bid(b)
{
//  cout << "PC::Const " <<endl;
}

PersonClass::~PersonClass( )
{
//  cout << "PC::Destr " <<endl;
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

bool PersonClass::operator<(const PersonClass& p) const
{
  return (name<p.name);
}

bool PersonClass::operator==(const PersonClass& p) const
{
  return (name == p.name);
}
//************************************ StudentClass ******************
StudentClass::StudentClass( ):PersonClass("Student","@001"), gpa(4.0)
{
//  cout << "SC::Def_Const " <<endl;
}

StudentClass::StudentClass(string n, string b,float g ):PersonClass(n,b),gpa(g)
{
//  cout << "SC::Const " <<endl;
}

StudentClass::~StudentClass( )
{
//  cout << "SC::Destr " <<endl;
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
void PrintDiv(string msg)
{
  cout <<endl<< "********************************"<<endl;
  cout << msg<<endl<<endl;
}

int main( )
{

   int x, i;
   float gpa;
   string name, bid;
   //char which;   

          
// Declare a vector of StudentClass
   vector<PersonClass*> s_vec;
   string which;
   StudentClass* s;
   PersonClass* p;
// Fill vector
PrintDiv("Fill Student vector:");
   cout << "Which type?"
   cint >> which;
   for (i =0; i<5; i++)
   {
    
   if(which == "Student" || which == "student" || which == "s")
   {
     cout << "Enter name, bid, and gpa: ";
     cin >> name >> bid >> gpa;
     s->SetName(name); s->SetBid(bid); s->SetGPA(gpa);      

     s_vec.push_back(s);
   }
   else
   {  
     cout << "Enter name, bid, and gpa: ";
     cin >> name >> bid >> gpa;
     p->SetName(name); p->SetBid(bid); p->SetGPA(gpa);      

     s_vec.push_back(p);
   }
 
   
// Print vector using iteration
PrintDiv("Print using iteration:");
   for (vector<StudentClass>::iterator it = s_vec.begin( ); it != s_vec.end( ); it++)
   {
     cout<< "item: ";
    (*it)->Print(cout);
     cout <<endl; 
   }
//In the above code find the student with name of "Fred"

//Delete the student with the name of "Fred"

s->SetName("Fred");

if (find(s_vec.begin( ), s_vec.end( ), *s) != s_vec.end( ))
  {
    vector<PersonClass>::iterator it = (find(s_vec.begin( ), s_vec.end( ), *s));
    p = *it;
    delete p;
  }
// delete item
else
  cout << "Fred not found in the vector."<<endl;
 
for(vector<StudentClass>::iterator it = s_vec.begin( ); it != s_vec.end( ); it++)
{
  cout << "Name: " << it->Name( ) << endl;
} 

// sort and print the vector
PrintDiv("Sort and Print vector:");

   for (  )
   {
     cout << "item: ";

     cout <<endl;
   }


************************************************************          
// Declare a vector of PersonClass*

   PersonClass *p;

// Fill vector
PrintDiv("Fill PersonClass* vector:");
   for (i =0; i<5; i++)
   {
     cout << "s or p? ";
     cin >> which;
     if (toupper(which) == 'P')
     {
       cout << "Enter  name, bid: ";
       cin >> name >> bid;

     }
     else
     {         
       cout << "Enter  name, bid, gpa: ";
       cin >> name >> bid>>gpa;

     }

   }
   

// Print vector using iterator
PrintDiv("Print using Iterator:");
   
   for ()
   {
     cout << "item: ";

     cout <<endl;
   }

//In the above code find the person with name of "Fred"

//Delete the person with the name of "Fred"


//
// sort and print the vector
PrintDiv("Sort and Print vector:");

   for ( )
   {
     cout << "item: ";

     cout <<endl;
   }

// Add a message to the line about that prints whether
// the object is a student or not.

*/
  return 0;

}
