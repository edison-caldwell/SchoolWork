#ifndef _CC3H
#define _CC3H

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include "voc.h"
#include "wpn.h"
#include "equip.h"
#include "armor.h"
#include "dice.h"




using namespace std;
using namespace GameSpace;

class SkillRules;

class CreatureClass{

public:
  
  enum DiceType{D4 = 4, D6 = 6, D8 = 8, D10 = 10, D12 = 12, D20 = 20};
  
  enum AbilityType{DEX /*DEXTERITY*/, CON /*CONSTITUTION*/, INT /*INTELLIGENCE*/, CHA /*CHARISMA*/, STR /*STRENGTH*/, WIS /*WISDOM*/};
  
  CreatureClass(const CreatureClass& c); //COPY CONSTRUCTOR
  
  virtual ~CreatureClass(); //DESTRUCTOR
  
  static SkillRules* skillRules;
  
  string Name( ) const;
  //RETURNS NAME
  //PRE: NAMEPTR EITHER POINTS TO NULL 
  //POST: VALUE NAMEPTR POINTS TO IS RETURNED
  
  
  int Row( ) const;
  //RETURNS ROW
  //PRE: ROW HOLDS A VALUE
  //POST: ROW IS RETURNED
  
  
  int Column( ) const;
  //RETURNS COLUMN
  //PRE: COLUMN HOLDS A VALUE
  //POST: COLUMN IS RETURNE
  
  
  int HP( ) const;
  //RETURNS HP AS AN INT
  //PRE: HP HOLDS A VALUE
  //POST:HP IS RETURNED
  
  
  int Ability(AbilityType ability) const;
  //RETURNS ABILITY SCORE INDEXED BY ABILITY TYPE
  //PRE: ABILITYSCORES HOLDS VALUES AND ABILITY IS AN ENUMERATED VALUE OF ABILITYTYPE
  //POST: ABILITYSCORES INDEXED BY ABILITY IS RETURNED
  
  
  int AbilityMod(AbilityType ability) const;
  //CALCULATES THE ABILITY MODIFIER
  //PRE: ABILITYSCORES HAS VALUES
  //POST: MOD IS RETURNED ROUNDED DOWN TO THE NEAREST WHOLE NUMBER
  
  
  string Weapon( ) const;
  //RETURNS WEAPONS NAME AS A STRING
  //PRE: WEAPON POINTS TO SOMETHING
  //POST: WEAPON NAME IS RETURNED
  
  
  string Armor( ) const;
  //RETURNS ARMOR NAME AS A STRING
  //PRE: ARMOR POINTS TO SOMETHING
  //POST: ARMOR NAME IS RETURNED
  
  
  
  vector<int> Abilities( ) const;
  
  
  vector<string> Skills( ) const;
  //RETURNS THE CREATURES SKILLS AS A VECTOR
  //PRE: SKILLS INITIALIZED
  //POST: VECTOR SKILLS RETURNED
  
  
  int SkillCheck(string skill);
  //SEARCHES FOR THE SKILL IN THE CREATURES' LIST OF USABLE SKILLS
  //IF FOUND, ROLL THE DICE FOR SKILLCHECK AND ADD THE MODIFIER
  //PRE: SKILL IS ALPHANUMERIC
  //POST: IF FOUND, RETURN THE ROLL PLUS THE ABILITY MOD
  
 
  bool Disabled( ) const;
  //COMPARES HEALTH TO ZERO
  //PRE: STATSCORES[HP] HAS A VALUE
  //POST: IF STATSCORES[HP] == ZERO RETURN TRUE, ELSE RETURN FALSE
  
 
  bool Dead( ) const;
  //CHECKS HEALTH TO BE LESS THAN -10 
  //PRE: HEALTH HAS A VALUE
  //POST: IF HEALTH IS LESS THAN -10 RETURN FALSE, ELSE RETURN TRUE
  
  
  bool Dying( ) const;
  //CHECKS HEALTH TO BE BETWEEN -1 AND 9
  //PRE: HEALTH HAS A VALUE
  //POST: IF HP IS BETWEEN -1 AND -9 RETURN TRUE, ELSE RETURN FALSE
  
  
  bool HasWeapon( ) const;
  //RETURNS A BOOLEAN. IF WEAPON IS NOT NULL RETURN TRUE, ELSE FALSE
  //PRE: NONE
  //POST: RETURN WEAPON
  
 
  bool HasArmor( ) const;
  //RETURNS A BOOLEAN. IF ARMOR IS NOT NULL RETURN TRUE, ELSE FALSE
  //PRE: NONE
  //POST: RETURN ARMOR
  
 
  bool SetCell(int newRow, int newCol);
  //CHANGES THE ROW AND COLUMN OF THE OBJECT
  //PRE:NEWROW AND NEWCOLUMN HAVE VALUES
  //POST: IF NEWROW AND NEWCOLUMN == NEG1 RETURN TRUE,  IF BOTH ARE > NEG1 RETURN TRUE,  ELSE RETURN FALSE
  
  
  int UpdateHP(int modification);
  //CHANGES THE HP RELIENT ON MODIFICATION
  //PRE: HP HAS A VALUE
  //POST: STATSCORES[HP] IS INCREASED OR DECREASED DEPENDING ON MODIFICATION
  
  
  EquipClass* LoseEquipment( );
  
  WpnClass* LoseWeapon( );
  
  ArmorClass* LoseArmor( );
  
  
  bool AddSkill(string skill);
  //ATTEMPTS TO ADD A SKILL TO THE CREATURES LIST OF SKILLS
  //IF SKILL IS VALID, ADD TO LIST. CAN ONLY OCCUR IF THE CREATURES HEALTH IS GREATER THAN -10
  //PRE: SKILLTABLE INITIALIZED. SKILL IS ALPHANUMERIC
  //POST: IF FOUND AND NOT ALREADY IN THE LIST, ADD TO LIST AND RETURN TRUE. ELSE RETURN FALSE.
  
  
  void Amnesia( );
  //DELETES CREATURES SKILLS
  //PRE: NONE
  //POST: ALL SKILL DELETED
  
  
  virtual EquipClass* FindEquipment(EquipClass * requip);
  
  
  int InitiativeCheck( ) const;
  
  
  virtual int AttackRoll( )const = 0;
  
  
  virtual int SavingThrow(int kind)const = 0;
  
  
  int Defense( ) const;
  
  
  int Damage( ) const;
  
  
  virtual void Write(ostream&) const;
  //OUTPUTS ALL VALUES OF OBJECT
  //PRE: OBJECT EXISTS
  //POST: ALL VALUES OUTPUT TO SCREEN DELIMINATED BY '#'
  
  
  CreatureClass& operator=(const CreatureClass& c);
  //ASSIGNS RIGHT OBJECT TO LEFT
  //PRE: RIGHT OBJECT EXISTS AND HOLDS VALUES
  //POST: DATA IN LEFT OBJECT IS OVERWRITTEN AND BOTH OBJECTS NOW HOLD THE SAME VALUES
  
  
  bool operator==(const CreatureClass& );
  ///COMPARES RIGHT OBJECT TO LEFT
  //PRE: RIGHT HAS A VALUE FOR NAMEPTR
  //POST: IF NAMEPTR AND RIGHT.NAMEPTR ARE THE SAME THING RETURN TRUE,  ELSE FALSE
  
  
  bool operator!=(const CreatureClass& );
  //COMPARES RIGHT AND LEFT OBJECT BY NAME
  //PRE: RIGHT HAS A VALUE FOR NAMEPTR
  //POST: IF NAMEPTR AND RIGHT.NAMEPTR ARE THE SAME THING RETURN TRUE,  ELSE FALSE
  
  
  bool operator<(const CreatureClass& c);
  //CHECKS THE CREATURES NAMES. IF LEFT IS GREATER THAN RIGHT RETURN TRUE, ELSE FALSE
  //PRE: BOTH CREATURES BEING COMPARED HAVE NAMES
  //POST: IF LEFT IS GREATER THAN RIGHT RETURN TRUE, ELSE FALSE
  
  
  bool operator<=(const CreatureClass& c);
  //CHECKS THE CREATURES NAMES. IF LEFT IS GREATER THAN OR EQUAL TO RIGHT RETURN TRUE, ELSE FALSE
  //PRE: BOTH CREATURES BEING COMPARED HAVE NAMES
  //POST: IF LEFT IS GREATER THAN OR EQUAL TO  RIGHT RETURN TRUE, ELSE FALSE
  
  
  bool operator>(const CreatureClass& c);
  //CHECKS THE CREATURES NAMES. IF LEFT IS LESS THAN RIGHT RETURN TRUE, ELSE FALSE
  //PRE: BOTH CREATURES BEING COMPARED HAVE NAMES
  //POST: IF LEFT IS LESS THAN RIGHT RETURN TRUE, ELSE FALSE
  
  
  bool operator>=(const CreatureClass& c);
  //CHECKS THE CREATURES NAMES. IF LEFT IS LESS THAN OR EQUAL TO RIGHT RETURN TRUE, ELSE FALSE
  //PRE: BOTH CREATURES BEING COMPARED HAVE NAMES
  //POST: IF LEFT IS LESS THAN OR EQUAL TO RIGHT RETURN TRUE, ELSE FALSE


  bool Active( )const;
  
  
protected:
  
  CreatureClass(string name);
  //parameterized constructor (name, race, voc)
  //PRE: PARAMETERS ARE CORRECT TYPES
  //POST: OBJECT INSTANTIATED WITH PARAMETERIZED VALUES. IF RACE IS NOT PARAMETERIZED, RACE AND VOC ARE DEFAULTED.
  //IF ONLY VOC IS NOT PARAMETERIZED
  
  
  void InitSkills(vector<string> setSkill);
  
  
  void InitAbilities(vector<int> setAbility);
   
 
  //Rovoid InitEquipment( );
  
  
 
  int RollHP(int numRolls, DiceType faces, int mod = 0);
  
  
  static void LoadSkillRules( );
  
  void WriteSkills(ostream&) const;
  
  void WriteAbilityScores(ostream&) const;
  
  WpnClass* weapon;
  
  ArmorClass* armor;
  
  
private:
  
  CreatureClass( );
  
  void DefaultName( );

  
  string PtrToStr(const CreatureClass& c) const;
  
  
  static void ReadSkills( );
  
  //**********VARIABLES**********
  
  char* namePtr;
  
  
  vector<int> abilityScores;
 
  
  vector<string> skills;
 
  
  int hp;
  
  
  int row;
  
  
  int col;

  static bool skillRead;
  
  static const int DISABLED;
 
 
  static const int DEAD;
  
  
  static const int DEF_NAME_LEN;
  
  
  static const string DEF_NAME;
};

#endif
