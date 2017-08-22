#include <iostream>
#include "cc1.h"

using namespace std;
using namespace GameSpace;

void PrintConstructors( );
void PrintOverloadedOps( );
void PrintGetters( );
void TestCopy(CreatureClass temp);


int main( )
{
  Dice::SeeRolls( );
  //CreatureClass temp("Copy Test");
  //CreatureClass temp2("ErrorTest", CreatureClass::ELF);
  //cout << endl << temp2 << endl << endl;
  PrintConstructors( );
 // PrintOverloadedOps( );
  //PrintGetters( );
  //cout << endl << temp;
  //TestCopy(temp);
  
  
  CreatureClass c1;
  
  cout << c1 << endl;
  
  cout << endl << endl << c1.HP () << endl << endl;
  
  c1.UpdateHP(-8);
  
  cout << c1.HP() << endl << endl;
  
  c1.UpdateHP(-22);
  
  cout << endl << c1.HP() << endl << endl;
  
  cout << c1.Disabled( ) << endl << endl;
  
  c1.UpdateHP(22);
  
  cout << c1.HP( ) << "     " << c1.Disabled( ) << endl << endl;
  
  
  
  
}



void PrintConstructors( )
{
  cout << endl << "*****" << "CONSTRUCTORS" << "*****" << endl << endl;
  
  PrintTest(cout,"C");
  CreatureClass c1;
  cout << c1;
  
  GameSpace::PrintTest(cout);
  CreatureClass c2("Old");
  cout << c2;
  
  GameSpace::PrintTest(cout);
  CreatureClass c3("Mcdonald", CreatureClass::OGRE);
  cout << c3;
  
  GameSpace::PrintTest(cout);
  CreatureClass c4("    Woah     Black    Betty", CreatureClass::HALFELF, CreatureClass::FTR);
  cout << c4; 
}

void PrintOverloadedOps( )
{
  
  cout << endl << "*****" << "OVERLOADED ==" << "*****" << endl << endl;
  
  bool temp;
  CreatureClass c1("Betty", CreatureClass::ELF);
  CreatureClass c2;
  CreatureClass c3;
  CreatureClass c4("Betty");
  CreatureClass c5("Bob");
  
  //*************boolean==***************    
  PrintTest(cout, "P");
  temp = (c1 == c2); //false
  cout << " " << temp << endl;
  
  GameSpace::PrintTest(cout);
  temp = (c2 == c3); //true
  cout << " " << temp << endl;
  
  GameSpace::PrintTest(cout);
  temp = (c1 == c4); //true
  
  cout << " " << temp << endl;
  
  GameSpace::PrintTest(cout);
  temp = (c2 == c5); //false
  cout << " " << temp << endl;
  
  GameSpace::PrintTest(cout);
  temp = (c4 == c5); //false
  cout << " " << temp << endl;
  
  //***********boolean!=*****************   
  cout << endl << "*****" << " OVERLOADED != " << "*****" << endl << endl;

  GameSpace::PrintTest(cout);
  temp = (c1 != c2); //true
  cout << " " << temp << endl;
  
  GameSpace::PrintTest(cout);
  temp = (c2 != c3); //false
  cout << " " << temp << endl;    
  
  GameSpace::PrintTest(cout);
  temp = (c1 != c4); //false
  cout << " " << temp << endl;
  
  GameSpace::PrintTest(cout);
  temp = (c2 != c5); //true
  cout << " " << temp << endl;
  
  GameSpace::PrintTest(cout);
  temp = (c4 != c5); //true
  cout << " " << temp << endl;
  
  //**********extraction*****************
  cout << endl << "*****" << " OVERLOADED EXTRACTION " << "*****" << endl << endl;

  
  GameSpace::PrintTest(cout);
  cout << c2 << endl;
 
  GameSpace::PrintTest(cout);
  cout << c1 << endl;
  
  cout << endl << "*****" << " OVERLOADED ASSIGNMENT " << "*****" << endl << endl;
  GameSpace::PrintTest(cout);
  c2 = c1;
  cout << endl << c2 << c1 << endl;
  
  GameSpace::PrintTest(cout);
  c4 = c3;
  cout << endl << c4 << c3 << endl;
  
}

void PrintGetters( )
{
  cout << endl << "*****" << " GETTERS " << "*****" << endl << endl;
  CreatureClass c1("Test One", CreatureClass::ELF, CreatureClass::CLR);
  
  cout << c1.Name( ) << "#" << c1.Row( ) << "#" << c1.Column( ) << "#" << c1.Race( ) << "#"
  << c1.Race( ) << "#" << c1.Voc( ) << "#" << c1.Level( ) << "#" << c1.HP( ) << "#" << c1.XP( ) << "#" << c1.GP( )
  << "#" << endl;
  
  cout << endl << "*****" << " DEAD/DYING/DISABLED/HUMANOID/MONSTER " << "*****" << endl << endl;
  cout << c1.Dead( ) << "#" << c1.Dying( ) << "#" << c1.Disabled( ) << "#" << c1.Humanoid( ) << "#" << c1.Monster( ) << "#" << endl;
  
  cout << "Hp before mod: " << c1.HP( ) << endl;
  c1.UpdateHP(-22);
  cout << "Hp after mod: " << c1.HP( ) << endl;
  cout << c1.Dead( ) << "#" << c1.Dying( ) << "#" << c1.Disabled( ) << "#" << c1.Humanoid( ) << "#" << c1.Monster( ) << "#" << endl;
  
  cout << c1.SetCell(-2, -5) << "#" << c1.SetCell(-1,-1) << "#" << c1.SetCell(0,-1) << "#" << c1.SetCell(-1,0) << "#" << c1.SetCell(5,5) << "#" << endl;
}

void TestCopy(CreatureClass temp)
{
  cout << temp << endl;
}
  