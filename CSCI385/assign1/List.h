//LIST CLASS IS A LINKED LIST OF STRUCTS(PLANET)
//THE LIST IS LINKED AND CAN BE TRAVERSED IN FOUR MANNERS:
//BY DISTANCE, REVERSE DISTANCE, MASS, AND DIAMETER.
#ifndef LIST_
#define LIST_

#include <string.h>
#include <iomanip>
#include "Milkyway.h"
#include <iostream>

using namespace std;
using namespace Milkyway;

struct Planet;

class List
{
public: 
    /*Constructor, destructor, overloaded copy, ect.*/
    List();
    //Constructor
    //Pre:
    //Post: List is instantiated with 9 planets. 
    
    ~List();
    //Destuctor
    //Pre:
    //Post: All memory deallocated

    List(const List& other);
    //Copy Constructor
    //Pre:
    //Post: this holds the same internal values as other

    List& operator=(const List& other);
    //Overloaded Assignment
    //Pre:
    //Post: this holds the same internal values as other;

    //friend ostream& operator<<(ostream &output, const List& l);

    void BigBang();
    //Creates default planets and links them by distance
    //Pre:
    //Post: 9 planets created and linked by distance.
    
    void LinkMass();
    //Links planets by mass
    //Pre:BigBang() has been executed
    //Post: Planets linked by mass

    void LinkDiameter();
    //Links the planets by diameter
    //Pre: BigBang() has been executed
    //Post: Planets are linked by diameter

    void ReverseLink();   
    //Links the planets by reverse distance
    //Pre: BigBang() has been executed
    //Post: Planets are linked my reverse distance;

    /*Transormers (robots in disguise)******/
    void Insert(planetPtr newPlanet);
    //Pre: Item is not already in the list.
    //Post: Item added to list with all private data.
    
    void Remove(string planetName);
    //Pre: Item is in list.
    //Post: Item is removed from list.
    
    /*Observers*****************************/

    string Name() const;
    //Returns currentPtr->Name 
    //Pre:
    //Post: Name is returned

    float Distance() const;
    //Returns currentPtr->Distance
    //Pre: 
    //Post: Distance returned.
    
    float Mass() const;
    //Returns currentPtr->Mass
    //Pre: 
    //Post: Mass returned;
    
    float Diameter() const;
    //Returns currentPtr->Diameter
    //Pre: 
    //Post: Diameter is returned.
    
    planetPtr Find(string);
    //Finds a planet based on planet names
    //Pre: List object has been created
    //Post: If found, planet is returned. Else NULL is returned.

    /*Pointer manipulators*******************/
    void GetNext(linkType type);
    //Sets currentPtr on a path or increments currentPtr on that path
    //Pre: type is valid and either currentPtr is NULL or on type's correlating path.
    //Post: The correct pointer is incremented.
    
    void GetPrevious();
    //Sets currentPtr equal to its reverseDistancePtr
    //Pre: 
    //Post: The correct pointer is decremented. 
    
    void Reset();
    //Sets currentPtr to NULL
    //Pre: 
    //Post: currentPtr is set to NULL

    void PrintReverse();
    //Prints planets by reverse distance
    //Pre:
    //Post: Planets' name and distance printed in order of furthest to closest to the sun.

    void PrintForward(linkType type);
    //Prints a planets path given by type
    //Pre: type is valid
    //Post: Planets' name and correlating value is printed
    
private:

    planetPtr headMass;
    //Points to the first node on the Mass path.
    
    planetPtr headDistance;
    //Points to the first node on the Distance path.
    
    planetPtr headDiameter;
    //Points to the first node on the Diameter path.

    planetPtr distanceTail;
    //Points to the last node on the Distance path.
    
    planetPtr currentPtr;
    //Points to the current node in the list on any given one path. 
    
    int planetCount;
    //Number of planets in the list.
};

#endif
    
    
