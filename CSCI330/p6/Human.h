#ifndef _HUMANH
#define _HUMANH

#include "Humanoid.h"

class Human: public Humanoid
{
public:
  
  virtual Human* Clone( ) const;
  
  Human(string, VocRules::VocType voc_type = VocRules::FTR);
  
  virtual ~Human( );
  
  virtual void Write(ostream&) const;
  
protected:
  
  Human( );
  
private:
  
  static const int ABL_ADJ[6];
  
  static const VocRules::VocType DEF_VOC;
  
};

#endif