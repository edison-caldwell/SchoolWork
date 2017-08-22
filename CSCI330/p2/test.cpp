#include <iostream>
#include "cc2.h"
#include <sstream>
#include <fstream>


using namespace std;

void PrintShit(CreatureClass c);
string Fuck(int);
void PrintVec(vector<string>);

int main()
{
  Dice::ReadRollsFromFile( );
  Dice::SeeRolls( );
  
  /*CreatureClass c0(""); 
   * CreatureClass c1("H1"); 
   * CreatureClass c2("HE2", CreatureClass::HALFELF);
   * CreatureClass c3("E3", CreatureClass::ELF, VocRules::FTR); 
   * CreatureClass c4("O4",CreatureClass::ORC, VocRules::WIZ);
   * CreatureClass c5("E5",CreatureClass::ELF, VocRules::NNE); 
   * CreatureClass c6("T6",CreatureClass::TROLL);
   * CreatureClass c7("OG7", CreatureClass::OGRE, VocRules::NNE);
   * CreatureClass c8("H8", static_cast<CreatureClass::RaceType>(15)); 
   * CreatureClass c9("H9", static_cast<CreatureClass::RaceType>(8), static_cast<VocRules::VocType>(19));
   * CreatureClass c10("H10", static_cast<CreatureClass::RaceType>(8), static_cast<VocRules::VocType>(5));
   * CreatureClass c11("O11", CreatureClass::ORC, VocRules::ROG);
   * CreatureClass c12("HE12", CreatureClass::HALFELF, VocRules::BBN); 
   * CreatureClass c13("E13", CreatureClass::ELF, VocRules::CLR); */
  
  cout << endl << endl << "Welcome to the DANGER-ZONE" << endl << endl;
  
  /*fstream shrek;
   * 
   * shrek.open("run.in");
   * 
   * 
   * vector<string> tempvec;
   * 
   * string tempstr;
   * 
   * getline(shrek, tempstr);
   * while(shrek)
   * { 
   *  tempvec.push_back(tempstr);
   *  
   *  getline(shrek, tempstr);
   * 
}

shrek.close( );*/
  
  
  CreatureClass* c[14];
  
  c[0] = new CreatureClass("");
  
  c[1] = new CreatureClass("HH1");
  
  c[2] = new CreatureClass("FF2", CreatureClass::HALFELF);
  
  c[3] = new CreatureClass("EE3", CreatureClass::ELF, VocRules::FTR);
  
  c[4] = new CreatureClass("OO4",CreatureClass::ORC, VocRules::WIZ);
  
  c[5] = new CreatureClass("EE5",CreatureClass::ELF, VocRules::NNE);
  
  c[6] = new CreatureClass("TT6",CreatureClass::TROLL);
  
  c[7] = new CreatureClass("GG7", CreatureClass::OGRE, VocRules::NNE);
  
  c[8] = new CreatureClass("HH8", static_cast<CreatureClass::RaceType>(15));
  
  c[9] = new CreatureClass("HH9", static_cast<CreatureClass::RaceType>(8), static_cast<VocRules::VocType>(19));
  
  c[10] = new CreatureClass("HH10", static_cast<CreatureClass::RaceType>(8), static_cast<VocRules::VocType>(5));
  
  c[11] = new CreatureClass("OO11", CreatureClass::ORC, VocRules::ROG);
  
  c[12] = new CreatureClass("FF12", CreatureClass::HALFELF, VocRules::BBN);
  
  c[13] = new CreatureClass("EE13", CreatureClass::ELF, VocRules::CLR);
  
  
  /*
   * cout << c[0]->Level( ) << " : " << c[0]->XP( ) << " : " << c[0]->HP( ) << endl;
   * Dice::SeeRolls( );
   * c[0]->UpdateXP(4000);
   * Dice::HideRolls( );
   * cout << c[0]->Level( ) << " : " << c[0]->XP( ) << endl;
   * 
   * cout << c[0]->HP( ) << endl << endl;
   * 
   * c[0]->UpdateHP(16);
   * 
   * cout << c[0]->Dying( ) << " : " << c[0]->Disabled( ) << " : " << c[0]->Dead( ) << endl;
   * 
   * c[0]->Amnesia( );
   * 
   * 
   * 
   * cout << c[0]->AddSkill("HIDE") << endl;
   * cout << c[0]->AddSkill("JUMP") << endl;
   * cout << c[0]->AddSkill("HEAL") << endl;
   * 
   * c[0]->Write(cout);
   * cout << endl;
   * 
   * shrek.open("run.out");
   * int count = 0;
   * 
   * for(int i = 0; i < 14; i++)
   * {
   *   shrek << "Mine: ";
   *   c[i]->Write(shrek);
   *   shrek << "Hers: " << tempvec[i] << endl << endl;
}

c[3]->Write(cout);

vector<int> intVec = c[3]->Abilities( );

for(int i = 0; i <intVec.size( ); i++)
  cout << intVec[i] << ", ";

CreatureClass temp("ButtSecks");

temp.Write(cout);

PrintShit(temp);

temp.WriteSkillList( );

temp.SkillCheck("SWIM");

CreatureClass temp2(""); 

cout << endl;

cout << temp2.SkillCheck("HIDE") << endl << temp2.SkillCheck("INTIMIDATE");

CreatureClass harry("Harry Potter", CreatureClass::ELF, VocRules::WIZ);

cout << endl << harry.SkillCheck("CONCENTRATION");


cout << endl << endl << "ASSIGNMENT" << endl << endl;
c[4]->Write(cout);
cout << endl;
c[0]->Write(cout);
cout << endl << endl;

*c[2] = *c[0];
c[2]->Write(cout);
cout << endl;
c[0]->Write(cout);
cout << endl;

CreatureClass N1("H0r");
CreatureClass G1("H0r");

cout << (N1 == G1) << " " << (N1 != G1) << " " << (N1 <= G1) << " " << (N1 < G1) << " " << (N1 >= G1) << " " << (N1 > G1) << endl << endl;

CreatureClass N2("E1r");
CreatureClass G2("e1r");

cout << (N2 == G2) << " " << (N2 != G2) << " " << (N2 <= G2) << " " << (N2 < G2) << " " << (N2 >= G2) << " " << (N2 > G2) << endl << endl;

CreatureClass N3("F2r");
CreatureClass G3("F1r");

cout << (N3 == G3) << " " << (N3 != G3) << " " << (N3 <= G3) << " " << (N3 < G3) << " " << (N3 >= G3) << " " << (N3 > G3) << endl << endl;

CreatureClass N4("O3r");
CreatureClass G4("O5r");

cout << (N4 == G4) << " " << (N4 != G4) << " " << (N4 <= G4) << " " << (N4 < G4) << " " << (N4 >= G4) << " " << (N4 > G4) << endl << endl;

CreatureClass N5("T4r");
CreatureClass G5("T44r");

cout << (N5 == G5) << " " << (N5 != G5) << " " << (N5 <= G5) << " " << (N5 < G5) << " " << (N5 >= G5) << " " << (N5 > G5) << endl << endl;

CreatureClass N6("G5");
CreatureClass G6("G 5r");

cout << (N6 == G6) << " " << (N6 != G6) << " " << (N6 <= G6) << " " << (N6 < G6) << " " << (N6 >= G6) << " " << (N6 > G6) << endl << endl;


//CreatureClass N1("H0"), N2(" E1"), N3("F2"), N4("\tO3"), N5(" T4 "), N6("G5");

cout << N1.Name( ) << " " << N2.Name( ) << " " << N3.Name( ) << " " << N4.Name( ) << " " << N5.Name( ) << " " << N6.Name( ) << " ";


CreatureClass B1("ZIM ZAM", static_cast<CreatureClass::RaceType>(15), static_cast<VocRules::VocType>(12));

WpnClass* myWep = new WpnClass("Club");

WpnClass* other = NULL;

other = B1.ChangeWeapon(myWep);
if(!other)
  cout << "This is NULL" << endl << endl;
ArmorClass* myArmor = new ArmorClass("Leather");

ArmorClass* tempArmor = NULL;

tempArmor = B1.ChangeArmor(myArmor);

WpnClass* tempWep = new WpnClass("Claws");

other = B1.ChangeWeapon(tempWep);

cout << other->Name( ) << endl << endl;

delete myWep;
myWep = NULL;
delete myArmor;
myArmor = NULL;

//myArmor = B1.LoseArmor( );

//myWep = B1.LoseWeapon( );

//cout << myWep->Name( ) << " : " << myArmor->Name( ) << endl << endl;

B1.AddSkill("HIDE");

B1.AddSkill("DIGGING");

Dice::SeeRolls( );

cout << B1.SkillCheck("HIDE") << endl << endl;

Dice::HideRolls( );

cout << B1.HasWeapon( ) << " " << B1.HasArmor( ) << endl << endl;

delete other;
other = B1.ChangeWeapon(NULL);

delete tempArmor;
tempArmor = B1.ChangeArmor(NULL);

cout << B1.Weapon( ) << endl << B1.Armor( ) << endl << endl;  

B1.Amnesia( );

B1.AddSkill("JUMP");

B1.AddSkill("USE MAGIC DEVICES");

B1.AddSkill("HEAL");

PrintVec(B1.Skills( ));

//B1.UpdateHP(-3);

cout << B1.AddSkill("BLUFF") << endl; //HP > ZERO
B1.AddSkill("HIDE");

B1.Amnesia( );  

cout << B1.SkillCheck("BLUFF") << endl; //HP > -10


cout << "AAAAAAAAAAAAHHHHHHHHHHHHHHHHHHHHH" << endl << endl;


cout << endl;
B1.Write(cout);
cout << endl;

//   cout << B1.Row() << endl << B1.Column( ) << endl << B1.Race( ) << endl << B1.Voc( )
//   << endl <<  B1.Level( ) << endl << B1.HP( ) << endl << B1.XP( ) << endl << B1.GP( ) << endl  << B1.Humanoid( ) << endl
//   << B1.Disabled( ) << endl << B1.Dying( ) << endl << B1.Dead( );
*/
  
  
  //Dice::SeeRolls( );
  //CreatureClass hpCheck("EE3", CreatureClass::ELF, VocRules::WIZ);
  
  c[3]->Write(cout);
  
  cout << endl;
  
  c[3]->UpdateXP(60009);
  
  c[3]->Write(cout);
  
  cout << endl;
  
  c[3]->UpdateXP(99958724);
  
  c[3]->Write(cout);
  
  cout << endl;
  
  cout << "***************************************ChangeWep/Armor***************************\n\n";
  
  WpnClass* tempWep = NULL;
  
  ArmorClass* tempArmor = NULL;
  
  cout << c[3]->ChangeWeapon(tempWep);
  
  cout << c[3]->ChangeArmor(tempArmor);
  
  tempWep = new WpnClass("Uzi");
  
  c[3]->ChangeWeapon(tempWep);
  
  c[3]->Write(cout);
  
  cout << endl << endl;
  
  cout << "**************************************ADD SKILL*********************************\n\n";
  
  cout << c[3]->AddSkill("This is not a SKILL") << endl;
  
  cout << c[3]->AddSkill("HEAL") << endl;
  
  cout << c[3]->AddSkill("HEAL") << endl;
  
  vector<string> tempVec;
  
  tempVec = c[3]->Skills( );
  
  for(int i = 0; i < tempVec.size( ); i++)
      cout << tempVec[i] << endl;
  
  for(int i = 0; i < 14; i++)
    delete c[i];
  
  return 0;
}

void PrintVec(vector<string> obama)
{
  for(vector<string>::iterator it = obama.begin( ); it < obama.end( ); it++)
    cout << *it << endl;
}

void PrintShit(CreatureClass c)
{
  c.Write(cout);
  cout << endl;
}

string Fuck(int you)
{
  string bitch;
  
  switch(you)
  {
    case 0 : bitch = "BLUFF";
    break;
    case 1 : bitch = "BALANCE";
    break;
    case 2 : bitch =  "CLIMB";
    break;
    case 3 : bitch = "CONCENTRATION";
    break;
    case 4 : bitch = "DIPLOMACY";
    break;
    case 5 : bitch = "DISABLE DEVICE";
    break;
    case 6 : bitch = "HAGGLE";
    break;
    case 7 : bitch = "HEAL";
    break;
    case 8 : bitch = "HIDE";
    break;
    case 9 : bitch = "INTIMIDATE";
    break;
    case 10 : bitch = "JUMP";
    break;
    case 11 : bitch = "MOVE SILENTLY";
    break;
    case 12 : bitch = "OPEN LOCK";
    break;
    case 13 : bitch = "PERFORM";
    break;
    case 14 : bitch = "REPAIR";
    break;
    case 15 : bitch = "SEARCH";
    break;
    case 16 : bitch = "SPOT";
    break;
    case 17 : bitch = "SWIM";
    break;
    case 18 : bitch = "TUMBLE";
    break;
    case 19 : bitch = "USE MAGIC DEVICES";
    break;
  }
  
  return bitch;
  
  
}
