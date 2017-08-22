#ifndef _ORCH
#define _ORCH

#include "Humanoid.h"

class Orc: public Humanoid
{
public:
  
  Orc(string, VocRules::VocType = VocRules::BBN);
  
  virtual ~Orc( );
  
  virtual void Write(ostream&) const;
 
protected:
  
  Orc( );
  
private:
  
  static const int ABL_ADJ[6];
  
  static const VocRules::VocType DEF_VOC;
  
};

#endif