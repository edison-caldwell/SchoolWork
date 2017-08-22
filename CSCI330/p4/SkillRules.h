#ifndef _SKILLRULES
#define _SKILLRULES

#include <fstream>
#include <vector>
#include <iostream>
#include "gamespace.h"


using namespace std;
using namespace GameSpace;

class CreatureClass;


class SkillRules{
  
public:
  
//   enum AbilityType{DEX /*DEXTERITY*/, CON /*CONSTITUTION*/, INT /*INTELLIGENCE*/, CHA /*CHARISMA*/, STR /*STRENGTH*/, WIS /*WISDOM*/};
  
  struct SkillData
  {
    string skill;
    CreatureClass::AbilityType abil;
  };
  
  static SkillRules* GetSkillRules( );
  
  static void DeleteSkillRules( );
  
  vector<string> DefSkills(VocRules::VocType);
  
  ~SkillRules( );
  
  CreatureClass::AbilityType GetSkillType(string);
  
  vector<string> GetSkills( );
  
  bool ValidateSkill(string);
  
  void Print(ostream&);
  
  
private:
  
  int GetSkillIndex(string);
  
  static const int SKILLS_MAX;
  
  static bool read;
  
  SkillRules( );
  
  CreatureClass::AbilityType StrToAbl(string);
  
  static SkillRules* sk;
  
  vector<SkillData> list;
  
  
};
  
#endif 
  
  