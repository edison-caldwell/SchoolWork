#include "List.h"

List::List()
{    
    BigBang();
    
    LinkMass();
    
    LinkDiameter();

    ReverseLink();
        
    planetCount = 9; 
}


List::~List()
{
    Reset();

    currentPtr = distanceTail;

    while(currentPtr != headDistance)
    {
        if(currentPtr->reverseDistancePtr)
            currentPtr = currentPtr->reverseDistancePtr;

        currentPtr->massPtr = NULL;
        currentPtr->distancePtr = NULL;
        currentPtr->diameterPtr = NULL;

        distanceTail->distancePtr = NULL;
        distanceTail->massPtr = NULL;
        distanceTail->diameterPtr = NULL;
        distanceTail->reverseDistancePtr = NULL;
        
        delete distanceTail;
        distanceTail = NULL;
        distanceTail = currentPtr;
    }

    delete headDistance;
    
    currentPtr = NULL;
    headMass = NULL;
    headDistance = NULL;
    headDiameter = NULL;
    distanceTail = NULL;
    
    return;
}


List::List(const List& other)
{
    if(!other.headDistance)
    {
        headDistance = NULL;
        headDiameter = NULL;
        headMass = NULL;
        
        return;
    }
    else
    {
        planetCount = other.planetCount;
        
        planetPtr toCopy = other.headDistance;
        planetPtr prevNode = NULL;
        planetPtr newListPtr = NULL;
        
        headDistance = new Milkyway::Planet;
        
        headDistance->Name = toCopy->Name;
        headDistance->DistanceFromSun = toCopy->DistanceFromSun;
        headDistance->Mass = toCopy->Mass;
        headDistance->Diameter = toCopy->Diameter;
        
        prevNode = headDistance;
        newListPtr = headDistance;
        toCopy = toCopy->distancePtr;
        
        while(toCopy!= NULL)
        {
            newListPtr->distancePtr = new Milkyway::Planet;
            newListPtr = newListPtr->distancePtr;
            newListPtr->Name = toCopy->Name;
            newListPtr->DistanceFromSun = toCopy->DistanceFromSun;
            newListPtr->Mass = toCopy->Mass;
            newListPtr->Diameter = toCopy->Diameter;
            
            newListPtr->reverseDistancePtr = prevNode;
            prevNode = newListPtr;  
            toCopy = toCopy->distancePtr; 
        }
        newListPtr->distancePtr = NULL;
        distanceTail = newListPtr;
        
        toCopy = other.headMass;
        
        planetPtr temp;
        temp = Find(toCopy->Name);
        headMass = temp;
        currentPtr = headMass;
        
        while(toCopy != NULL)
        {
            temp = Find(toCopy->Name);
            currentPtr->massPtr = temp;
            toCopy = toCopy->massPtr;
            GetNext(MASS);
        }
        
        Reset();
        
        
        toCopy = other.headDiameter;
        
        temp = Find(toCopy->Name);
        headDiameter = temp;
        currentPtr = headDiameter;
        
        while(toCopy != NULL)
        {
            temp = Find(toCopy->Name);
            currentPtr->diameterPtr = temp;
            toCopy = toCopy->diameterPtr;
            GetNext(DIAMETER);
        }
    }
}


List& List::operator=(const List& other)
{
    if(!other.headDistance)
    {
        headDistance = NULL;
        headDiameter = NULL;
        headMass = NULL;
    }
    else
    {
        planetCount = other.planetCount;
        
        planetPtr toCopy = other.headDistance;
        planetPtr prevNode = NULL;
        planetPtr newListPtr = NULL;
        
        headDistance = new Milkyway::Planet;
        
        headDistance->Name = toCopy->Name;
        headDistance->DistanceFromSun = toCopy->DistanceFromSun;
        headDistance->Mass = toCopy->Mass;
        headDistance->Diameter = toCopy->Diameter;
        
        prevNode = headDistance;
        newListPtr = headDistance;
        toCopy = toCopy->distancePtr;
        
        while(toCopy!= NULL)
        {
            newListPtr->distancePtr = new Milkyway::Planet;
            newListPtr = newListPtr->distancePtr;
            newListPtr->Name = toCopy->Name;
            newListPtr->DistanceFromSun = toCopy->DistanceFromSun;
            newListPtr->Mass = toCopy->Mass;
            newListPtr->Diameter = toCopy->Diameter;
            newListPtr->reverseDistancePtr = prevNode;
            prevNode = newListPtr;  
            toCopy = toCopy->distancePtr;
        }
        newListPtr->distancePtr = NULL;
        distanceTail = newListPtr;
        
        toCopy = other.headMass;
        
        planetPtr temp;
        temp = Find(toCopy->Name);
        headMass = temp;
        currentPtr = headMass;
        
        while(toCopy != NULL)
        {
            temp = Find(toCopy->Name);
            currentPtr->massPtr = temp;
            toCopy = toCopy->massPtr;
            GetNext(MASS);
        }
        
        Reset();
        
        
        toCopy = other.headDiameter;
        
        temp = Find(toCopy->Name);
        headDiameter = temp;
        currentPtr = headDiameter;
        
        while(toCopy != NULL)
        {
            temp = Find(toCopy->Name);
            currentPtr->diameterPtr = temp;
            toCopy = toCopy->diameterPtr;
            GetNext(DIAMETER);
        }
    }
}


void List::Insert(planetPtr newPlanet)
{
    Reset();
    currentPtr = headDistance;

    if(newPlanet->DistanceFromSun < headDistance->DistanceFromSun)
    {
        newPlanet->distancePtr = headDistance;
        headDistance->reverseDistancePtr = newPlanet;
        headDistance = newPlanet;
    }
    else
    {
        while(currentPtr->distancePtr != NULL && 
            currentPtr->distancePtr->DistanceFromSun < newPlanet->DistanceFromSun)
        {
            GetNext(DISTANCE);
        }

        if(currentPtr->distancePtr == NULL)
        {
            currentPtr->distancePtr = newPlanet;
        }
        else
        {
            newPlanet->distancePtr = currentPtr->distancePtr;
            currentPtr->distancePtr = newPlanet;
            newPlanet->reverseDistancePtr = currentPtr;
        }
    }
    
    Reset();
    currentPtr = headMass;
    
    if(newPlanet->Mass < headMass->Mass)
    {
        newPlanet->massPtr = headMass;
        headMass = newPlanet;
    }
    else
    {
       while(currentPtr->massPtr != NULL && 
        currentPtr->massPtr->Mass < newPlanet->Mass)
        {
            GetNext(MASS);
        }

        if(currentPtr->massPtr == NULL)
            currentPtr->massPtr = newPlanet;
        else
        {
            newPlanet->massPtr = currentPtr->massPtr;
            currentPtr->massPtr = newPlanet;
        }
    }

    Reset();
    currentPtr = headDiameter;

    if(newPlanet->Diameter < headDiameter->Diameter)
    {
        newPlanet->diameterPtr = headDiameter;
        headDiameter = newPlanet;
    }
    else
    {
        while(currentPtr->diameterPtr != NULL && 
            currentPtr->diameterPtr->Diameter < newPlanet->Diameter ) 
        {
            GetNext(DIAMETER);
        }

        if(currentPtr->diameterPtr == NULL)
            currentPtr->diameterPtr = newPlanet;
        else
        {
            newPlanet->diameterPtr = currentPtr->diameterPtr;
            currentPtr->diameterPtr = newPlanet;
        }
    }
    planetCount++;
}


void List::Remove(string planetName)
{
    planetPtr temp = Find(planetName);
    Reset();

    if(temp != NULL)
    {
        if(temp == headDistance)
            headDistance = headDistance->distancePtr;
        else if(!temp->distancePtr)
            distanceTail = temp->reverseDistancePtr;
        else
        {    
            currentPtr = temp->reverseDistancePtr;
            currentPtr->distancePtr = temp->distancePtr;
            temp->distancePtr->reverseDistancePtr = currentPtr;
        }

        Reset();
        currentPtr = headMass;
        
        if(temp == headMass)
            headMass = headMass->massPtr;
        else if(temp->massPtr)
        {
            while(currentPtr->massPtr->Name != temp->Name)
            {
                GetNext(MASS);
            }
                    
            currentPtr->massPtr = temp->massPtr;
        }
        
        Reset();
        currentPtr = headDiameter;
        
        if(temp == headDiameter)
            headDiameter = headDiameter->diameterPtr;
        else if(temp->diameterPtr)
        {
            while(currentPtr->diameterPtr->Name != temp->Name)
                GetNext(DIAMETER);
        
            currentPtr->diameterPtr = temp->diameterPtr;
        }

        delete temp;
        
        planetCount--;
    }
}

planetPtr List::Find(string search)
{
    planetPtr temp = headDistance;
    
    while(temp->Name != search && temp->distancePtr != NULL)
    {
        temp = temp->distancePtr;
    }

    if(temp->Name == search)
        return temp;
    else
        return NULL;
}

string List::Name() const
{
    if(currentPtr)
        return currentPtr->Name;
}
float List::Distance() const
{
    if(currentPtr)
        return currentPtr->DistanceFromSun;
}


float List::Mass() const
{
    if(currentPtr)
        return currentPtr->Mass;
}


float List::Diameter() const
{
    if(currentPtr)
        return currentPtr->Diameter;
}



void List::GetNext(linkType type) 
{
    if(!currentPtr)
    {
        if(type == MASS)
            currentPtr = headMass;
        else if(type == DISTANCE)
            currentPtr = headDistance;
        else if(type == DIAMETER)
            currentPtr = headDiameter;
    }
    else
    {
        if(type == MASS)
            currentPtr = currentPtr->massPtr;
        else if(type == DISTANCE)
            currentPtr = currentPtr->distancePtr;
        else if(type == DIAMETER)
            currentPtr = currentPtr->diameterPtr;
    }
    
    return;
}


void List::GetPrevious() 
{
    currentPtr = currentPtr->reverseDistancePtr;
}


void List::Reset()
{
    currentPtr == NULL;
}


void List::BigBang()
{
    headDistance = Mercury();
    currentPtr = headDistance;
    currentPtr->distancePtr = Venus();
    
    GetNext(DISTANCE);
    
    currentPtr->distancePtr = Earth();
    GetNext(DISTANCE);
    
    currentPtr->distancePtr = Mars();
    GetNext(DISTANCE);
    
    currentPtr->distancePtr = Jupiter();
    GetNext(DISTANCE);
    
    currentPtr->distancePtr = Saturn();
    GetNext(DISTANCE);
    
    currentPtr->distancePtr = Uranus();
    GetNext(DISTANCE);
    
    currentPtr->distancePtr = Neptune();
    GetNext(DISTANCE);
    
    currentPtr->distancePtr = Pluto();
    GetNext(DISTANCE);
    
    currentPtr->distancePtr = NULL;
    
    distanceTail = currentPtr;
    
    Reset();
        
    return;   
}


void List::ReverseLink()
{
    planetPtr temp;
    
    currentPtr = headDistance;
    
    currentPtr->reverseDistancePtr = NULL;
    
    for(int i = 1; i < 9; i++)
    {
        temp = currentPtr;
        
        GetNext(DISTANCE);
        
        currentPtr->reverseDistancePtr = temp;
    }
    
    Reset();
    
    return;    
}


void List::LinkMass()
{
    headMass = Find(planetNames[massPath[0]]);
    currentPtr = headDistance;
    
    planetPtr temp = headMass;
    
    for(int i = 1; i < 9; i++)
    {
        temp->massPtr = Find(planetNames[massPath[i]]);
        temp = temp->massPtr;
    }
    
    temp->massPtr = NULL;
    
    Reset();
    
    return;
}


void List::LinkDiameter()
{    
    headDiameter = Find(planetNames[diameterPath[0]]);
    currentPtr = headDistance;
    
    planetPtr temp = headDiameter;
    for(int i = 1; i < 9; i++)
    {
        temp->diameterPtr = Find(planetNames[diameterPath[i]]);
        temp = temp->diameterPtr;
    }
    
    temp->diameterPtr = NULL;
    
    Reset();

    return;
}


void List::PrintReverse()
{
    currentPtr = headDistance->distancePtr;
    for(int i = 0; i < planetCount; i++)
    {
        
        if(currentPtr->reverseDistancePtr)
        {
            cout << currentPtr->reverseDistancePtr->Name << endl << currentPtr->reverseDistancePtr->DistanceFromSun << endl << endl;

            if(!currentPtr->distancePtr)
            {
                cout << currentPtr->Name << endl << currentPtr->DistanceFromSun << endl << endl;
                break;
            }
        }
        

        GetNext(DISTANCE);
    }
}

void List::PrintForward(linkType type)
{
    Reset();
    
    if(type == DISTANCE)
        currentPtr = headDistance;
    else if(type == MASS)
        currentPtr = headMass;
    else if(type == DIAMETER)
        currentPtr = headDiameter;

    for(int i = 0; i < planetCount; i++)
    {
        Print(currentPtr, type);
        GetNext(type);
    }
    
    return;
}
