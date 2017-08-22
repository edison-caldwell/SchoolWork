#include "List.h"
#include <iomanip>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits>

using namespace std;
using namespace Milkyway;

void PreFace();
void ClearScreen();
int MainMenu(List l);
void DistanceView(List l);
void ReverseDistanceView(List l);
void MassView(List l);
void DiameterView(List l);
List PurchasePlanet(List l);
List SellPlanet(List l);

string PAUSE;


int main()
{
	List milkyway;
	//ClearScreen();
	PreFace();
	//ClearScreen();
	MainMenu(milkyway);


}

void PreFace()
{	

	cout << "\n\n\n\n\n\n";
	centerstring("WELCOME TO THE GALAXY!");
	cout << endl;
	centerstring("TO FULLY ENJOY YOUR STAY YOU NEED SOME INFORMATION ABOUT THIS SYSTEM.");
	cout << endl;
	centerstring("PLEASE HIT ENTER TO CONTINUE.");
	cout << "\n\n\n\n\n\n\n\n\n\n";

	getline(cin,PAUSE);
    //cin.ignore();
}

void ClearScreen()
{
    cout << string( 100, '\n' );
}

int MainMenu(List l)
{
	string choice;

	//ClearScreen();
	do {
		//ClearScreen();
		cout << "\n\n\n\n\n\n";
		centerstring("PLEASE CHOOSE FROM THE OPTIONS BELOW TO LEARN MORE ABOUT THE SYSTEM YOU ARE IN");
		cout << endl;
		centerstring("1. VIEW PLANETS IN DISTANCE FROM THE NEAREST SUN");
		cout << endl;
		centerstring("2. VIEW PLANETS IN REVERSE DISTANCE FROM THE NEAREST SUN");
		cout << endl;
		centerstring("3. VIEW PLANETS BASED ON MASS");
		cout << endl;
		centerstring("4. VIEW PLANETS BASED ON DIAMETER");
		cout << endl;
		centerstring("5. PURCHASE A NEW PLANET FOR THE SOLAR SYSTEM");
		cout << endl;
		centerstring("6. SELL A PLANET IN THE SOLAR SYSTEM (DOING SO WILL DESTROY THE PLANET)");
		cout << endl;
		centerstring("7. EXIT TERMINAL");
		cout << endl;
		centerstring("WHICH WOULD YOU LIKE? PLEASE TYPE ONE, TWO, THREE, FOUR, ECT.");
		cout << "\n\n\n\n\n\n\n\n\n\n";

		cin >> choice;
		cout << endl << endl;


		if(choice == "ONE")
			DistanceView(l);
		else if(choice == "TWO")
			ReverseDistanceView(l);
		else if(choice == "THREE")
			MassView(l);
		else if(choice == "FOUR")
			DiameterView(l);
		else if(choice == "FIVE")
			l = PurchasePlanet(l);
		else if(choice == "SIX")
			l = SellPlanet(l);

		getline(cin,PAUSE);

	} while(choice != "SEVEN");
}



void DistanceView(List l)
{
	l.PrintForward(DISTANCE);
}

void ReverseDistanceView(List l)
{
	l.PrintReverse();
}

void MassView(List l)
{
	l.PrintForward(MASS);
}

void DiameterView(List l)
{
	l.PrintForward(DIAMETER);
}

List PurchasePlanet(List l)
{
	planetPtr temp = NewPlanet();

	l.Insert(temp);

	return l;
}

List SellPlanet(List l)
{
	string name;
	cout << "PLEASE ENTER THE NAME OF A PLANET TO REMOVE/DESTROY: ";
	getline(cin, name);
	l.Remove(name);

	return l;
}
