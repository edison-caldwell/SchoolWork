#ifndef _HANDLE4H
#define _HANDLE4H

#include "p4.h"
#include <typeinfo>

class Creature{
  
public:
  
  enum RaceType{HUMAN, ELF, HALFELF, ORC, TROLL, OGRE};
  
  //CONSTRUCTORS
  
  Creature(string, RaceType inRace=HUMAN, VocRules::VocType voc=VocRules::NNE);
  Creature(const Creature&);
  Creature(CreatureClass* ptr);
  ~Creature( );
  
  //OVERLOADED OPS
  bool operator==(const Creature&) const;
  bool operator!=(const Creature&) const;
  bool operator<(const Creature&) const;
  bool operator>(const Creature&) const;
  bool operator<=(const Creature&) const;
  bool operator>=(const Creature&) const;
  Creature& operator=(const Creature&);
  
  //CREATURE METHODS
  static RaceType StrToRace(string);
  static string RaceToStr(int);
  string Race( ) const;
  int VocInt( ) const;
  int RaceInt( ) const;
  bool IsHumanoid( ) const;
  bool IsMonster( ) const;
  
  //CREATURE HELPER-METHODS
  bool ValidRace(RaceType);
  CreatureClass* InitCreature(string, VocRules::VocType);
  void Copy(const Creature& c);
  
  
  //CREATURECLASS HANDLES
  string Name( ) const;/**********************************Returns the creatures name as a string.************/
  
  
  
  int Row( ) const;/**************************************Returns the creatures current row as an int.*******/
  
  
  
  int Column( ) const;/***********************************Returns the creatures current column as an int.****/
  
  
  
  int HP( ) const;/***************************************Returns the creatures current health as an int.****/
  
  
  
  int Ability(CreatureClass::AbilityType ability) const;/*Returns the ability score for a specific ability.*/
  
  
  
  string Weapon( ) const;/********************************Returns creatures held weapon as a string.********/
  
  
  
  string Armor( ) const;				//Returns creatures worn armor as a string.
  
  
  
  vector<int> Abilities( ) const;			//Returns creatures abilities as a vector of ints.
  
  
  
  int SkillCheck(string skill) const;			//Returns calculated skill check for a specific skill.
  
  
  
  vector<string> Skills( ) const;			//Returns the creatures skills as a vector of strings
  
  
  
  bool Disabled( ) const;				//If hp zero or less return true.
  
  
  
  bool Dying( ) const;					//If hp is between -10 and 0 return true.
  
  
  
  bool Dead( ) const;					//If hp is less than -10 return true.
  
  
  
  bool Active( ) const;					//If creature is not dead, dying, or disabled return true.
  
  
  
  bool HasWeapon( ) const;				//If holding a weapon return true.
  
  
  
  bool HasArmor( ) const;				//If wearing armor return true.
  
  
  
  bool SetCell(int newRow, int newCol);			//If both parameters are -1 or both greater than -1 return true.
							//Creatures position on the board is updated.
  
  
  
  int UpdateHP(int mod);				//Updates the HP buy the modification ammount.
  
  
  
  //EquipClass* LoseEquipment( );			//IGNORE.
  
  
  
  WpnClass* LoseWeapon( );				//Creature loses its weapon, weapon is returned to client.
  
  
  
  ArmorClass* LoseArmor( );				//Creature loses its armor, armor is returned to client.
  
  
  
  bool AddSkill(string skill);				//Checks if parameter is a valid skill, if it is add to creatures list
							//of available skills and return true.
  
  
  
  void Amnesia( );					//Creature forgets all known skills. Bummer!
  
  
  
  EquipClass* FindEquipment(EquipClass* requip);	//Creature finds a new piece of eqiupment and equips it, putting the
							//worn/held item into their pack.
  
  
  
  int InitiativeCheck( ) const;				//Rolls for initiative. Creature must be active else a zero is returned.
  
  
  
  int AttackRoll( ) const;				//Rolls for attack. Creature must be active else a zero is returned.
  
  
  
  int SavingThrow(int kind) const;			//Rolls for saving throw. Valid "kinds" are; FORT(1), REFLEX(0), and
							//WILL(2).
  
  
  
  int Defense( ) const;					//Returns the creatures calculated defense based on a constant bonus(10),
							//amor bonus, and a DEX ability mod.
  
  
  
  int Damage( ) const;					//Returns the creatures calculated damage based on weapon damage and
							//an ability mod depending on weapon type (DEX for ranged, STR for melee).
  
  
  
  void Write(ostream&) const;				//Writes all available information about the creature.
  
  
  
  //HUMANOID-ONLY***** HANDLES
  string Voc( )const;					//Return creatures vocation as a string.
  
  
  
  int Level( ) const;					//Return creatures level as an int.
  
  
  
  int GP( ) const;					//Return creatures gp as an int.
  
  
  
  int XP( ) const;					//Return creatures xp as an int.
  
  
  
  vector<string> Pack( ) const;				//Return creatures pack as a vector of strings.
  
  
  
  vector<string> EquipInventory( ) const;		//Return all creatures equipment as a vector of strings.
  
  
  
  bool ChangeEquipment(string requip);			//Changes the creatures equipment with something in the pack.
  
  
  
  EquipClass* BuyEquipment(EquipClass*);		//Buy equipment and lower gp buy the price. Replaced equip added to pack.
  
  
  
  EquipClass* SellEquipment(string);			//Sells creatures equipment. First checks pack then held items.
  
  
  
  int UpdateGP(int mod);				//Update the GP buy an ammount, cannot drop below zero.
  
  
  
  int UpdateXP(int mod);				//Updates the XP by an ammount. Can only be positive.

  
private:
  Creature( );
  
  RaceType race;
  
  CreatureClass* handle;
};

#endif
