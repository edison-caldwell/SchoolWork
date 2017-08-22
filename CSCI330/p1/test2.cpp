#include <iostream>
#include "cc1.h"

using namespace std;

int main()
{
  Dice::SeeRolls( );
  CreatureClass c1("OGRE TEST", CreatureClass::OGRE);

  cout << c1.Monster() << " : " << c1.Humanoid() << endl << endl;

  cout << endl << c1 << endl << endl;


  return 0;
}