// person4.h

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
    virtual PersonClass(string name, string bid );
    virtual ~PersonClass( );

    void SetName(string name);
    void SetBid(string bid);
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
    StudentClass( );
    StudentClass(string name, string bid, float gpa);
    ~StudentClass( );    

    void SetGPA(float gpa);
    float GPA( ) const;
    void Print(ostream& out) const;
    

  private:
    float gpa;
};



#endif


