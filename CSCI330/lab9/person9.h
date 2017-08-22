// person7.h

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
    PersonClass(const string name, const string bid );
    virtual ~PersonClass( );
    void SetName(const string name);
    void SetBid(const string bid);
    string Name( ) const;
    string Bid( ) const;
    virtual void Print(ostream& out) const;
    

    bool operator==(const PersonClass& p) const;
    bool operator!=(const PersonClass& p) const;
    bool operator<=(const PersonClass& p) const;
    bool operator>=(const PersonClass& p) const;
    bool operator<(const PersonClass& p) const;
    bool operator>(const PersonClass& p) const;

    friend class Person; // allows the class to call private functions (Clone).    
  private:
    string name;
    string bid;
    virtual PersonClass* Clone() const;

};


//************************************ StudentClass ******************
class StudentClass: public PersonClass
{
  public:
    StudentClass( );
    StudentClass(const string name, const string bid, float gpa=0.0);
    ~StudentClass( );
    void SetGPA(float gpa);
    float GPA( ) const;
    void Print(ostream& out) const;

  private:
    float gpa;
    StudentClass* Clone( ) const;

};

//************************************ HandleClass ******************
class Person
{
  public:
    Person( );
    Person(PersonClass * ptr);
    Person(char type, const string name, const string bid, float gpa=0.0); // type='p' or 's'
    Person(const Person& person);
    ~Person( );
    Person& operator=(const Person& person);
   
    void SetName(const string name);
    void SetBid(const string bid);
    void SetGPA(float gpa);
    string Name( ) const;
    string Bid( ) const;
    float GPA( ) const;
    void Print(ostream& out) const;


  bool operator==(const Person& p) const;
  bool operator!=(const Person& p) const;
  bool operator<=(const Person& p) const;
  bool operator>=(const Person& p) const;
  bool operator<(const Person& p) const;
  bool operator>(const Person& p) const;
  
  private:
    PersonClass* p;
    void CopyIntoMe(const Person& person);

};
  

#endif


