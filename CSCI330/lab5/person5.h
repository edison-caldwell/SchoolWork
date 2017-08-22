// person5.h

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
    PersonClass(string name, string bid);
    void SetName(string name);
    void SetBid(string bid);
    string Name( ) const;
    string Bid( ) const;
    bool operator<(const PersonClass& p)const;
    bool operator==(const PersonClass& p)const;
    virtual void Print(ostream& out) const;
    virtual ~PersonClass( );
  private:
    string name;
    string bid;
};


//************************************ StudentClass ******************
class StudentClass: public PersonClass
{
  public:
    StudentClass( );
    StudentClass(string name, string bid, float gpa);
    
    void SetGPA(float gpa);
    float GPA( ) const;
    virtual void Print(ostream& out) const;
    virtual ~StudentClass( );
  private:
    float gpa;
};



#endif


