//CSCI 330
//Fall 2015 (161)
//Program 3
//Implementation of CreatureClass to create a Creature
//    for the Quest for Elgeon Game


#ifndef _CREATURECLASS_H
#define _CREATURECLASS_H
#include "gamespace.h"
#include "dice.h"
#include "voc.h"
#include "wpn.h"
#include "armor.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using namespace GameSpace;


class CreatureClass
{
    public:
        enum AbilityType {DEX, CON, INT, CHA, STR, WIS};
        // enumerated for Abilities - used for indexing ability array
                

        // Relational operator that compares obj by non case-sensitive name
        // Pre : 
        // Post:value compares creature's name
        bool operator==(const CreatureClass & tempCreature) const;
        bool operator!=(const CreatureClass & tempCreature) const;
        bool operator<=(const CreatureClass & tempCreature) const;
        bool operator<(const CreatureClass & tempCreature) const;
        bool operator>=(const CreatureClass & tempCreature) const;
        bool operator>(const CreatureClass & tempCreature) const;

        virtual void Write(ostream& out) const;
        //The output stream will receive the creature data in the following format:
        //name#(row,col)#hp#[a1#a2#a3#a4#a5#a6]#(skills)#wpn#armor#
        //Pre : The related fields have been initialized
        //Post: The output stream contains the data

        string Name( ) const;
        //Returns the creatures name
        //Pre : 
        //Post: name is returned
        
        int Row( ) const;
        //Returns the creatures cell row
        //Pre : 
        //Post: the value of row is returned

        int Column( ) const;
        //Returns the creatures cell column
        //Pre : 
        //Post: the value of column is returned

        int HP( ) const;
        //Returns the creatures health points
        //Pre : 
        //Post: hp is returned

        int Ability(AbilityType ability ) const;
        //Returns the creatures specific ability based on in-parameter
        //Pre : a valid AbilityType is sent in
        //Post: an int value of that ability score is returned

        vector<int> Abilities( ) const;
        //Returns the ability vector
        //Pre :
        //Post: Vector of the abilities is returned
         
        vector<string> Skills( ) const;
        //Returns the vector of skills
        //Pre :
        //Post: Skill vector is returned

        bool Dead( ) const;
        //Returns true if creature is dead, false otherwise.
        //Pre : 
        //Post: True is returned if hp <= DEAD, false otherwise

        bool Dying( ) const;
        //Returns true if creature is dying, false otherwise.
        //Pre : 
        //Post: True is returned if DEAD<hp<DISABLED, false otherwise

        bool Disabled( ) const;
        //Returns true if creature is disabled, false otherwise.
        //Pre : 
        //Post: True is returned if hp <= DISABLED, false otherwise

        bool Active( ) const;
        // Returns true if creature is active (not disabled)
        // Pre :
        //Post: True if hp >DISABLED
        
        int AbilityMod (AbilityType ability) const;
        //Returns the calculated ability modifier 
        //Pre : A valid abilityType is sent in
        //Post: The calculated ability modifier is returned

        bool SetCell(int newRow, int newCol);
        //Set the current coordinates regardless of other fields.
        //coordinates are set (returns true) under following conditions:
	//  newRow and newCol not negative 
	//  newRow and newCol are both -1  (ex: -1,-1)
        //all other cases the function returns false.
        //Pre: It is up to the user to send valid moves based on the board
        //Post: The creatures coordinates are modified and true is returned
        //          otherwise false is returned

        int UpdateHP(int modification);
        //Updates the creatures HP by modification.
        //Negative modification will decrease HP and positive modification will increase HP.
        //The modified HP is returned.
        //Pre : 
        //Post: hp is updated by modification and the new hp is returned

        string Weapon( ) const;
        //Returns the name of the weapon
        
        string Armor( ) const;
        //Returns the name of the armor
        
        bool HasWeapon( ) const;
        //Returns true if creature has a current weapon
        
        bool HasArmor( ) const;
        //Returns true if creature has a current armor
        
        virtual EquipClass* FindEquipment(EquipClass *e);
        //Replaces the current equipment
	//Pre:
	//Post: Current equipment is replaced and replaced equipment
	//      is returned.  If e is NULL then no equipment is 
	// 	effected.
        
        EquipClass * LoseEquipment( );
        //Current equipment is lost, the equipment lost is returned
	//Pre:
	//Post: equipment is set to NULL and the equipment replaced is returned.

       WpnClass* LoseWeapon( );
        //Current weapon is lost, the weapon lost is returned

        ArmorClass* LoseArmor( );
        //Current armor is lost, the armor lost is returned


        bool AddSkill(string skill);
        //Adds a skill to the creatures list of skills
        
        int SkillCheck(string skill) const;
        //Returns the skill check value for a specific skill
        
        void Amnesia( );
        //Creature loses all the skills
        
        int InitiativeCheck( ) const;
        //Calculates the initiative check for a creature
        
        virtual int AttackRoll( ) const = 0;
	//Determines the AttackRoll value
        
        virtual int SavingThrow(int kind) const = 0;
	//Determines the savingthrow value
        
        int Defense( ) const;
	//Determines the Defensive value
        
        int Damage( ) const;
	//Determines the value for damages

        friend class Creature;
        
    protected:

        CreatureClass(string name);
        //Paramaterized Constructor
        //Pre : requires the name be sent in
        //Post: creature is constructed 

        virtual ~CreatureClass();
        //Destructor
        //Post: memory is deallocated

        CreatureClass(const CreatureClass& otherCreature);
        //Copy Constructor

        CreatureClass& operator= (const CreatureClass& otherCreature);
        //Overloaded assignment operator

        static const int NUM_ABILITIES=6;

        virtual CreatureClass *Clone( ) const = 0;
        
        void InitAbilities(const int startAbil[]);
        // Set the initial abilities using startAbil[]
        // pre:  initial abilities are rolled and saved in
        //	 startAbil[]
        // post: abilities have been initialized
        
        void InitHP(int startHP);
        // Sets the initial value for HP
        // pre:  hp has been rolled and sent in as startHP
        // post: hp has initial value of startHP

        int RollHitDie(int, int, int) const;
        //This will roll the hit die and add the appropriate values to the hp
        //Pre : The die class is available, hp has been initialized
        //Post: hp has been updated accordingly

    private:
        CreatureClass( );
        //Default Constructor

        void InitName(string name);
        // Sets the name after trimming
        
        static void LoadSkillTable( );
	// Loads the skill table from the file
	
        bool CheckSkill(string sk, int& ab) const;
        // Checks if the skill is valid

        void CopyIntoMe(const CreatureClass& c);
	// Copies all the fields in the class

//DATA MAMEBERS        
        string name;
        int row;
        int column;
        int hp;
        int ability[NUM_ABILITIES];

        WpnClass * wpn;
        ArmorClass * armor;
        vector<string> skills;

//CLASS DATA        
        static map<string,int> skillsTable;

// CLASS CONSTANTS
        static const int DISABLED;
        static const int DEAD;
        static const string DEF_NAME;

};

#endif // _CREATURECLASS_H

