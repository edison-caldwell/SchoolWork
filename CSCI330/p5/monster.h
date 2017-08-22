//CSCI 330
//Fall 2015 (161)
//Program 3
//monster.h

#ifndef _MONSTERH
#define _MONSTERH

#include "cc.h"

class Monster: public CreatureClass
{
  public:
    
    void Write (ostream & stream) const;
    // Writes the creature to ostream
    // pre: stream must be open
    // post: creature is written to the output stream
     
 protected:
    
    Monster(string name);
    // parameterized constructor

    Monster(string name, const int ABIL_ADJ[], const int HIT_DIE[]);
    // parameterized constructor

    void InitAbilities(const int ABIL_ADJ[]);
    // Initialize abilties using preset values
    
    void InitHP(const int HIT_DIE[]);
    // Initialize the Health using the hit die provided
    // [0] - number of dice
    // [1] - faces of dice
    // [2] - modifier

    virtual Monster* Clone() const  = 0;

    virtual void StartPackage( ) =0;

    int AttackBonus(const int BASE_ATT_BONUS[]) const;        
    // Calculates the Attack bonus given the Base attack bonus constants
    
    int AttackRoll(const int ATT_BONUS[]) const;  
    // Calculates the Attack roll given the attack bonus constants
    
    int SavingThrow(int kind, const int SAVING_THROWS[]) const;
    // Calculates the saving throw given the svaing throw constants
    //   and the kind of saving throw it is
    
  private:
    Monster( );
    // default constructor
      
    // no data
};

#endif


