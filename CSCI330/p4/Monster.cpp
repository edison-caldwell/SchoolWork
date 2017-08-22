#include "Monster.h"

Monster::Monster( ):
CreatureClass::CreatureClass("")
{
  
}

Monster::~Monster( )
{
  //cout << "MONSTER   DESTRUCTOR\n*******************\n";
}

Monster::Monster(string name, const int adjustments[], const string skills[], const int skillSize):
CreatureClass::CreatureClass(name)
{
  //cout << "MONSTER   CONST\n*******************\n";
  
  vector<string> skillvec;
  vector<int> abilityvec;
  
  for(int i = 0; i < skillSize; i++)
    skillvec.push_back(skills[i]);
  
  for(int i = 0; i < 6; i++)
    abilityvec.push_back(adjustments[i]);
  
  
  CreatureClass::InitAbilities(abilityvec);
  
  CreatureClass::InitSkills(skillvec); 
}


void Monster::Write(ostream& out) const
{
  
}



Monster* Monster::Clone( ) const
{
  return new Monster(*this);
}


int Monster::AttackRoll( ) const 
{}



int Monster::SavingThrow(int kind) const
{}








