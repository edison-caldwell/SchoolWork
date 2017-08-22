#ifndef _TROLLH
#define _TROLLH

#include "Monster.h"

class Troll: public Monster
{
public:
  
  virtual Troll* Clone( ) const;
  
  Troll(string);
  
  virtual ~Troll( );
  
  virtual void Write(ostream&) const;
  
  virtual int AttackRoll( )const;
  
  virtual int SavingThrow(int)const;
  
protected:
  
  Troll( );
  
private:
  
  static const int ABL_ADJ[6];
  
  static const CreatureClass::DiceType HITDIE;
  
  static const int NUM_HP_ROLL; 
  
  static const int HP_MOD;
  
  static const int SAVETHROW[3];
  
  static const int ATTACK_BONUS[2];
  
  static const string INIT_WEAPON;
  
  static const string INIT_ARMOR;
  
  static const string INIT_SKILLS[];
  
  static const int SKILL_SIZE;
  
};

#endif