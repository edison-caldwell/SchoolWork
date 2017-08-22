#include <iostream>
#include "List.h"

using namespace std;
using namespace Milkyway;

void foo(List test);

int main()
{    
    List constructor;
    
    cout << constructor;
    
    List insert;
    
    //insert.Insert(NewPlanet());
    
    //cout << "AFTER INSERT" << endl;
    cout << insert << endl << endl;

    //insert.PrintReverse();
    //insert.Remove("BUTTS");
    //cout << "AFTER REMOVE" << endl << endl;
    //cout << insert << endl << endl;

    //cout << "REMOVINg BUTTS" << endl << endl << insert << endl << endl;
    
    foo(insert);

    cout << "END OF MAIN" << endl << endl;
    
    return 0;
    
}

void foo(List test)
{
	cout << "TESTING COPY CONSTRUCT" << endl << endl;
    test.PrintForward();
	return;
}
