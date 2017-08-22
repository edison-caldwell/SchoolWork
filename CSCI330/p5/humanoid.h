//CSCI 330
//Fall 2015 (161)
//Program 3
//Implementation of CreatureClass to create a Creature
//    for the Quest for Elgeon Game


#ifndef _HUMANOIDH
#define _HUMANOIDH

#include "cc.h"
#include "voc.h"
#include "gamespace.h"
#include "dice.h"


class Humanoid:public CreatureClass
{
  public:
  
     virtual ~Humanoid( );
     //destructor

//********************************************* Basic Observers
     
     string Voc( ) const;
     // returns the vocation
     // pre:  none.
     // post: returns the vocation as a string

     int Level( ) const;
     // returns the level
     // pre:  none.
     // post: returns the level
     
     int GP( ) const;
     // returns the Gp (gold points)
     // pre:  none.
     // post: returns the gp
     
     int XP( ) const;
     // returns the xp (experience points)
     // pre:  none.
     // post: returns the xp
     
     vector<string> Pack( ) const;
     //Return a list of equipment in the pack
     
     vector<string> EquipInventory( ) const;
     //Return a list of all equipment including current equipment

     void Write(ostream& stream) const;
     // Write the data to stream
     // pre: stream must be open
     // post: Creature is written to ostream
     
//********************************************* Combat

     virtual int AttackRoll( ) const;
     // Rolls the dice and calculates the attack roll
     // pre:
     // post: returns the attack roll value
     
     virtual int SavingThrow(int kind) const;
     // Calculates the saving throw for a character
     // pre:
     // post: return the calculated value for saving throw

     int UpdateGP(int val);
     // Updates the gp (gp points) with the val
     // pre: val has a value
     // post: xp is updated gp = gp + val
       
     int UpdateXP(int val);
     // Updates the xp (experience points) with the val
     // pre: val has a value
     // post: xp is updated xp = xp + val
     
//********************************************* Equipment
     
     virtual EquipClass *FindEquipment(EquipClass * e);
     //Place current equipment in pack and replace current
     //equipment with the found equipment
     //Pre:
     //Post: equipment replaces the current equipment and the current 
     //  equipment is placed in the pack and NULL is returned.
     //  if equipment cannot be found then the equipment is returned.

     bool ChangeEquipment(string equipment);
     //Find equipment in pack and swap with current equipment
     //Pre:
     //Post: if equipment is in pack and swapped then true is returned
     //      else false is returned
          
     EquipClass* BuyEquipment(EquipClass* e);
     // if there is enough GP then the current equipment is placed 
     // in the pack, the equipment is purchased
     //   GP is decreased
     // pre:  
     // post: if equipment is purchased then NULL is returned and
     //   new equipment is current equipment.
     //   if equipment is not purchased then the equipment is returned 
     
     EquipClass* SellEquipment(string equipment);
     // if the equipment is in inventory then
     //	  the equipment is sold and GP is increased
     // pre:  equipment is the name of equipment
     // post: if no equipment is sold then NULL is returned
     //   if equipment is sold then equipment is returned
     //   could leave current equipment as NULL 
     
     Humanoid & operator=(const Humanoid& h);
     // assignment operator
     
     
  protected:


     Humanoid(string name, VocRules::VocType voc, 
              const VocRules::VocType DEF_VOC, const int ABIL_ADJ[]);
     // parameterized const
     // constants for the Default Voc and Ability Adjustments provided
     // by derived class
     
     Humanoid(const Humanoid & h );
     // copy constructor
  
  
     virtual Humanoid * Clone( ) const = 0;

     virtual void StartPackage( ) = 0;
    
     void InitAbilities(const int ABIL_ADJ[]);  
     // initializes the abilities based on the ABIL_ADJ and dice roll
     // pre:  none.
     // post: rolls the dice to initialize the abilities applying
     //        ability adjustments

     void InitVoc(VocRules::VocType v, const VocRules::VocType DEF_VOC );
     // initializes the vocation to v
     //  if v invalid then vocation is set to DEF_VOC
     // pre:  none.
     // post: vocation has valid value

     void InitLevel();
     // initializes the level
     // pre:  none.
     // post:  initialization done

     void InitXP( );
     // initializes the xp
     // pre:  none.
     // post:  initialization done
        
     void InitGP( );
     // initializes the gp
     // pre:  none.
     // post:  initialization done
        
     void InitHP( );
     // initializes the Hp
     // pre:  none.
     // post:  initialization done
        
     void InitPack(vector<string> initpack);
     // initializethe pack of weapons
    
     void InitSkills( );    
     // initialize the list of skills
    
     int HitDie( ) const;
     // Determine HitDie for the creature
     // pre: none
     // post: hit die value is returned

     EquipClass* FindAndRemoveFromPack(string equipName);
     // finds the equipment in the pack, 
     // removes the equipment and returns it
     // pre: 
     // post: returns equipment removed.
     //		if not found returns NULL
     
     EquipClass* SwapAndMoveToPack(EquipClass * e);
     // swaps the current equipment with e
     // stores old current in the pack
     // pre:
     // post: current equipment is now e (unless it is NULL)
     //        old current is in pack
    
private:
     Humanoid( );
     // default constructor

     void CopyIntoMe(const Humanoid & h);    
     // Deep copy of the humanoid data
    
     void EmptyPack();
     // Erases the entire pack deallocating each piece of equipment
    
     void CkPromotion( );
     // checks the xp for possible promotion to higher level
     // pre:  none.
     // post: character may have been promoted

     int AttackBonus( ) const;
     // Calculates the attack bonus
     // pre:  none.
     // post: returns the attack bonus after rolling dice

// DATA MEMBERS
    int level;		
    int gp;
    int xp;
    vector<EquipClass *> pack;
    VocRules::VocType voc;

// CLASS DATA
    static const int NUM_INIT_SK = 3;
    static const string INITSKILLS[VocRules::VOC_MAX][NUM_INIT_SK];
        
};



#endif



