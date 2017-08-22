#ifndef _MONSTERH
#define _MONSTERH

#include "cc4.h"

class Monster: public CreatureClass
{
public:
  
  virtual Monster* Clone( ) const;
  
  virtual ~Monster( );
  
  virtual  void Write(ostream&) const;
  
  virtual int AttackRoll( ) const;
  
  virtual int SavingThrow(int) const;
  
 
//    virtual EquipClass* FindEquipment(EquipClass*);
  
 
protected:
  
  Monster(string, const int[], const string[], const int);
  
private:
  
  Monster( );
  
};

#endif
  
