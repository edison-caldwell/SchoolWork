//CSCI 330
//Fall 2015 (161)
//Program 3
// troll.h

#ifndef _TROLLH
#define _TROLLH

#include "monster.h"

class Troll:public Monster
{
  public:
    Troll(string n);
    // Constructor - must provide name of creature
    
    virtual int AttackRoll( ) const;
    // Calculates the attack roll 
    // pre: none
    // post: the attack roll value is returned
    
    virtual int SavingThrow(int kind) const;
    // Calculate the saving throw value based on the kind of S.T.
    // pre: none
    // post: the saving throw value is returned
    
    void Write(ostream& stream) const;
    // Write the creature to ostream
    // pre: out must be open
    // post: the creature is written to the ostream
    
  protected: 
    virtual Troll *Clone( ) const;     
  
  
  private:
    Troll( );  // default constructor

    virtual void StartPackage( );
    // starter package initialization for the creature
    // pre: none
    // post: starter pack has been initialized
    
    static const string RACE;
    static const int ABIL_ADJ[6];
    static const int HIT_DIE[3];// rolls=0, faces=1, modifier=2
    static const int SAVING_THROWS[4];
    static const int BASE_ATT_BONUS[2]; // MELEE = 0; RANGE = 1
    static const string INIT_WPN;
    static const string INIT_ARMOR;
    static const int NUM_INIT_SKILLS=2;
    static const string INIT_SKILLS[NUM_INIT_SKILLS];
    
};


#endif



