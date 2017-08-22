#include "Milkyway.h"

namespace Milkyway
{
    planetPtr Mercury()
    {
        planetPtr mercury = new Planet;
        
        mercury->Name = "MERCURY";
        mercury->DistanceFromSun = 36.0;
        mercury->Mass = .364;
        mercury->Diameter = 3032;
        mercury->distancePtr = NULL;
        mercury->massPtr = NULL;
        mercury->diameterPtr = NULL;
        mercury->reverseDistancePtr = NULL;
        
        return mercury;
    }
    
    planetPtr Venus()
    {
        planetPtr venus = new Planet;
    
        venus->Name = "VENUS";
        venus->DistanceFromSun = 67.2;
        venus->Mass = 5.37;
        venus->Diameter = 7521;
        venus->distancePtr = NULL;
        venus->massPtr = NULL;
        venus->diameterPtr = NULL;
        venus->reverseDistancePtr = NULL;
        
        return venus;
    }
    
    planetPtr Earth()
    {
        planetPtr earth = new Planet;
        
        earth->Name = "EARTH";
        earth->DistanceFromSun = 93.0;
        earth->Mass = 6.58;
        earth->Diameter = 7926;
        earth->distancePtr = NULL;
        earth->massPtr = NULL;
        earth->diameterPtr = NULL;
        earth->reverseDistancePtr = NULL;
        
        return earth;
    }
    
    planetPtr Mars()
    {
        planetPtr mars = new Planet;
        
        mars->Name = "MARS";
        mars->DistanceFromSun = 141.6;
        mars->Mass = 0.708;
        mars->Diameter = 4221;
        mars->distancePtr = NULL;
        mars->massPtr = NULL;
        mars->diameterPtr = NULL;
        mars->reverseDistancePtr = NULL;
        
        return mars;
    }
    
    planetPtr Jupiter()
    {
        planetPtr jupiter = new Planet;
        
        jupiter->Name = "JUPITER";
        jupiter->DistanceFromSun = 483.8;
        jupiter->Mass = 2093;
        jupiter->Diameter = 88846;
        jupiter->distancePtr = NULL;
        jupiter->massPtr = NULL;
        jupiter->diameterPtr = NULL;
        jupiter->reverseDistancePtr = NULL;
        
        return jupiter;
    }
    
    planetPtr Saturn()
    {
        planetPtr saturn = new Planet;
        
        saturn->Name = "SATURN";
        saturn->DistanceFromSun = 890.8;
        saturn->Mass = 627;
        saturn->Diameter = 74897;
        saturn->distancePtr = NULL;
        saturn->massPtr = NULL;
        saturn->diameterPtr = NULL;
        saturn->reverseDistancePtr = NULL;
        
        return saturn;
    }
    
    planetPtr Uranus()
    {
        planetPtr uranus = new Planet;
        
        uranus->Name = "URANUS";
        uranus->DistanceFromSun = 1784.8;
        uranus->Mass = 95.7;
        uranus->Diameter = 31763;
        uranus->distancePtr = NULL;
        uranus->massPtr = NULL;
        uranus->diameterPtr = NULL;
        uranus->reverseDistancePtr = NULL;
        
        return uranus;
    }
    
    planetPtr Neptune()
    {
        planetPtr neptune = new Planet;
        
        neptune->Name = "NEPTUNE";
        neptune->DistanceFromSun = 2793.1;
        neptune->Mass = 113;
        neptune->Diameter = 30775;
        neptune->distancePtr = NULL;
        neptune->massPtr = NULL;
        neptune->diameterPtr = NULL;
        neptune->reverseDistancePtr = NULL;
        
        return neptune;
    }
    
    planetPtr Pluto()
    {
        planetPtr pluto = new Planet;
        
        pluto->Name = "PLUTO";
        pluto->DistanceFromSun = 3670.0;
        pluto->Mass = .0161;
        pluto->Diameter = 1464;
        pluto->distancePtr = NULL;
        pluto->massPtr = NULL;
        pluto->diameterPtr = NULL;
        pluto->reverseDistancePtr = NULL;
        
        return pluto;
    }
    
    void AddPlanetName(string temp)
    {
        nameList.push_back(temp);
        
        sort(nameList.begin(), nameList.end());
        
        return;
    }
    
//     Planet& Planet::operator=(const Planet& other)
//     {
//         Name = other.Name;
//         DistanceFromSun = other.DistanceFromSun;
//         Mass = other.Mass;
//         Diameter = other.Diameter;
//         distancePtr = NULL;
//         massPtr = NULL;
//         diameterPtr = NULL;
//         reverseDistancePtr = NULL;
//     }
    
    Planet::Planet()
    {
        distancePtr = NULL;
        diameterPtr = NULL;
        massPtr = NULL;
    }
    
//     Planet::Planet(const Planet& other)
//     {
//         *this = other;
//     }
    
    planetPtr NewPlanet()
    {
        planetPtr tempPlanet = new Planet;
        string tempString;
        float tempFloat = 0;
        
        cout << endl << "Name?: ";
        cin >> tempString;
        tempPlanet->Name = tempString;
        
        cout << endl <<  "Distance from the Sun?: ";
        cin >> tempFloat;
        tempPlanet->DistanceFromSun = tempFloat;
        
        cout << endl << "Mass?: ";
        cin >> tempFloat;
        tempPlanet->Mass = tempFloat;
        
        cout << endl << "Diameter?: ";
        cin >> tempFloat;
        tempPlanet->Diameter = tempFloat;
        cout << endl;
        
        return tempPlanet;
        
    }
    
//     ostream& operator<<(ostream &output, const Planet& p)
//     {
//         output << "Name: " <<  p.Name << endl;
//         output << "Distance: " << p.DistanceFromSun << endl;
//         output << "Mass: " << p.Mass << endl;
//         output << <p.Diameter << endl;
//     }
    
    void Print(planetPtr p, linkType link)
    {
        cout << "Name: " << p->Name << endl; 

        if(link == DISTANCE)
            cout << "Distance: " << p->DistanceFromSun << endl;
        else if(link == MASS) 
            cout << "Mass: " << p->Mass << endl; 
        else if(link == DIAMETER)
            cout << "Diameter: " << p->Diameter << endl;

        cout << endl;

        return;
    }

    void centerstring(char* s)
    {
        int l=strlen(s);
        int pos=(int)((80-l)/2);
        
        for(int i=0;i<pos;i++)
            cout<<" ";

        cout<<s;
    }
}


