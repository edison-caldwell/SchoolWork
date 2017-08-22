#ifndef _ELFH
#define _ELFH

#include "Humanoid.h"

class Elf: public Humanoid
{
public:
  
  Elf(string, VocRules::VocType = VocRules::WIZ);
  
  virtual ~Elf( );
  
  virtual void Write(ostream&) const;
  
protected:
  
  Elf( );
  
private:
  
  static const int ABL_ADJ[6];
  
  static const VocRules::VocType DEF_VOC;
  
};

#endif