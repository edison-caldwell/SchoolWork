// lab2.cpp


#include <iostream>
#include <string>
#include <vector>
#include "str2.h"

using namespace std;

vector<int> InputVector( );
void WriteVector(vector<int>);
vector<StrClass> InputStrClassVector( );
void WriteStrClassVector(vector<StrClass>);
void CheckIsPal(vector<StrClass>);

int main(void)
{
	vector<int> vec1;

	vec1 = InputVector( );
        
	WriteVector(vec1);

	cout << vec1.size() << endl << endl;
	
	vector<StrClass> vec2;
	
	vec2 = InputStrClassVector( );
	
	WriteStrClassVector(vec2);
	
	CheckIsPal(vec2);

	
	
	return 0;
}

vector<int> InputVector( )
{

	int input;
	vector<int> temp;

	cout << "Enter values for the vector (neg to end): ";
	cin >> input;
	while(input >= 0)
	{
		temp.push_back(input);
		
		cout << "Next: ";
		cin >> input;
	}

	return temp;
}

void WriteVector(vector<int> out_vec)
{
	/*for(vector<int>::iterator it = out_vec.begin(); it < out_vec.end( ); it ++)
	{
		cout << *it << endl;
	}*/
	
	int length = out_vec.size( );
	for(int i = 0; i < length; i++)
	{
		cout << endl << out_vec[i];
	}
	
	out_vec.clear();
	cout << endl << endl;
}


//******************************************************************
//******************************************************************


vector<StrClass> InputStrClassVector( )
{
	vector<StrClass> vec;
	
	string mystring;

	StrClass myclass;
	
	cin.ignore( );
	
	for(int i = 0; i < 5; i++)
	{
		cout << "Enter a string: ";
		
		getline(cin, mystring);
		
		myclass.SetStr(mystring.c_str());

		vec.push_back(myclass);
	}
	
	return vec;
}

void WriteStrClassVector(vector<StrClass> out)
{
	StrClass temp;

	/*for(vector<StrClass>::iterator it = out.begin( ); it < out.end( ); it++)
	{
		it->DisplayStr( );
		cout << endl << endl;
	}*/
	
	for(int i = 0; i < out.size(); i++){
	  cout << endl;
	  out[i].DisplayStr( );
	  cout << endl << endl;}
}


void CheckIsPal(vector<StrClass> temp)
{
  for(vector<StrClass>::iterator it = temp.begin( ); it < temp.end( ); it++)
    cout << it->IsPal( ) << endl;
}

