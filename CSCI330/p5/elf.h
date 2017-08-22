// elf.h

#ifndef _ELFH
#define _ELFH

#include "humanoid.h"
#include "voc.h"

class Elf:public Humanoid
{
  public:

    Elf(string name, VocRules::VocType voc=VocRules::NNE);
    // Constructor - must have name of creature
    
    void Write(ostream& stream) const;  
    // Write the creature to ostream
    // pre: out must be open
    // post: creature is written to ostream
    
  protected:
    virtual Elf * Clone( ) const;
    
  
  private:
    Elf( ); // default constructor

    virtual void StartPackage( );
    // starter package initialization for the creature
    // pre: none
    // post: starter pack has been initialized

    static const int ABIL_ADJ[NUM_ABILITIES];
    static const VocRules::VocType DEFAULT_VOC;
    static const int NUM_INIT_PK=4;
    static const string INITPACK[VocRules::VOC_MAX][NUM_INIT_PK];                
    static const string RACE;
};

#endif



