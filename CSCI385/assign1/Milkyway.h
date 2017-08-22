#ifndef _MILKYWAY
#define _MILKYWAY

#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

namespace Milkyway
{
    struct Planet;
    
    typedef Planet* planetPtr;
    
    struct Planet
    {
        string Name;
        //Planet name.
        
        float DistanceFromSun;
        //Distance planet is from the sun.
        
        float Mass;
        //Mass of the planet.
        
        float Diameter;
        //Diameter of the planet.
        
        planetPtr distancePtr;
        //Points to the next planet on the "Distance from Sun" path. 
        
        planetPtr massPtr;
        //Points to the next planet on the "Mass" path.
        
        planetPtr diameterPtr;
        //Points to the next planet on the "Diameter" path.
        
        planetPtr reverseDistancePtr;
        //Points to the previous planet on the "Distance from Sun" path.
        
        Planet();
        
        //Planet(const Planet& other);
        
        //Planet& operator=(const Planet& other);
        
        friend ostream& operator<<(ostream &output, const Planet& p);
                
    };
    

    enum linkType{MASS, DISTANCE, DIAMETER};
    
    enum planets{MERCURY, VENUS, EARTH, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO};
    
    void Print(planetPtr p, linkType type);

    const int distancePath [9] = {MERCURY, VENUS, EARTH, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO};
    
    const int massPath [9] = {PLUTO, MERCURY, MARS, VENUS, EARTH, URANUS, NEPTUNE, SATURN, JUPITER};
    
    const int diameterPath [9] = {PLUTO, MERCURY, MARS, VENUS, EARTH, NEPTUNE, URANUS, SATURN, JUPITER};
    
    const string planetNames [9] = 
    {"MERCURY", 
    "VENUS", 
    "EARTH", 
    "MARS", 
    "JUPITER", 
    "SATURN",
    "URANUS",
    "NEPTUNE",
    "PLUTO"};
    
    static vector<string> nameList(planetNames, planetNames + sizeof(planetNames) / sizeof(planetNames) );
    
    planetPtr Mercury();
    
    planetPtr Venus();
    
    planetPtr Earth();
    
    planetPtr Mars();
    
    planetPtr Jupiter();
    
    planetPtr Saturn();
    
    planetPtr Uranus();
    
    planetPtr Neptune();
    
    planetPtr Pluto(); //not a planet.
    
    planetPtr NewPlanet();
    
    void AddPlanetName(string temp);

    void centerstring(char* s);

};

#endif
