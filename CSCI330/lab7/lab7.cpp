
//pair datatype
#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main( )
{
// Create a variable that is a pair consisting of item and price
  
  pair<string, float> data;

  data.first = "pen";
  data.second = 1.20;

// Assign directly into this variable using first & second


// Create a variable using parameterized constructor to create with values
//    "book", 14.95
  pair<string, float> preconstruct("book",14.95);

// Create a variable using the copy constructor
  pair<string, float> copy(preconstruct);
        
	
// print the pair values by accessing the fields
  cout << endl << copy.first << " " << copy.second << endl << endl;
	
// Ask the user for a pair and assign it to the variable

	string item;
	float price;
	cout << "Enter item: ";
	cin >> item;
	cout << "Enter price:";
	cin >> price ;
	
  pair<string,float> item(item, price);


// Create a datatype for the pair
  typedef pair<string,float> PairType;
        
        
// Create a vector of this pair datatype
  vector<PairType> shoppingList;


cout <<endl<<endl;
// Load the vector with 5 pairs of items and prices
//      using user input
  for(int i = 0; i < 5; i++)
  {
   string item;
   float price;

   cout << "Enter item: ";
   cin >> item;

   cout << "Enter price: ";
   cin >> price;

   shoppingList.push_back(make_pair(item,price));
  }



cout <<endl<<endl;
// Print the vector using subscripting
 for(vector<PairType>::iterator it = shoppingLists.begin( ); it != shoppingList.end( ); it++)
 {
   
 

cout <<endl<<endl;
// sort the vector

// Print the vector using iterators
        





        cout  <<endl<<endl; 

	return 0;
}
