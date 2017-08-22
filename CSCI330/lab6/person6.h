// person6.h

#ifndef _PERSON
#define _PERSON

#include <iostream>
#include <string>
#include <cctype>
#include <typeinfo>


using namespace std;

//************************************ PersonClass ******************
class PersonClass
{
  public:
    virtual PersonClass* Clone( ) const; //make pure virtual in CreatureClass
    PersonClass( );
    PersonClass(const string name, const string bid );
    PersonClass(const PersonClass & p);
    PersonClass & operator=(const PersonClass & p);
    virtual ~PersonClass( );

    void SetName(const string name);
    void SetBid(const string bid);
    string Name( ) const;
    string Bid( ) const;
    virtual void Print(ostream& out) const;
    
  private:
    string name;
    string bid;
};


//************************************ StudentClass ******************
class StudentClass: public PersonClass
{
  public:
    virtual StudentClass* Clone( ) const; //just virtual in derived class !pure
    StudentClass( );
    StudentClass(const string name, const string bid, float gpa=0.0);
    StudentClass(const StudentClass & s);
    StudentClass & operator=(const StudentClass & p);

    ~StudentClass( );

    void SetGPA(float gpa);
    float GPA( ) const;
    void Print(ostream& out) const;

  private:
    float gpa;
};

//************************************ HandleClass ******************
class Person
{
  public:
    Person( );
    Person(char type, const string name, const string bid, float gpa=0.0); // type='p' or 's'
    Person(PersonClass* ptr);
    Person(const Person& person);
    Person& operator=(const Person& person);
    void CopyIntoMe(const Person& person);
    ~Person( );
   
    void SetName(const string name);
    void SetBid(const string bid);
    void SetGPA(float gpa);
    string Name( ) const;
    string Bid( ) const;
    float GPA( ) const;
    void Print(ostream& out) const;
  
  private:
    PersonClass* p;

//*****NOTES*****
// 1) no virtual functions in the handle class
// 2) make sure all functions have a return.
// 3) check to make sure the pointer is not null. 
// 4) 
};
  

#endif


