#include "Troll.h"

//***STATIC VARIABLES***//

const int Troll::ABL_ADJ[6] = {14, 23, 6, 6, 23, 9}; //DEX CON INT CHA STR WIS

const CreatureClass::DiceType Troll::HITDIE = D8;

const int Troll::NUM_HP_ROLL = 6;

const int Troll::HP_MOD = 36;

//const int Troll::SAVETHROW[3]; //**** still needs values ****

//const int Troll::ATTACK_BONUS[2]; //**** still needs values ****

const string Troll::INIT_WEAPON = "CLUB";

const string Troll::INIT_ARMOR = "THICK SKIN";

const string Troll::INIT_SKILLS[2] = {"LISTEN", "SPOT"};

const int Troll::SKILL_SIZE = 2;



//***CONSTRUCTORS***//

Troll::Troll(string name):
Monster::Monster(name, ABL_ADJ,  INIT_SKILLS, SKILL_SIZE)
{
  //cout << "TROLL     CONST \n*******************\n";
  
  CreatureClass::UpdateHP(CreatureClass::RollHP(NUM_HP_ROLL, HITDIE, HP_MOD));
}

Troll::~Troll( )
{
  //cout << "\nTROLL     DESTRUCTOR\n*******************\n";
}

//***OBSERVERS***//

void Troll::Write(ostream& out) const
{ 
  out << "TROLL#";
  
  CreatureClass::Write(out);
}

//++++++++++++++//

int Troll::AttackRoll( )const 
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
	temp += CreatureClass::AbilityMod(CreatureClass::STR) + 9;
    }
    else
      temp += CreatureClass::AbilityMod(CreatureClass::STR);
  }
  
  if(temp < 0)
    temp = 0;
  
  return temp;
}


int Troll::SavingThrow(int type)const 
{
  int lastgrace = 0;
  
  if(CreatureClass::Active( ))
  {   
    lastgrace += Dice::Roll(CreatureClass::Name( ), GameSpace::SVTH, 1, D20);
    
    if(type == VocRules::FORT)
      lastgrace += AbilityMod(CreatureClass::CON) + 11;
    else if(static_cast<VocRules::SavingThrowType>(type) == VocRules::REFLEX)
      lastgrace += AbilityMod(CreatureClass::DEX) + 4;
    else if(static_cast<VocRules::SavingThrowType>(type) == VocRules::WILL)
      lastgrace += AbilityMod(CreatureClass::WIS) + 3;
  }
  
  return lastgrace;   
}

Troll* Troll::Clone( ) const
{
  return new Troll(*this);
}