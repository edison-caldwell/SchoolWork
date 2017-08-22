// creature.h

#ifndef _MYCREATUREH
#define _MYCREATUREH

#include "p4.h"

class Creature
{
  public:

  	enum RaceType  {HUMAN, ELF, HALFELF, ORC, TROLL, OGRE};
	// enumerator for construction of creature
    
        static const RaceType DEFAULT_RACE = HUMAN;
	// default race for construction
        
	static RaceType StrToRace(string s);
	// Convert string to a race type
	// pre:  s must have string
	// post: return race type based on string

	static string RaceToStr( RaceType s);
	// Converts s to a string
	// pre:  s must have a RaceType value
	// post: return value of matching string

// CONSTRUCTORS
	Creature( );
	
	Creature(string name, RaceType race=DEFAULT_RACE, VocRules::VocType voc=VocRules::NNE);
	
	Creature(const Creature& c);

	Creature(CreatureClass * ptr);
	
// DESTRUCTOR	
	~Creature( ) ;
	
// ASSIGNMENT OP		
	Creature& operator=(const Creature & c);

// PUBLIC METHODS

    	string Name( ) const;
    	// Returns the name of the character
    	// pre: none  
    	// post: returns name 

    	string Voc( ) const;
    	// returns the vocation
    	// pre:  none.
    	// post: returns the vocation as a string

    	string Race( ) const;
    	// returns the race
    	// pre:  none.
    	// post: returns the race as a string
    
    	int GP( ) const;
    	// Returns the GP (Gold pieces)
    	// pre:  none.
    	// post: returns the GP

     	int HP( ) const;
    	// Returns the HP (hit points)
    	// pre:  none
    	// post: returns the HP 
     
    	int XP( ) const;
    	// returns the xp (experience points)
    	// pre:  none.
    	// post: returns the xp

    	int Level( ) const;
    	// returns the level
    	// pre:  none.
    	// post: returns the level

    	int Row( ) const;
    	// returns the row
    	// pre: none
    	// post: returns the row
    	
    	int Column( ) const;
    	// returns the column
    	// pre: none
    	// post: returns the column
    	
    	int Ability(int ability ) const;
    	// Returns the ability requested
    	// pre:  none.
    	// post: returns the ability value

    	vector<int> Abilities( ) const;
    	// Returns the abilities
    	// pre:  none.
    	// post: returns the abilities
    
    	string Weapon( ) const;
    	// Returns the current wpn, empty string if non exists
    	// pre:  none.
    	// post: returns the current weapon being used
     
    	string Armor( ) const;
    	// returns the current Armor, empty string if non exists
    	// pre:  none.
    	// post: returns the current armor being "worn"
     
        bool HasWeapon( ) const;
        // returns true if creature has a weapon
        // pre: none
        // post: returns true if creature has a weapon
        
        bool HasArmor( ) const;
        // returns true if creature has armor
        // pre: none
        // post: returns true if creature has armor

    	vector<string> Pack( ) const;
    	// returns the list of equipment in the pack
    	// pre:  array of strings must be large enough
    	// post: returns the list of equipment in pack

    	vector<string> EquipInventory( ) const;
    	// returns the list of equipment
    	// pre:  array of strings must be large enough
    	// post: returns the list of equipment 

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
        //Post: True is returned if DEAD<hp<DISABLED, false otherwis

        bool Disabled( ) const;
        //Returns true if creature is disabled, false otherwise.
        //Pre :
        //Post: True is returned if hp <= DISABLED, false otherwise

        bool Active( ) const;
        // Returns true if creature is active (not disabled)
        // Pre :
        //Post: True if hp >DISABLED
        
        bool IsHumanoid( ) const;
        // returns true if creature is Humanoid
        
        bool IsMonster( ) const;
        // returns true if creature is Monster

	int UpdateHP(int val);
	// Updates the HP given val
	
	int UpdateGP(int val);
    	// Updates the GP given val (GP will always be >=0)
    	
    	int UpdateXP(int val);
    	// Updates the xp (experience points) with the val
    	//  (XP will always be >=0)
    	// pre: val has a value
    	// post: xp is updated xp = xp + val

        bool SetCell(int newRow, int newCol);
        //Set the current coordinates regardless of other fields.
        //coordinates are set (returns true) under following conditi
        //  newRow and newCol not negative
        //  newRow and newCol are both -1  (ex: -1,-1)
        //all other cases the function returns false.
        //Pre: It is up to the user to send valid moves based on the
        //Post: The creatures coordinates are modified and true is r
        //          otherwise false is returned

        
        WpnClass* LoseWeapon( );
        // The creature loses the current wpn
        // pre: none
        // post: creatures current wpn is returned and the current wpn
        //           creature is carrying is none.
        
        ArmorClass* LoseArmor( );
        // The creature loses the current armor
        // pre: none
        // post: creatures current wpn is returned and the current armor
        //           creature is wearing is none.
        
        EquipClass* FindEquipment( EquipClass* equip);
        // Creature finds equipment and replaces old equipment
        // pre: none
        // post: if creature is active then creature will replace 
        //   current equipment with equip.  If creature has pack then 
        //   the old current equipment is put in pack.  If not pack
        //   then old equipment is returned.
        //   if creature is not active then equip is returned untouched.
        
	bool ChangeEquipment(string equipName);
	// Creature should change the current equipment with equipName
	// equipment is pack.
	// pre: none
	// post: if creature is active and creature has the equipName
	//  in equipment inventory then current equipment is put in pack
	//  and current equipment is equipName.
	//  if active and successful true is returned
	//  otherwise false is returned
	
	EquipClass* BuyEquipment(EquipClass* equip);
	// Creature is offered equipment to buy
	// pre: none
	// post: if creature is active and has enough gp then
	//  creature can purchase the equip.  It becomes current equipment
	//  and null is returned.
	//  if not active or not enough GP then equip is returned untouched.
	
	EquipClass* SellEquipment(string equipName);
	// Creature has a chance to sell equipment named equipName
	// pre: none
	// post: if creature is active and owns the equipment equipname, 
	//  then it is returned.
	//  if not active or doesn't own the equipment then null is returned
	
   	bool AddSkill(string skill);
   	// Creature aquires a new skill
   	// pre: none
   	// post: If creature is active then new skill is added to the
   	//  skill list and true is returned
   	
	int SkillCheck(string skill) const;
	// Returns the skill check value for the skill
	// pre: none
	// post: if creature not dead then skill check value returned

   	void Amnesia( );
   	// Creature hit head and lost all knowledge of skills
   	// pre: none
   	// post: creature has no skill list
             
        int InitiativeCheck( ) const;
        //Calculates the initiative check for a creature

        int AttackRoll( ) const;
        //Determines the AttackRoll value

        int SavingThrow(int kind) const;
        //Determines the savingthrow value

        int Defense( ) const;
        //Determines the Defensive value

        int Damage( ) const;
        //Determines the value for damages     
	  
    	void Write(ostream& stream) const;
    	// Writes the creature data to an output stream
    	// pre:  stream must be open, headers already printed
    	//       if necessary.
    	// post: all member data in creature object has been inserted
    	//       into output stream.

	int VocInt( ) const;
	// returns the enum value for vocation

	int RaceInt( ) const;
	// returns the enum value for race

        // Relational Operators	  
	bool operator==(const Creature& c) const; 
	bool operator!=(const Creature& c) const;
	bool operator<(const Creature& c) const; 
	bool operator<=(const Creature& c) const;
	bool operator>(const Creature& c) const; 
	bool operator>=(const Creature& c) const;

    private:

	
	CreatureClass * Create(string name, Creature::RaceType race,
	                        VocRules::VocType voc);
	// Creates the creature - used for construction
	                        	
	void CopyIntoMe(const Creature &c);
	// Copies creature "c" into self
	// used for copy constructor and op=

// DATA	
	CreatureClass *p;
};

#endif


