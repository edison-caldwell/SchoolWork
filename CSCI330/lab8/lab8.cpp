
// maps

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

void PrintPair(pair<string,float> p);

int main( )
{
// Create a map variable that will contain items and prices
  map<string,float> m;

// Insert an item and price into the map - try this a few ways
  m.insert(make_pair("Ball",8.75));

  m["Action Figure"] = 15.99;

  m["Ugly Sweater"] = 22.45;

// Print an item's price from the map
  
  

  for(map<string,float>::iterator it = m.begin( ); it != m.end( ); it++)
    cout << it->first << " $" << it->second <<  endl;

// Print an item's price that is not in the map


cout <<"\n****************\n";
// Print the map


cout <<"\n****************\n";
// Print the map using for_each


cout <<"\n****************\n";
// Modify one of the item's price value
  m["Ugly Sweater"] = 12.99;
  cout << m["Ugly Sweater"] << endl;
// Check the price on one of the items that is in the map
  

// Check the price on an item that is not in the map
  cout << m["Tickle Me Elmo!"] << endl;

cout <<"\n****************\n";
// Print the map using for_each
  for_each(m.begin( ), m.end( ), PrintPair);

cout <<"\n****************\n";
// Find an item in the map and print the price
  if(m["Ball"] == 22.00)
    cout << "Damn that's expensive" << endl << endl;
  else
    cout << m["Ball"] << "... seems about right" << endl << endl;

  if(find(m.begin( ), m.end( ), "USB")) != m.end( ))   //how the hell??
    m.erase(find(m.begin( ), m.end( ), "USB")->first);  


cout <<"\n****************\n";
// Erase the item from the map
  m.erase("Tickle Me Elmo!");
// Print the map using for_each
  for_each(m.begin( ), m.end( ), PrintPair);

cout <<"\n****************\n";
cout <<endl <<endl;

	return 0;
}

void PrintPair(pair<string,float> p)
{
  cout << p.first << " $" << p.second << endl;
}



