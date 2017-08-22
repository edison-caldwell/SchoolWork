#include "cc3.h"
#include "SkillRules.h"


bool SkillRules::read = false;

SkillRules* SkillRules::sk = NULL;

const int SkillRules::SKILLS_MAX = 21;




SkillRules* SkillRules::GetSkillRules( )
{
  if(!read)
    sk = new SkillRules( );
  
  read = true;
  
  return sk;
}



SkillRules::SkillRules( )
{ 
  string temp;
  
  SkillData tempStruct;
  
  fstream shrek;
  
  shrek.open(GameSpace::SKILLS_FILE.c_str());
  
  for(int i = 0; i < SKILLS_MAX; i++)
  {
    getline(shrek, temp, '#');
    
    transform(temp.begin( ), temp.end( ), temp.begin( ), ::toupper); 
    
    tempStruct.skill = temp;
    
    getline(shrek, temp);
    
    transform(temp.begin( ), temp.end( ), temp.begin( ), ::toupper);
    
    tempStruct.abil = StrToAbl(temp);
    
    list.push_back(tempStruct);
     
  }
  shrek.close( );
  
}



vector<string> SkillRules::GetSkills( )
{
  vector<string> temp;
  
  for(int i = 0; i < list.size( ); i++)
  {
    temp.push_back(list[i].skill); 
  }
  
  return temp;
}



bool SkillRules::ValidateSkill(string skill)
{
  bool found = false;
  
  for(int i = 0; i < list.size( ); i++)
  {
    if(list[i].skill == skill)
      found = true;
  }
  
  return found;
}



int SkillRules::GetSkillIndex(string skill)
{
  int index = 0;
  
  for(int i = 0; i < list.size( ); i++)
  {
    if(list[i].skill == skill)
      index = i;
  }
  
  return index;
}



CreatureClass::AbilityType SkillRules::GetSkillType(string temp_skill)
{
  transform(temp_skill.begin( ), temp_skill.end( ), temp_skill.begin( ), ::toupper);
  
  int index = GetSkillIndex(temp_skill);
  
  return list[index].abil;
  
}



SkillRules::~SkillRules( )
{
  
}



void SkillRules::DeleteSkillRules( )
{
  delete sk;
  
  read = false;
}


void SkillRules::Print(ostream& out)
{
  for(int i = 0; i < list.size( ); i++)
  {
    out << list[i].skill << " "; 
    
    switch(list[i].abil)
    {
      case 0 : out << "DEX" << endl;
      break;
      case 1 : out << "CON" << endl;
      break;
      case 2 : out << "INT" << endl;
      break;
      case 3 : out << "CHA" << endl;
      break;
      case 4 : out << "STR" << endl;
      break;
      case 5 : out << "WIS" << endl;
      break;
    }
  }
}



CreatureClass::AbilityType SkillRules::StrToAbl(string str)
{
  CreatureClass::AbilityType temp;
  
  if(str == "DEX")
    temp = CreatureClass::DEX;
  else if(str == "CON")
    temp = CreatureClass::CON;
  else if(str == "INT")
    temp = CreatureClass::INT;
  else if (str == "CHA")
    temp = CreatureClass::CHA;
  else if(str == "STR")
    temp = CreatureClass::STR;
  else if(str == "WIS")
    temp = CreatureClass::WIS;
  
  return temp;
}

vector<string> SkillRules::DefSkills(VocRules::VocType voc)
{
    vector<string> temp;
  
  if(voc == VocRules::BBN)
  {
    temp.push_back("CLIMB");
    temp.push_back("LISTEN");
    temp.push_back("SWIM");
  }
  else if(voc == VocRules::CLR)
  {
    temp.push_back("HEAL");
    temp.push_back("USE MAGIC DEVICES");
  }
  else if(voc == VocRules::FTR)
  {
    temp.push_back("INTIMIDATE");
    temp.push_back("SWIM");
  }
  else if(voc == VocRules::ROG)
  {
    temp.push_back("BLUFF");
    temp.push_back("CLIMB");
    temp.push_back("HIDE");
  }
  else if(voc == VocRules::WIZ)
  {
    temp.push_back("CONCENTRATION");
    temp.push_back("HIDE");
    temp.push_back("USE MAGIC DEVICES");
  }

  return temp;
}
