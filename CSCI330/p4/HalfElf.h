#ifndef _HALFELFH
#define _HALFELFH

#include "Humanoid.h"

class HalfElf: public Humanoid
{
public:
  
  virtual HalfElf* Clone( ) const;
  
  HalfElf(string, VocRules::VocType = VocRules::ROG);
  
  virtual ~HalfElf( );
  
  virtual void Write(ostream&) const;
  
protected:
  
  HalfElf( );
  
private:
  
  static const int ABL_ADJ[6];
  
  static const VocRules::VocType DEF_VOC;
  
};

#endif