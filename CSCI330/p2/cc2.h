#ifndef _CC2H
#define _CC2H

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <fstream>
#include "voc.h"
#include "armor2.h"
#include "wpn2.h"
#include "dice.h"

using namespace std;
using namespace GameSpace;

class CreatureClass
{
public:
  
  enum RaceType{HUMAN, ELF, HALFELF, ORC, TROLL, OGRE, BAD};
  enum AbilityType{DEX /*DEXTERITY*/, CON /*CONSTITUTION*/, INT /*INTELLIGENCE*/, CHA /*CHARISMA*/, STR /*STRENGTH*/, WIS /*WISDOM*/};
  enum SavingThrowType{FORT = 1, REFLEX, WILL};
  enum StatType{row, column, hp, gp, level, xp};
  enum DiceType{D4, D6, D8, D10, D12, D20};
  
  
  //CONSTRUCTORS****************************************************************************
  
  CreatureClass(string name, RaceType race_type = HUMAN, VocRules::VocType voc_type = VocRules::NNE);
  //parameterized constructor (name, race, voc)
  //PRE: PARAMETERS ARE CORRECT TYPES
  //POST: OBJECT INSTANTIATED WITH PARAMETERIZED VALUES. IF RACE IS NOT PARAMETERIZED, RACE AND VOC ARE DEFAULTED.
  //IF ONLY VOC IS NOT PARAMETERIZED 
  
  CreatureClass(const CreatureClass& c); //COPY CONSTRUCTOR
  
  ~CreatureClass(); //DESTRUCTOR
  
  //GETTERS**********************************************************************************
  
  
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
  //POST: COLUMN IS RETURNED
  
  int Race( ) const;
  //RETURNS RACE AS AN INT
  //PRE:RACE HOLDS AN ENUMERATED VALUE
  //POST:RACE RETURNS AS AN INT
  
  int Voc( ) const;
  //RETURNS VOCATION AS AN INT
  //PRE: VOC HOLDS A VALUE
  //POST: VOC IS RETURNED
  
  int Level( ) const;
  //RETURNS LEVEL AS AN INT
  //PRE: LEVEL HOLDS A VALUE
  //POST: LEVEL IS RETURNED
  
  int HP( ) const;
  //RETURNS HP AS AN INT
  //PRE: HP HOLDS A VALUE
  //POST:HP IS RETURNED
  
  int XP( ) const;
  //RETURNS XP AS AN INT
  //PRE: XP HOLDS A VALUE
  //POST: XP IS RETURNED
  
  int GP( ) const;
  //RETURNS GP AS AN INT
  //PRE: GP HOLDS A VALUE
  //POST: GP IS RETURNED
  
  int Ability(AbilityType ability);
  //RETURNS ABILITY SCORE INDEXED BY ABILITY TYPE
  //PRE: ABILITYSCORES HOLDS VALUES AND ABILITY IS AN ENUMERATED VALUE OF ABILITYTYPE
  //POST: ABILITYSCORES INDEXED BY ABILITY IS RETURNED
  
  bool Humanoid( ) const;
  //TESTS IF CREATURE IS A HUMANOID
  //PRE:OBJECT HAS A RACE
  //POST: RETURN TRUE IF NOT A OGRE OR TROLL, ELSE RETURN FALSE
  
  bool Monster( ) const;
  //TESTS IF CREATURE IS A MONSTER
  //PRE: RACE HOLDS A VALUE
  //POST: IF RACE IS TROLL OR OGRE RETURN TRUE. ELSE RETURN FALSE
  
  bool Dying( ) const;
  //CHECKS HEALTH TO BE BETWEEN -1 AND 9
  //PRE: HEALTH HAS A VALUE
  //POST: IF HP IS BETWEEN -1 AND -9 RETURN TRUE, ELSE RETURN FALSE
  
  bool Dead( ) const;
  //CHECKS HEALTH TO BE LESS THAN -10 
  //PRE: HEALTH HAS A VALUE
  //POST: IF HEALTH IS LESS THAN -10 RETURN FALSE, ELSE RETURN TRUE
  
  bool Disabled( ) const;
  //COMPARES HEALTH TO ZERO
  //PRE: STATSCORES[HP] HAS A VALUE
  //POST: IF STATSCORES[HP] == ZERO RETURN TRUE, ELSE RETURN FALSE
  
  
  //OTHER************************************************************************

  int AbilityMod(AbilityType ability);
  //CALCULATES THE ABILITY MODIFIER
  //PRE: ABILITYSCORES HAS VALUES
  //POST: MOD IS RETURNED ROUNDED DOWN TO THE NEAREST WHOLE NUMBER
  
  int UpdateHP(int modification);
  //CHANGES THE HP RELIENT ON MODIFICATION
  //PRE: HP HAS A VALUE
  //POST: STATSCORES[HP] IS INCREASED OR DECREASED DEPENDING ON MODIFICATION
  
  bool SetCell(int newRow, int newCol);
  //CHANGES THE ROW AND COLUMN OF THE OBJECT
  //PRE:NEWROW AND NEWCOLUMN HAVE VALUES
  //POST: IF NEWROW AND NEWCOLUMN == NEG1 RETURN TRUE,  IF BOTH ARE > NEG1 RETURN TRUE,  ELSE RETURN FALSE
  
  //PROG2 IMPLEMENTATIONS
  
  string Weapon( );
  //RETURNS WEAPONS NAME AS A STRING
  //PRE: WEAPON POINTS TO SOMETHING
  //POST: WEAPON NAME IS RETURNED
  
  string Armor( );
  //RETURNS ARMOR NAME AS A STRING
  //PRE: ARMOR POINTS TO SOMETHING
  //POST: ARMOR NAME IS RETURNED
  
  bool HasWeapon( );
  //RETURNS A BOOLEAN. IF WEAPON IS NOT NULL RETURN TRUE, ELSE FALSE
  //PRE: NONE
  //POST: RETURN WEAPON
  
  bool HasArmor( );
  //RETURNS A BOOLEAN. IF ARMOR IS NOT NULL RETURN TRUE, ELSE FALSE
  //PRE: NONE
  //POST: RETURN ARMOR
  
  bool AddSkill(string skill);
  //ATTEMPTS TO ADD A SKILL TO THE CREATURES LIST OF SKILLS
  //IF SKILL IS VALID, ADD TO LIST. CAN ONLY OCCUR IF THE CREATURES HEALTH IS GREATER THAN -10
  //PRE: SKILLTABLE INITIALIZED. SKILL IS ALPHANUMERIC
  //POST: IF FOUND AND NOT ALREADY IN THE LIST, ADD TO LIST AND RETURN TRUE. ELSE RETURN FALSE. 
  
  WpnClass* ChangeWeapon(WpnClass* wpn);
  //IF PARAMETER IS NOT NULL, CHECKS TO SEE IF A VALID WEAPON. IF A VALID WEAPON IS PASSED IN, SWAP THE WEAPONS 
  //AND RETURN THE WEAPON SWAPPED OUT. IF PARAMETER IS NULL OR NOT VALID, RETURN ITS VALUE.
  //PRE: WPN IS NULL OR HAS A VALID WEAPON
  //POST: WEAPONS SWAPPED AND PREVIOUSLY HELP WEAPON RETURNED
  
  WpnClass* LoseWeapon( );
  //HELD WEAPON IS LOST AND RETURNED TO CLIENT
  //PRE: WEAPON IS NULL OR POINTS TO AN OBJECT
  //POST: WEAPON IS DELETED AND SET TO NULL. WEAPONS VALUE IS RETURNED
  
  ArmorClass* ChangeArmor(ArmorClass* requip);
  //IF PARAMETER IS NOT NULL, CHECKS TO SEE IF A VALID ARMOR. IF A VALID ARMOR IS PASSED IN, SWAP THE ARMORS 
  //AND RETURN THE ARMOR SWAPPED OUT. IF PARAMETER IS NULL OR NOT VALID, RETURN ITS VALUE.
  //PRE: REQUIP IS NULL OR HAS A VALID ARMOR
  //POST: ARMORS SWAPPED AND PREVIOUSLY HELP ARMOR RETURNED
  
  ArmorClass* LoseArmor( );
  //HELD ARMOR IS LOST AND RETURNED TO CLIENT
  //PRE: ARMOR IS NULL OR POINTS TO AN OBJECT
  //POST: ARMOR IS DELETED AND SET TO NULL. WEAPONS VALUE IS RETURNED
  
  int SkillCheck(string skill);
  //SEARCHES FOR THE SKILL IN THE CREATURES' LIST OF USABLE SKILLS
  //IF FOUND, ROLL THE DICE FOR SKILLCHECK AND ADD THE MODIFIER
  //PRE: SKILL IS ALPHANUMERIC
  //POST: IF FOUND, RETURN THE ROLL PLUS THE ABILITY MOD
  
  int UpdateGP(int value);
  //ADDS TO CREATURES GOLD, IF DROPPED BELOW ZERO SETS GOLD TO ZERO
  //PRE: GOLD IS GREATER THAN ZERO
  //POST: VALUE ADDED TO GOLD
  
  int UpdateXP(int value);
  //ADDS VALUE TO THE XP. FUNCTION THEN CHECKS XP AGAINST THE PROMOTION TABLE TO SEE IF LEVEL PROMOTION OCCURS
  //A DICE ROLL FOR HP IS DONE FOR EACH PROMOTION AND THAT VALUE, PLUS ONE FOR THE MINIMUM INCREASE,
  //IS ADDED TO THE CREATURES HP. THE XP IS RETURNED.
  //PRE: NONE
  //POST: XP UPDATED AND CHECKED AGAINST THE PROMOTION TABLE. LEVEL INCREASED IF NEW THRESHHOLD BROKEN. 
  
  
  vector<string> Skills( );
  //RETURNS THE CREATURES SKILLS AS A VECTOR
  //PRE: SKILLS INITIALIZED
  //POST: VECTOR SKILLS RETURNED
  
  vector<int> Abilities( );
  //RETURNS THE ABILITIES AS A VECTOR
  //PRE: NONE
  //POST: ABILITIES RETURNED AS A VECTOR
  
  void Amnesia( );
  //DELETES CREATURES SKILLS
  //PRE: NONE
  //POST: ALL SKILL DELETED
  
  void WriteSkillList( );
  
  void Write(ostream&);
  //OUTPUTS ALL VALUES OF OBJECT
  //PRE: OBJECT EXISTS
  //POST: ALL VALUES OUTPUT TO SCREEN DELIMINATED BY '#'
  
  //OVERLOADED OPERATORS**********************************************************************
  
  bool operator==(const CreatureClass& )const;
  ///COMPARES RIGHT OBJECT TO LEFT
  //PRE: RIGHT HAS A VALUE FOR NAMEPTR
  //POST: IF NAMEPTR AND RIGHT.NAMEPTR ARE THE SAME THING RETURN TRUE,  ELSE FALSE
  
  bool operator!=(const CreatureClass& )const;
  
  CreatureClass& operator=(const CreatureClass& c);
  //ASSIGNS RIGHT OBJECT TO LEFT
  //PRE: RIGHT OBJECT EXISTS AND HOLDS VALUES
  //POST: DATA IN LEFT OBJECT IS OVERWRITTEN AND BOTH OBJECTS NOW HOLD THE SAME VALUES
  
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

  
private:
  
  void softCopy(const CreatureClass& c);
  void RollStats( );
  void DefaultName( );
  
  string PtrToStr(const CreatureClass& c) const;
  
  bool SearchVec(string, bool = false);
  
  AbilityType SwitchSkillType(string);
  
  vector<string> GetDefSkills( );
  
  static void ReadSkills( );
  static void LoadVoc( );
  
  CreatureClass(); //default constructor
  
  //**********CONSTANTS**********
  static const int AB_ADJ[6][6];
  static const VocRules::VocType DEF_VOC[6];
  static const int NUM_DICE_HP_HUMANOID;
  static const int NUM_DICE_GP;
  static const int NUM_DICE_HP_TROLL;
  static const int NUM_DICE_HP_OGRE;
  static const int NUM_DICE_SIDES[6];
  static const int NUM_DICE_AB;
  static const int OGRE_HP_MOD;
  static const int TROLL_HP_MOD;
  static const int DEAD_DYING_LIM;
  static const int DYING_DISABLED_LIM;
  static const int DEF_ROW;
  static const int DEF_COL;
  static const int NAME_MAX_LEN;
  static const int TROLL_LEVEL;
  static const int OGRE_LEVEL;
  static const int MIN_START_HP;
  static const int DEF_XP;
  static const int DEF_LVL_HMNOID;
  static const int DEF_NAME_LEN;
  static const int NAME_MIN;
  static const int NUM_DICE_SKCK;
  static const int PROMOTION_TABLE[];
  static const string DEF_NAME;
  
  static vector< vector<string> > skillTable;
  static bool skillsRead;
  static VocRules* vocRules;
  static bool vocRead;
  
  //**********VARIABLES**********
  ArmorClass* armor;
  char* namePtr; 
  int abilityScores[6];
  int statScores[6];
  RaceType race;
  SavingThrowType saveThrow;
  vector<string> skill_list;
  VocRules::VocType voc;
  WpnClass* weapon;

  
  
};
#endif
