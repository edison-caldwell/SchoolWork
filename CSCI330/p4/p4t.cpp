#include "handle4.h"

using namespace std;

void Observe(Creature);

void Update(Creature);

void Skills(Creature);

int main( )
{
  
  string pause;
//   Dice::SeeRolls( );
  
//   Dice::ReadRollsFromFile( );
  
  Creature* t[5];
  
  t[0] = new Creature("H12", Creature::HUMAN);
  t[1] = new Creature("E13", Creature::ELF);
  t[2] = new Creature("O15", Creature::ORC);
  t[3] = new Creature("T16", Creature::TROLL);
  t[4] = new Creature("G17", Creature::OGRE);
  
  Creature skilltest("H18");
  
    for(int i = 0; i < 5; i++)
  {
    cout << string(50, '\n');
    Observe(*t[i]);
    getline(cin, pause);
  }
  
  
  for(int i = 0; i < 5; i++)
  {
    cout << string(50, '\n');
    Update(*t[i]);
    getline(cin, pause);
  }
  
  for(int i = 0; i < 5; i++)
  {
    cout << string(50, '\n');
    Skills(*t[i]);
    getline(cin, pause);
  }
  
  
  
  return 0;
}


void Observe(Creature temp)
{
  cout << "**********TEST OBSERVERS**********\n\n\n";
  
  temp.Write(cout);
  
  cout << endl;
  
  for(int i = 0; i < 6; i++)
    cout << "ABILITY[" << i << "]: " <<  temp.Ability(static_cast<CreatureClass::AbilityType>(i)) << endl;
  
  cout << endl << "ABILITIES: ";
  
  vector<int> abilities = temp.Abilities( );
  
  for(int i = 0; i < 6; i++)
    cout << abilities[i] << " ";
  
  cout << endl << "ROW: " << temp.Row( ) << endl;
  
  cout << "COL: " << temp.Column( ) << endl;
  
  cout << "RACE: " << temp.Race( ) << endl;
  
  cout << "VOC: " << temp.Voc( ) << endl;
  
  cout << "LEVEL: " << temp.Level( ) << endl;
  
  cout << "HP: " << temp.HP( ) << endl;
  
  cout << "XP: " << temp.XP( ) << endl;
  
  cout << "GP: " << temp.GP( ) << endl;
  
  cout << "HUMANOID: " << temp.IsHumanoid( ) << endl;
  
  cout << "MONSTER: " << temp.IsMonster( ) << endl;
  
  cout << "DISABLED: " << temp.Disabled( ) << endl;
  
  cout << "DYING: " << temp.Dying( ) << endl;
  
  cout << "DEAD: " << temp.Dead( ) << endl;
  
  cout << string(15, '\n');
}

void Update(Creature temp)
{
  cout << "**********TEST UPDATES**********\n\n\n";
  
  temp.Write(cout);
  
  cout << endl;
  
  cout << "SET CELL(3,-1)(-1,3)(3,3): " << temp.SetCell(3,-1) << " " << temp.SetCell(-1,3) << " " << temp.SetCell(3, 3) << endl;
  
  cout << "UPDATE GP(9): " << temp.UpdateGP(9) << endl;
  
  cout << "UPDATE GP(-20): " << temp.UpdateGP(-20) << endl;
  
  cout << "UPDATE XP: " << temp.UpdateXP(2600001) << endl;
  
  cout << "UPDATE HP: " << temp.UpdateHP(28) << endl;
  
  cout << "ROW: " << temp.Row( ) << endl;
  
  cout << "COLUMN: " << temp.Column( )  << endl;
  
  cout << "RACE: " << temp.Race( ) << endl;
  
  cout << "VOC: " << temp.Voc( ) << endl;
  
  cout << "LEVEL: " << temp.Level( ) << endl;
  
  cout << "HP: " << temp.HP( ) << endl;
  
  cout << "XP: " << temp.XP( ) << endl;
  
  cout << "GP: " << temp.GP( ) << endl;
  
  cout << "HUMANOID: " << temp.IsHumanoid( ) << endl;
  
  cout << "MONSTER: " << temp.IsMonster( ) << endl;
  
  cout << "DISABLED: " << temp.Disabled( ) << endl;
  
  cout << "DYING: " << temp.Dying( ) << endl;
  
  cout << "DEAD: " << temp.Dead( ) << endl;
  
  cout << string(15, '\n');
}

void Skills(Creature temp)
{
  cout << "**********TEST SKILLS**********\n\n\n";
  
  temp.Write(cout);
  
  cout << endl;
  
  cout << "HP: " << temp.HP() << endl;
  
  vector<string> sks = temp.Skills( );
  
  cout << "SKILLS: ";
  
  for(int i = 0; i < sks.size( ); i++)
    cout << sks[i] << " ";
  
  cout << endl;
  
  cout << "AMNESIA" << endl;
  
  temp.Amnesia( );
  
  sks.clear( );
  
  sks = temp.Skills( );
  
  cout << "SKILLS: ";
  
  for(int i = 0; i < sks.size( ); i++)
    cout << sks[i] << " ";
  
  cout << "ADD SKILL(balance): " << temp.AddSkill("balance") << endl;
  
  cout << "ADD SKILL(Concentration): " << temp.AddSkill("Concentration") << endl;
  
  cout << "ADD SKILL(HeaL): " << temp.AddSkill("HeaL") << endl;
  
  cout << "ADD SKILL(JuMp): " << temp.AddSkill("JuMp") << endl;
  
  sks.clear( );
  
  sks = temp.Skills( );
  
  cout << "SKILLS: ";
  
  for(int i = 0; i < sks.size( ); i++)
    cout << sks[i] << " ";
  
  cout << endl << "ADDSKILL(bogus): " << temp.AddSkill("bogus") << endl;
  
  cout << "SKILLS: ";
  
  for(int i = 0; i < sks.size( ); i++)
    cout << sks[i] << " ";
  
  cout << endl << "AMNESIA" << endl;
  
  temp.Amnesia( );
  
  cout << "ADD SKILL(balance): " << temp.AddSkill("balance") << endl;
  
  cout << "ADD SKILL(Concentration): " << temp.AddSkill("Concentration") << endl;
  
  cout << "ADD SKILL(HeaL): " << temp.AddSkill("HeaL") << endl;
  
  cout << "ADD SKILL(JuMp): " << temp.AddSkill("JuMp") << endl;
  
  cout << "ADD SKILL(open LOCK): " << temp.AddSkill("open LOCK") << endl;
  
  sks.clear( );
  
  sks = temp.Skills( );
  
  cout << "SKILLS: ";
  
  for(int i = 0; i < sks.size( ); i++)
    cout << sks[i] << " ";
  
  cout << endl;
  
  cout << "SKILL CHECK(balance): " << temp.SkillCheck("balance") << endl;
  
  cout << "SKILL CHECK(concentration): " << temp.SkillCheck("concentration") << endl;
  
  cout << "SKILL CHECK(heal): " << temp.SkillCheck("heal") << endl;
  
  cout << "SKILL CHECK(jump): " << temp.SkillCheck("jump") << endl;
  
  cout << "SKILL CHECK(open lock): " << temp.SkillCheck("open lock") << endl;
  
  cout << "SKILL CHECK(search): " << temp.SkillCheck("search") << endl;
  
  cout << string(15, '\n');
}
    
    
  
  
  
  
  
  
  
  
  