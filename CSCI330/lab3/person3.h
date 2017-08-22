// person3.h
// Answers to questions a-e and post on D2L

#ifndef _PERSON
#define _PERSON

#include <iostream>
#include <string>

using namespace std;

//************************************ PersonClass ******************
class PersonClass
{
  public:
    PersonClass( );
    PersonClass(string);
    void SetName(string name);
    void SetBid(string bid);
    void Print(ostream& out) const;
    
  private:
    string name;
    string bid;
};


//************************************ StudentClass ******************
class StudentClass: public PersonClass
{
  public:
    StudentClass( );
    StudentClass(string);
    void SetGPA(float gpa);
    void Print(ostream& out) const;

  private:
    float gpa;
};


//************************************ FacultyClass ******************
class FacultyClass: public PersonClass
{
  public:
    FacultyClass( );
    void SetSalary(float salary);
    void Print(ostream& out) const;

  private:
    float salary;
};


#endif


