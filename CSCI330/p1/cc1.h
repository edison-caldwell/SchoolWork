#ifndef _CC1H
#define _CC1H

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <iomanip>
#include "dice.h"

using namespace std;
using namespace GameSpace;

class CreatureClass
{
public:
  
  friend ostream& operator<<(ostream& out, const CreatureClass& c); //overloded extraction
  
  enum RaceType{HUMAN, ELF, HALFELF, ORC, TROLL, OGRE};
  enum VocType{NNE /*NONE*/, BBN /*BARBARIAN*/, CLR /*CLERIC*/, FTR /*FIGHTER*/, ROG /*ROGUE*/, WIZ /*WIAZARD*/};
  enum AbilityType{DEX /*DEXTERITY*/, CON /*CONSTITUTION*/, INT /*INTELLIGENCE*/, CHA /*CHARISMA*/, STR /*STRENGTH*/, WIS /*WISDOM*/};
  enum SavingThrowType{FORT = 1, REFLEX, WILL};
  enum StatType{row, column, hp, gp, level, xp};
  enum DiceType{D4, D6, D8, D10, D12};
  
  
  //CONSTRUCTORS
  CreatureClass(); //default constructor
  CreatureClass(string name, RaceType race_type = HUMAN, VocType voc_type = NNE); //Parameterized constructor (name, race, vocation)
  CreatureClass(const CreatureClass& c); //copy constructor
  ~CreatureClass(); //deconstructor
  
  //GETTERS
  string Name( ) const;
  int Row( ) const;
  int Column( ) const; 
  int Race( ) const;
  int Voc( ) const;
  int Level( ) const;
  int HP( ) const;
  int XP( ) const;
  int GP( ) const;
  int Ability(AbilityType ability) ;
  bool Humanoid( ) const;
  bool Monster( ) const;
  bool Dying( ) const;
  bool Dead( ) const;
  bool Disabled( ) const;
  
  
  //OTHER
  int AbilityMod(AbilityType ability); //calculate and return ability modifier for roll
  int UpdateHP(int modification); //if mod is negative decrease health, if positive increase
  bool SetCell(int newRow, int newCol); //moves the character and returns a bool if moved.
  
  //OVERLOADED OPERATORS
  bool operator==(const CreatureClass& )const; //overloaded == 
  bool operator!=(const CreatureClass& )const; //overloaded !=
  CreatureClass& operator=(const CreatureClass& c); //overloaded assignment
  
private:
  
  void softCopy(const CreatureClass& c);
  void RollStats( );

  
  //**********CONSTANTS**********
  static const int AB_ADJ[6][6];
  static const VocType DEF_VOC[6];
  static const int HIT_DIES[6];
  static const int NUM_DICE_HP_HUMANOID;
  static const int NUM_DICE_GP;
  static const int NUM_DICE_HP_TROLL;
  static const int NUM_DICE_HP_OGRE;
  static const int NUM_DICE_SIDES[5];
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
  
  //**********VARIABLES**********
  int abilityScores[6];
  int statScores[6];
  char* namePtr; 
  RaceType race;
  VocType voc;
  SavingThrowType saveThrow;
  
  
  
};
#endif
