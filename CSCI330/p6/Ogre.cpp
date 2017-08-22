#include "Ogre.h"

const int Ogre::ABL_ADJ[6] = {8, 15, 6, 7, 21, 10}; //DEX CON INT CHA STR WIS

const CreatureClass::DiceType Ogre::HITDIE = D8;

const int Ogre::NUM_HP_ROLL = 4;

const int Ogre::HP_MOD = 8;

const int Ogre::SAVETHROW[3] = {0, 0, 0}; //**** still needs values ****

const int Ogre::ATTACK_BONUS[2] = {0, 0}; //**** still needs values ****

const string Ogre::INIT_WEAPON = "SPEAR";

const string Ogre::INIT_ARMOR = "SPIKED BANDS";

const string Ogre::INIT_SKILLS[3] = {"INTIMIDATE", "LISTEN", "SPOT"};

const int Ogre::SKILL_SIZE = 3;



Ogre::Ogre(string name):
Monster(name, ABL_ADJ, INIT_SKILLS, SKILL_SIZE)
{
  //cout << "OGRE      CONST\n*******************\n";
  
  CreatureClass::UpdateHP(CreatureClass::RollHP(NUM_HP_ROLL, HITDIE, HP_MOD)); 
}



Ogre::~Ogre( )
{
  //cout << "\nOGRE      DESTRUCTOR\n*******************\n";
}



void Ogre::Write(ostream& out) const
{
  //   cout << "Ogre Write \n\n";
  
  out << "OGRE#";
  
  CreatureClass::Write(out);
  
}



int Ogre::AttackRoll( ) const
{
  int temp = 0;
  
  if(CreatureClass::Active( ))
  {
    temp = Dice::Roll(CreatureClass::Name( ), GameSpace::ATT, 1, CreatureClass::D20);
    
    if(weapon)
    {
      if(WpnClass::IsRange(weapon->Name( )))
	temp += CreatureClass::AbilityMod(CreatureClass::DEX) + 1;
      else
	temp += CreatureClass::AbilityMod(CreatureClass::STR) + 8;
    }
    else
      temp += CreatureClass::AbilityMod(CreatureClass::STR) + 8;
  }
  
  if(temp < 0)
    temp = 0;
  
  return temp;
}



int Ogre::SavingThrow(int type) const
{
  int lastgrace = 0;
  
  if(CreatureClass::Active( ))
  {  
    lastgrace += Dice::Roll(CreatureClass::Name( ), GameSpace::SVTH, 1, D20);
    
    if(type == VocRules::FORT)
      lastgrace += AbilityMod(CreatureClass::CON) + 6;
    else if(static_cast<VocRules::SavingThrowType>(type) == VocRules::REFLEX)
      lastgrace += AbilityMod(CreatureClass::DEX) + 0;
    else if(static_cast<VocRules::SavingThrowType>(type) == VocRules::WILL)
      lastgrace += AbilityMod(CreatureClass::WIS) + 1;
  }
  
  return lastgrace;   
}


Ogre* Ogre::Clone( ) const
{
  return new Ogre(*this);
}






