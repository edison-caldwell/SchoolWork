// voc.h

#ifndef _VOCH
#define _VOCH

#include <iostream>
#include <fstream>
#include <string>
#include "gamespace.h"

using namespace std;
using namespace GameSpace;

class VocRules
{
  public:
    enum VocType {NNE, BBN, CLR, FTR, ROG, WIZ};
    // Datatype for describing the vocations
    // Barbarian:BBN, Cleric:CLR, Fighter:FTR, Rogue:ROG, Wizard:WIZ
    
    static VocType StrToVoc(string s);
    // Convert string to a voc type
    // pre:  s must have string
    // post: return voc type based on string

    static string VocToStr( VocType s);
    // Converts s to a string
    // pre:  s must have a VocType value
    // post: return value of matching string

    enum SavingThrowType {FORT=1, REFLEX, WILL};
    // Datatype for describing the saving throws
    // Fortitude:FORT, Reflex: REFLEX, Will:WILL
    
    static const int VOC_MAX = 6;
    // Number of different vocations
    
    static const int LEVEL_MAX = 20;
    // Number of levels for each vocation
        
    static VocRules* GetVocRules( );
    // Creates the single VocRules instance (singleton)
    // pre:  none
    // post: a pointer to the instance is returned

    static void DeleteVocRules( );    
    // Deletes the instance of VocRules
    // pre: none
    // post: instance has been deleted
     
    ~VocRules( ); //destructor
    
    int BaseAttackBonus(VocType v, int level) const;
    // Looks up and returns the BaseAttackBonus for a vocation and level
    // pre: level must be between 1 and 20
    // post: returns the attack bonus
    
    int BaseSaveBonus(VocType v, int level, SavingThrowType r) const;
    // Looks up the base saving throw bonus
    // pre: level must be between 1 and 20
    // post: returns base saving throw bonus
    
    int HitDie(VocType v) const;
    // Looks up the hit die for a specific vocation
    // pre:  v has the vocation
    // post: returns the hit die (number of sided die to use)
    
  private:
    static VocRules* vr;                   // pointer to the singleton
//    static const string VOCRULES_FILENAME; // filename for vocrules    
    static const int RULE_MAX = 4;         // rules in voc rules
    static const int BASE_ATTACK_BONUS;    //Index for base_attack_bonus


    VocRules( );
    // Creates the table by loading from file
     
    int table[VOC_MAX][LEVEL_MAX+1][RULE_MAX];   // table for the rules
    int hitdie[VOC_MAX]; // table for the hitdie     
};


#endif




