#ifndef _MONSTERH
#define _MONSTERH

#include "cc3.h"

class Monster: public CreatureClass
{
public:
  
  virtual ~Monster( );
  
  virtual  void Write(ostream&) const;
 
//    virtual EquipClass* FindEquipment(EquipClass*);
  
 
protected:
  
  Monster(string, const int[], const string[], const int);
  
private:
  
  Monster( );
  
};

#endif
  
