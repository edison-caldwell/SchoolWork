#include "cc2.h"

using namespace std;


//TESTED: CONSTRUCTORS, COPY CONSTRUCTOR, SKILLCHECK, ASSIGNMENT,
//NEEDS TESTED:  RELATIONAL OPS, NAME, BASIC OBSERVERS, UPDATES, EQUIPMENT, SKILLS, DEAD/DYING/DISABLED
//*******************************************************************************************
//Stat Declarations**************************************************************************
const int CreatureClass::NUM_DICE_HP_HUMANOID = 1;          //Number of dice rolled for humanoid hp roll
const int CreatureClass::NUM_DICE_SKCK = 1;
const int CreatureClass::NUM_DICE_GP = 1;                   //number of dice rolled for gp roll
const int CreatureClass::NUM_DICE_HP_TROLL = 6;             //number of dice rolled for troll hp
const int CreatureClass::NUM_DICE_HP_OGRE = 4;              //number of dice rolled for ogre hp
const int CreatureClass::NUM_DICE_AB = 3;                   //number of dice rolled for abilities
const int CreatureClass::NUM_DICE_SIDES[6] = {4,6,8,10,12,20}; //array of dice sides indexed by DiceType
const int CreatureClass::OGRE_HP_MOD = 8;                   //mod for OGRE hp
const int CreatureClass::TROLL_HP_MOD = 36;                 //mod for troll hp
const int CreatureClass::OGRE_LEVEL = 2;                    //constant OGRE level
const int CreatureClass::TROLL_LEVEL = 1;                   //constant troll level
const int CreatureClass::DEAD_DYING_LIM = -10;              //limit between dying and dead
const int CreatureClass::DYING_DISABLED_LIM = 0;            //limit between disabled and dead
const int CreatureClass::NAME_MAX_LEN = 10;                 //max length of name
const int CreatureClass::DEF_ROW = -1;                      //starting row
const int CreatureClass::DEF_COL = -1;                      //starting column
const int CreatureClass::MIN_START_HP = 1;                   //minimum starting hp
const int CreatureClass::DEF_LVL_HMNOID = 1;
const int CreatureClass::DEF_XP = 0;
const int CreatureClass::DEF_NAME_LEN = 8;
const int CreatureClass::NAME_MIN = 1;
const string CreatureClass::DEF_NAME = "default";

vector< vector<string> > CreatureClass::skillTable;

bool CreatureClass::skillsRead = false;

VocRules* CreatureClass::vocRules = NULL;

bool CreatureClass::vocRead = false;



void CreatureClass::LoadVoc( )
{
  vocRules = VocRules::GetVocRules( );
  
  vocRead = true;
}





const int CreatureClass::PROMOTION_TABLE[]=
 // Level 0 has 0, Level 1 base is 1, Level 2 base is 3000...
    {0,1000,3000,6000,10000,16000,24000,36000,
     52000,76000,110000,160000,220000,320000,
     440000,640000,890000,1300000,1800000,2600000};


     
     
const int CreatureClass::AB_ADJ[6][6] = 
{
  //Two demensional array that holds the ability adjustments, indexed by race and the ability type
  
  //           DEX CON INT CHA STR WIS 
  /*HUMAN*/   { 0,  0,  0,  0,  0,  0},
  /*ELF*/     { 2, -2,  0,  0,  0,  0},
  /*HALFELF*/ { 0,  0,  0,  0,  0,  0},
  /*ORC*/     { 0,  0, -2, -2,  2, -1},
  /*TROLL*/   {14, 23,  6,  6, 23,  9},
  /*OGRE*/    { 8, 15,  6,  7, 21, 10}
};




const VocRules::VocType CreatureClass::DEF_VOC[6] = 
{
  //Array of default vocations indexed by race
  /*HUMAN*/   VocRules::FTR,
  /*ELF*/     VocRules::WIZ,
  /*HALFELF*/ VocRules::ROG,
  /*ORC*/     VocRules::BBN,
  /*TROLL*/   VocRules::NNE,
  /*OGRE*/    VocRules::NNE
};




void CreatureClass::WriteSkillList( )
{ 
  for(int i = 0; i < skillTable.size( ); i++)
  {
    for(int j = 0; j < skillTable[i].size( ); j++)
    {
      cout << skillTable[i][j] << " ";
      
      if(j == skillTable[i].size( ) - 1)
	cout << endl;  
    }
    
  }
}




void CreatureClass::ReadSkills( )
{
  vector<string> vec;
  
  vector< vector<string> > yo_dawg;
  
  string temp;
  
  fstream shrek;
  
  shrek.open(GameSpace::SKILLS_FILE.c_str());
  
  for(int i = 0; i < 21; i++)
  {
    getline(shrek, temp, '#');
    
    transform(temp.begin( ), temp.end( ), temp.begin( ), ::toupper); 
    
    vec.push_back(temp);
    
    getline(shrek, temp);
    
    vec.push_back(temp);
    
    yo_dawg.push_back(vec);
    
    vec.clear( ); 
  }
  
  shrek.close( );
  
  skillsRead = true;
  
  skillTable = yo_dawg;
}




//*******************************************************************************************
//METHOD IMPLEMENTATIONS*********************************************************************
//*******************************************************************************************
CreatureClass::CreatureClass( ):namePtr(NULL), weapon(NULL), armor(NULL)
//default constructor
//PRE: NONE;
//POST: OBJECT IS CREATED WITH DEFAULT VALUES OF:
//ROW = -1, COLUMN = -1, NAMEPTR = NULL, RACE = HUMAN, VOC = FTR, XP = 0 AND ROLLS FOR ABILITY SCORES, HP, AND GP
{
  DefaultName( );
  race = HUMAN;
  voc = VocRules::FTR;
  
  
  RollStats( );
}




void CreatureClass::DefaultName( )
{ 
  namePtr = NULL;
  namePtr = new char [DEF_NAME_LEN];
  
  strcpy(namePtr, DEF_NAME.c_str( )); 
}




CreatureClass::CreatureClass(string name, RaceType race_type, VocRules::VocType voc_type)
                    :namePtr(NULL), weapon(NULL), armor(NULL)
//parameterized constructor (name, race, voc)
//PRE: PARAMETERS ARE CORRECT TYPES
//POST: OBJECT INSTANTIATED WITH PARAMETERIZED VALUES. IF RACE IS NOT PARAMETERIZED, RACE AND VOC ARE DEFAULTED.
//      IF ONLY VOC IS NOT PARAMETERIZED 
{
  if(!skillsRead)
    ReadSkills( );
  
  if(!vocRead)
    LoadVoc( );
  
  int check = static_cast<int>(race_type);
  
  if(check < 0 || check >5)
    race_type = BAD;
  
  //*******************TRIMMING WHITESPACE FROM NAME******
  name = GameSpace::TrimStr(name);
  
  
  //*******************CHECKING NAME LENGTH***************
  if(name.length( ) > NAME_MAX)
    name = name.substr(0, NAME_MAX);
  
  //*******************DETERMINING NAME*******************
  if(name.length( ) > NAME_MIN)
  {
    namePtr = NULL;
    namePtr = new char[name.length( )+1];
    strcpy(namePtr, name.c_str( ));
  }
  else if(name == "")
    DefaultName( );
  
  //*******************DETERMINING RACE*******************
  if(race_type == BAD)
    race = HUMAN;
  else
    race = race_type;
  
  //*******************DETERMINING VOC******************* 
  
  
  if(Humanoid( ))
  {
    if(voc_type == VocRules::NNE || voc_type < VocRules::NNE || voc_type > VocRules::WIZ)
      voc = DEF_VOC[race];
    else
      voc = voc_type;
  }
  else if(Monster( ))
  {
    voc = VocRules::NNE;
  }
  
  //*******************ROLLING FOR STATS*******************
  RollStats( );
  
  skill_list = GetDefSkills( );
}




CreatureClass::CreatureClass(const CreatureClass& c):namePtr(NULL), weapon(NULL), armor(NULL)
//COPY CONSTURCTOR
//PRE: OBJECT EXISTS 
//POST: NEW OBJECT IS DEEP COPY OF ORIGINAL
{
  if(c.namePtr)
  {
    namePtr = NULL;
    namePtr = new char[strlen(c.namePtr) + 1];
    strcpy(namePtr, c.namePtr);
  }
  
  if(c.weapon)
    weapon = new WpnClass(c.weapon->Name( ));
  else weapon = NULL;
  
  if(c.armor)
    armor = new ArmorClass(c.armor->Name( ));
  else armor = NULL;
  
  softCopy(c);
}




CreatureClass::~CreatureClass( )
{ 
  delete [] namePtr;
  delete weapon;
  delete armor;
}




void CreatureClass::softCopy(const CreatureClass& c)
//COPIES STATSCORES, ABILITY SCORES, RACE, AND VOC
//PRE: OBJECT BEING PASSED IN HOLD VALUES AND EXISTS
//POST: DATA VALUES ARE COPIED INT THE NEW OBJECT
{

  race = c.race;
  voc = c.voc;
  
  for(int i = row; i <= xp ; i++)
    statScores[i] = c.statScores[i];
  
  for(int i = CreatureClass::DEX; i <= CreatureClass::WIS; i++)
    abilityScores[i] = c.abilityScores[i]; 
  
  skill_list = c.skill_list;
}




vector<string> CreatureClass::GetDefSkills( )
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
  else if(voc == VocRules::NNE && race == TROLL)
  {
    temp.push_back("LISTEN");
    temp.push_back("SPOT");
  }
  else if(voc == VocRules::NNE && race == OGRE)
  {
    temp.push_back("INTIMIDATE");
    temp.push_back("LISTEN");
    temp.push_back("SPOT");
  }
  
  return temp;
}




string CreatureClass::Name( ) const
//RETURNS NAME
//PRE: NAMEPTR EITHER POINTS TO NULL 
//POST: VALUE NAMEPTR POINTS TO IS RETURNED
{
  string temp;
  
  if(namePtr == NULL)
    temp = "";
  else
    temp = namePtr;
  
  return temp;
}




int CreatureClass::Row( ) const
//RETURNS ROW
//PRE: ROW HOLDS A VALUE
//POST: ROW IS RETURNED
{
  return statScores[row];
}




int CreatureClass::Column( ) const
//RETURNS COLUMN
//PRE: COLUMN HOLDS A VALUE
//POST: COLUMN IS RETURNED
{
  return statScores[column];
}




int CreatureClass::Race( ) const
//RETURNS RACE AS AN INT
//PRE:RACE HOLDS AN ENUMERATED VALUE
//POST:RACE RETURNS AS AN INT
{
  return (int)race;
}




int CreatureClass::Voc( ) const
//RETURNS VOCATION AS AN INT
//PRE: VOC HOLDS A VALUE
//POST: VOC IS RETURNED
{
  return (int)voc;
}




int CreatureClass::Level( ) const
//RETURNS LEVEL AS AN INT
//PRE: LEVEL HOLDS A VALUE
//POST: LEVEL IS RETURNED
{
  return statScores[level];
}




int CreatureClass::HP( ) const
//RETURNS HP AS AN INT
//PRE: HP HOLDS A VALUE
//POST:HP IS RETURNED
{
  return statScores[hp];
}




int CreatureClass::XP( ) const
//RETURNS XP AS AN INT
//PRE: XP HOLDS A VALUE
//POST: XP IS RETURNED
{
  return statScores[xp];
}




int CreatureClass::GP( ) const
//RETURNS GP AS AN INT
//PRE: GP HOLDS A VALUE
//POST: GP IS RETURNED
{ 
  return statScores[gp];
}




int CreatureClass::Ability(AbilityType ability)
//RETURNS ABILITY SCORE INDEXED BY ABILITY TYPE
//PRE: ABILITYSCORES HOLDS VALUES AND ABILITY IS AN ENUMERATED VALUE OF ABILITYTYPE
//POST: ABILITYSCORES INDEXED BY ABILITY IS RETURNED
{
  return abilityScores[ability];
}




bool CreatureClass::Humanoid( ) const
//TESTS IF CREATURE IS A HUMANOID
//PRE:OBJECT HAS A RACE
//POST: RETURN TRUE IF NOT A OGRE OR TROLL, ELSE RETURN FALSE
{
  return(race != TROLL && race != OGRE && race != BAD) ;
}




bool CreatureClass::Monster( ) const
//TESTS IF CREATURE IS A MONSTER
//PRE: RACE HOLDS A VALUE
//POST: IF RACE IS TROLL OR OGRE RETURN TRUE. ELSE RETURN FALSE
{
  return(race == TROLL || race == OGRE);
}




bool CreatureClass::Dead( ) const
//CHECKS HEALTH TO BE LESS THAN -10 
//PRE: HEALTH HAS A VALUE
//POST: IF HEALTH IS LESS THAN -10 RETURN FALSE, ELSE RETURN TRUE
{ 
  return(statScores[hp] <= DEAD_DYING_LIM);   
}




bool CreatureClass::Dying( ) const
//CHECKS HEALTH TO BE BETWEEN -1 AND 9
//PRE: HEALTH HAS A VALUE
//POST: IF HP IS BETWEEN -1 AND -9 RETURN TRUE, ELSE RETURN FALSE
{
  return(statScores[hp] > DEAD_DYING_LIM && statScores[hp] < DYING_DISABLED_LIM);
}




bool CreatureClass::Disabled( ) const
//COMPARES HEALTH TO ZERO
//PRE: STATSCORES[HP] HAS A VALUE
//POST: IF STATSCORES[HP] == ZERO RETURN TRUE, ELSE RETURN FALSE
{
  return(statScores[hp] <= DYING_DISABLED_LIM);
}




int CreatureClass::AbilityMod(AbilityType ability)
//CALCULATES THE ABILITY MODIFIER
//PRE: ABILITYSCORES HAS VALUES
//POST: MOD IS RETURNED ROUNDED DOWN TO THE NEAREST WHOLE NUMBER
{
  return floor((abilityScores[ability]/2) - 5);
}




bool CreatureClass::SetCell(int newRow, int newColumn)
//CHANGES THE ROW AND COLUMN OF THE OBJECT
//PRE:NEWROW AND NEWCOLUMN HAVE VALUES
//POST: IF NEWROW AND NEWCOLUMN == NEG1 RETURN TRUE,  IF BOTH ARE > NEG1 RETURN TRUE,  ELSE RETURN FALSE
{
  bool temp = true;
  
  if((newRow > DEF_ROW && newColumn > DEF_COL) || (newRow == DEF_ROW && newColumn == DEF_COL))
  {
    statScores[row] = newRow; statScores[column] = newColumn;
  }
  else temp = false;
  
  return temp;
}




int CreatureClass::UpdateHP(int modification)
//CHANGES THE HP RELIENT ON MODIFICATION
//PRE: HP HAS A VALUE
//POST: STATSCORES[HP] IS INCREASED OR DECREASED DEPENDING ON MODIFICATION
{
  return(statScores[hp] += modification);
}




void CreatureClass::RollStats( )
//Rolls HP and Abilities for creature and adds the modification. If VocRules singleton not created, creates it.
{
  if(!vocRead)
    LoadVoc( );
  
  string name;
  
  if(!namePtr)
    name = "";
  else
    name = namePtr;
  
  if(Humanoid( ))
  {
    for(int i = DEX; i <= WIS; i++)
      abilityScores[i] = Dice::Roll(name, static_cast<RollType>(i), NUM_DICE_AB, NUM_DICE_SIDES[D6]) + (AB_ADJ[race][i]);
    
    statScores[hp] = Dice::Roll(name, GameSpace::HP, NUM_DICE_HP_HUMANOID, vocRules->HitDie(voc));
    statScores[hp] = statScores[hp] + AbilityMod(CON);
    
    if(statScores[hp] < 1)
      statScores[hp] = MIN_START_HP;
    
    statScores[gp] = Dice::Roll(name, GameSpace::GP, NUM_DICE_GP, NUM_DICE_SIDES[D4]);
    
    statScores[level] = DEF_LVL_HMNOID;
  }
  
  else if(Monster( ))
  {
    if(race == TROLL)
    {  
      statScores[hp] = Dice::Roll(name, GameSpace::HP, NUM_DICE_HP_TROLL, 8) + TROLL_HP_MOD;
      
      statScores[level] = TROLL_LEVEL;
      
      for(int i = DEX; i <= WIS; i++)
	abilityScores[i] = AB_ADJ[TROLL][static_cast<AbilityType>(i)];
    }
    else if(race == OGRE)
    {
      
      statScores[hp] = Dice::Roll(name, GameSpace::HP, NUM_DICE_HP_OGRE, 8) + OGRE_HP_MOD;
      
      statScores[level] = OGRE_LEVEL;
      
      for(int i = DEX; i <= WIS; i++)
	abilityScores[i] = AB_ADJ[OGRE][static_cast<AbilityType>(i)];
    }
    statScores[gp] = 0;
  }
  statScores[row] = DEF_ROW;
  statScores[column] = DEF_COL;
  statScores[xp] = DEF_XP;
}




void CreatureClass::Write(ostream& out)
//OUTPUTS ALL VALUES OF OBJECT
//PRE: OBJECT EXISTS
//POST: ALL VALUES OUTPUT TO SCREEN DELIMINATED BY '#'
{
  out << race << "#" << voc << "#";
  
  if(!namePtr)
    out << "#(";
  else
    out << namePtr << "#("; 
  
  out << statScores[CreatureClass::row] << "," << statScores[CreatureClass::column] << ")#";
  out << statScores[CreatureClass::hp] << "#";
  out << statScores[CreatureClass::level] << "#";
  out << statScores[CreatureClass::xp] << "#";
  out << statScores[CreatureClass::gp] << "#";
  out << abilityScores[CreatureClass::DEX] << "#";
  out << abilityScores[CreatureClass::CON] << "#";
  out << abilityScores[CreatureClass::INT] << "#";
  out << abilityScores[CreatureClass::CHA] << "#";
  out << abilityScores[CreatureClass::STR] << "#";
  out << abilityScores[CreatureClass::WIS] << "#";
  
  if(armor)
    out << armor->Name( ) << "#";
  else out << "#";
  
  if(weapon)
    out << weapon->Name( ) << "#(";
  else out << "#(";
  
  for(vector<string>::iterator it = skill_list.begin( ); it < skill_list.end( ); it++)
  {
    out << *it; 
    
    if(it < skill_list.end( ) -1)
      out << ",";
  }
  
  out << ")#";
}




//*******************************************************************************************
//OVERLOADED OPERATORS***********************************************************************
//*******************************************************************************************
string CreatureClass::PtrToStr(const CreatureClass& c) const
{
  string temp;
  
  if(c.namePtr == NULL)
    temp = "";
  else
    temp = c.namePtr;
  
  transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
  
  return temp;
}




bool CreatureClass::operator==(const CreatureClass& c) const
//COMPARES RIGHT OBJECT TO LEFT
//PRE: RIGHT HAS A VALUE FOR NAMEPTR
//POST: IF NAMEPTR AND RIGHT.NAMEPTR ARE THE SAME THING RETURN TRUE,  ELSE FALSE
{
  string left, other;
  
  left = PtrToStr(*this);
  other = PtrToStr(c);
  
  return(left == other);
}  




bool CreatureClass::operator!=(const CreatureClass& c) const
//COMPARES RIGHT OBJECT TO LEFT
//PRE:RIGHT HAS A VALUE FOR NAMEPTR
//POST: IF NAMPTR AND RIGHT.NAMEPTR ARE THE SAME THING RETURN FALSE,  ELSE TRUE
{ 
  string left, other;
  
  left = PtrToStr(*this);
  other = PtrToStr(c);
  
  return(left != other);
}




CreatureClass& CreatureClass::operator=(const CreatureClass& c)
//ASSIGNS RIGHT OBJECT TO LEFT
//PRE: RIGHT OBJECT EXISTS AND HOLDS VALUES
//POST: DATA IN LEFT OBJECT IS OVERWRITTEN AND BOTH OBJECTS NOW HOLD THE SAME VALUES
{
  int len;
  if (namePtr != c.namePtr)                           // make sure not same string!
  {
    if ((c.namePtr != NULL) && (c.namePtr[0] != '\0'))
    {
      len = strlen(c.namePtr);
      
      delete [] namePtr;
      namePtr = NULL;
      namePtr = new char[len+1];
      
      strcpy(namePtr, c.namePtr);
    }
    
    if(c.weapon != NULL)
    {
      delete weapon;
      weapon = NULL;
      weapon = new WpnClass(c.weapon->Name( )); 
    }
      
    
    if(c.armor != NULL)
    {
      delete armor;
      armor = NULL;
      armor = new ArmorClass(c.armor->Name( ));
    }
    
    softCopy(c);   
  }
}




/************************************************************************************/
/************************************************************************************/
/***********************************PROGRAM 2 METHODS********************************/
/************************************************************************************/
/************************************************************************************/
string CreatureClass::Weapon( )
//RETURNS WEAPONS NAME AS A STRING
//PRE: WEAPON POINTS TO SOMETHING
//POST: WEAPON NAME IS RETURNED
{
  string temp;
  
  if(!weapon)
    temp = "";
  else temp = weapon->Name( );
  
  return temp; 
}




string CreatureClass::Armor( )
//RETURNS ARMOR NAME AS A STRING
//PRE: ARMOR POINTS TO SOMETHING
//POST: ARMOR NAME IS RETURNED
{
  string temp;
  
  if(!armor)
    temp = "";
  else temp = armor->Name( );
  
  return temp;
}



bool CreatureClass::HasWeapon( )
//RETURNS A BOOLEAN. IF WEAPON IS NOT NULL RETURN TRUE, ELSE FALSE
//PRE: NONE
//POST: RETURN WEAPON
{
  return(weapon);
}




bool CreatureClass::HasArmor( )
//RETURNS A BOOLEAN. IF ARMOR IS NOT NULL RETURN TRUE, ELSE FALSE
//PRE: NONE
//POST: RETURN ARMOR
{
  return(armor);
}




WpnClass* CreatureClass::ChangeWeapon(WpnClass* wpn)
//IF PARAMETER IS NOT NULL, CHECKS TO SEE IF A VALID WEAPON. IF A VALID WEAPON IS PASSED IN, SWAP THE WEAPONS 
//AND RETURN THE WEAPON SWAPPED OUT. IF PARAMETER IS NULL OR NOT VALID, RETURN ITS VALUE.
//PRE: WPN IS NULL OR HAS A VALID WEAPON
//POST: WEAPONS SWAPPED AND PREVIOUSLY HELP WEAPON RETURNED
/*{  
  WpnClass* temp = NULL;

  
  if(wpn && statScores[hp] > DYING_DISABLED_LIM && WpnClass::IsEquipment(wpn->Name( )))
  { 
      if(weapon)
      {
        temp = new WpnClass(weapon->Name( ));
      
        delete weapon;
        weapon = NULL;
        weapon = new WpnClass(wpn->Name( ));  
      }
      else if(!weapon)
      {
        weapon = new WpnClass(wpn->Name( )); 
      }
  }
  else if(wpn)
    temp = new WpnClass(wpn->Name( ));

  delete wpn;
  
  wpn = NULL;
 
  return temp;
}*/
{
  WpnClass* temp = NULL;
  
   if(wpn && statScores[hp] > DYING_DISABLED_LIM && WpnClass::IsEquipment(wpn->Name( )))
  { 
      if(weapon)
      {
	temp = weapon;
	
	weapon = wpn;
      }
      else if(!weapon)
      {
        weapon = wpn; 
      }
  }
  else if(wpn)
    temp = new WpnClass(wpn->Name( ));
  
  return temp;
}
  




ArmorClass* CreatureClass::ChangeArmor(ArmorClass* requip)
//IF PARAMETER IS NOT NULL, CHECKS TO SEE IF A VALID ARMOR. IF A VALID ARMOR IS PASSED IN, SWAP THE ARMORS 
//AND RETURN THE ARMOR SWAPPED OUT. IF PARAMETER IS NULL OR NOT VALID, RETURN ITS VALUE.
//PRE: REQUIP IS NULL OR HAS A VALID ARMOR
//POST: ARMORS SWAPPED AND PREVIOUSLY HELP ARMOR RETURNED
{
  ArmorClass* temp = NULL;
  
  if(requip && statScores[hp] > DYING_DISABLED_LIM && ArmorClass::IsEquipment(requip->Name( )))
  {
    if(armor)
    {
      temp = new ArmorClass(armor->Name( ));
      
      delete armor;
      armor = new ArmorClass(requip->Name( ));
    }
    else if(!armor)
    {
      armor = new ArmorClass(requip->Name( ));
    }
  }
  else if(requip)
    temp = new ArmorClass(requip->Name( ));
  
  delete requip;
  
  requip = NULL;
  
  return temp;      
}




WpnClass* CreatureClass::LoseWeapon( )
//HELD WEAPON IS LOST AND RETURNED TO CLIENT
//PRE: WEAPON IS NULL OR POINTS TO AN OBJECT
//POST: WEAPON IS DELETED AND SET TO NULL. WEAPONS VALUE IS RETURNED
{
  WpnClass* temp = NULL;
  
  if(weapon)
  {
    delete temp;
    temp = NULL;
    temp = new WpnClass(weapon->Name( ));
    
    delete weapon;
    
    weapon = NULL;
  }
  
  return temp;
  
}




ArmorClass* CreatureClass::LoseArmor( )
//HELD ARMOR IS LOST AND RETURNED TO CLIENT
//PRE: ARMOR IS NULL OR POINTS TO AN OBJECT
//POST: ARMOR IS DELETED AND SET TO NULL. WEAPONS VALUE IS RETURNED
{
  ArmorClass* temp = NULL;
  
  if(armor)
  {
    delete temp;
    temp = NULL;
    temp = new ArmorClass(armor->Name( ));
    
    delete armor;
    
    armor = NULL;
  }
  
  return temp;
}





bool CreatureClass::SearchVec(string search_for, bool table)
//SEARCHED THE SKILLS AND SKILLS TABLE VECTORS FOR A STRING. IF TABLE IS TRUE SEARCH BOTH, ELSE IF FALSE SEARCH
//ONLY SKILLS. IF THE OBJECT IS FOUND IN ONE(OR BOTH) RETURN TRUE, ELSE FALSE. 
//PRE:TABLE HAS A VALUE.
//POST: OBJECT FOUND OR NOT FOUND. RETURN TRUE IF FOUND, ELSE FALSE IF NOT
{
  bool exists = false;
  
  if(table)
  {                                                          /*Searches skill table for the skill*/
    for(int i = 0; i < skillTable.size( ); i++)
    {
      for(int j = 0; j < skillTable[i].size( ); j++)
      {
	if(skillTable[i][j] == search_for)
	  exists = true;
      }
    }
  }
  else if(!table)                                            /*Searches  the creatures skill list*/
  {
    for(int i = 0; i < skill_list.size( ); i++)
    {
      if(skill_list[i] == search_for)
	exists = true;
    }  
  } 
  
  return exists;
}




bool CreatureClass::AddSkill(string skill)
//ATTEMPTS TO ADD A SKILL TO THE CREATURES LIST OF SKILLS
//IF SKILL IS VALID, ADD TO LIST. CAN ONLY OCCUR IF THE CREATURES HEALTH IS GREATER THAN -10
//PRE: SKILLTABLE INITIALIZED. SKILL IS ALPHANUMERIC
//POST: IF FOUND AND NOT ALREADY IN THE LIST, ADD TO LIST AND RETURN TRUE. ELSE RETURN FALSE. 
{
  bool added = false;
  
  transform(skill.begin( ), skill.end( ), skill.begin( ), ::toupper);
  
  if(statScores[hp] > DYING_DISABLED_LIM)
  {
    if(SearchVec(skill, true))
    {
      added = true;
      
      if(!SearchVec(skill, false))
      {
        skill_list.push_back(skill);
        added = true;
      }
    }
  }
  else if(SearchVec(skill, false)
    added = true;
  
  sort(skill_list.begin( ), skill_list.end( ));
  
  return added;
}




int CreatureClass::SkillCheck(string skill)
//SEARCHES FOR THE SKILL IN THE CREATURES' LIST OF USABLE SKILLS
//IF FOUND, ROLL THE DICE FOR SKILLCHECK AND ADD THE MODIFIER
//PRE: SKILL IS ALPHANUMERIC
//POST: IF FOUND, RETURN THE ROLL PLUS THE ABILITY MOD
{ 
  int check = 0;
  
  string skillType;
  
  transform(skill.begin( ), skill.end( ), skill.begin( ), ::toupper);

  if(statScores[hp] > DEAD_DYING_LIM)
  {
    if(SearchVec(skill, false))
    {
      for(int i = 0; i < skillTable.size( ); i++)
      {
	for(int j = 0; j < skillTable[i].size( ); j++)
	{
	  if(skillTable[i][j] == skill)
	    skillType = skillTable[i][j+1];
	}	  
      }
    
    check = Dice::Roll(namePtr, GameSpace::SKCK, NUM_DICE_SKCK, NUM_DICE_SIDES[D20]);
    
    AbilityType tempAbil = SwitchSkillType(skillType);
    
    check += AbilityMod((SwitchSkillType(skillType)));
    }
  } 
  
  return check;
}




void CreatureClass::Amnesia( )
//DELETES CREATURES SKILLS
//PRE: NONE
//POST: ALL SKILL DELETED
{
  skill_list.clear( );
}




vector<string> CreatureClass::Skills( )
//RETURNS THE CREATURES SKILLS AS A VECTOR
//PRE: SKILLS INITIALIZED
//POST: VECTOR SKILLS RETURNED
{
  return skill_list;
}




vector<int> CreatureClass::Abilities( )
//RETURNS THE ABILITIES AS A VECTOR
//PRE: NONE
//POST: ABILITIES RETURNED AS A VECTOR
{
  vector<int> ability;
  
  for(int i = DEX; i <= WIS; i++)
    ability.push_back(abilityScores[i]);
  
  return ability;
}




int CreatureClass::UpdateGP(int value)
//ADDS TO CREATURES GOLD, IF DROPPED BELOW ZERO SETS GOLD TO ZERO
//PRE: GOLD IS GREATER THAN ZERO
//POST: VALUE ADDED TO GOLD
{
  int temp;
  if(Humanoid( ))
  {
  if(statScores[gp] < 0)
    statScores[gp] = 0;
  else
    statScores[gp] += value;
  }
  
  return statScores[gp];
}




int CreatureClass::UpdateXP(int value)
//ADDS VALUE TO THE XP. FUNCTION THEN CHECKS XP AGAINST THE PROMOTION TABLE TO SEE IF LEVEL PROMOTION OCCURS
//A DICE ROLL FOR HP IS DONE FOR EACH PROMOTION AND THAT VALUE, PLUS ONE FOR THE MINIMUM INCREASE,
//IS ADDED TO THE CREATURES HP. THE XP IS RETURNED.
//PRE: NONE
//POST: XP UPDATED AND CHECKED AGAINST THE PROMOTION TABLE. LEVEL INCREASED IF NEW THRESHHOLD BROKEN. 
{

  if(!vocRead)
    LoadVoc( );
  
  string temp = namePtr;
  
  int oneUP = 0;
  
  if(value > 0 && Humanoid( ))
  {
    statScores[xp] += value;
    
    for(int i = 0; i < VocRules::LEVEL_MAX; i++)
    {
      if(statScores[xp] >= PROMOTION_TABLE[i] && statScores[level] <= i)
	oneUP++;
    }
    
    if(oneUP > 0)
    {
      for(int i = 0; i < oneUP; i++)
      {
	statScores[hp]+= (Dice::Roll(temp, GameSpace::HP, NUM_DICE_HP_HUMANOID, vocRules->HitDie(voc)) + 1);
      }
    }
   
  statScores[level] += oneUP;
  
  }
  return statScores[xp];
  
  
}




bool CreatureClass::operator<(const CreatureClass& c)
//CHECKS THE CREATURES NAMES. IF LEFT IS GREATER THAN RIGHT RETURN TRUE, ELSE FALSE
//PRE: BOTH CREATURES BEING COMPARED HAVE NAMES
//POST: IF LEFT IS GREATER THAN RIGHT RETURN TRUE, ELSE FALSE
{
  string left, other;
  
  left = PtrToStr(*this);
  other = PtrToStr(c);
  
  return(left < other);
  
}




bool CreatureClass::operator<=(const CreatureClass& c)
//CHECKS THE CREATURES NAMES. IF LEFT IS GREATER THAN OR EQUAL TO RIGHT RETURN TRUE, ELSE FALSE
//PRE: BOTH CREATURES BEING COMPARED HAVE NAMES
//POST: IF LEFT IS GREATER THAN OR EQUAL TO  RIGHT RETURN TRUE, ELSE FALSE
{
  string left, other;
  
  left = PtrToStr(*this);
  other = PtrToStr(c);
  
  return(left <= other);
}




bool CreatureClass::operator>(const CreatureClass& c)
//CHECKS THE CREATURES NAMES. IF LEFT IS LESS THAN RIGHT RETURN TRUE, ELSE FALSE
//PRE: BOTH CREATURES BEING COMPARED HAVE NAMES
//POST: IF LEFT IS LESS THAN RIGHT RETURN TRUE, ELSE FALSE
{
  string left, other;
  
  left = PtrToStr(*this);
  other = PtrToStr(c);
  
  return(left > other);
}




bool CreatureClass::operator>=(const CreatureClass& c)
//CHECKS THE CREATURES NAMES. IF LEFT IS LESS THAN OR EQUAL TO RIGHT RETURN TRUE, ELSE FALSE
//PRE: BOTH CREATURES BEING COMPARED HAVE NAMES
//POST: IF LEFT IS LESS THAN OR EQUAL TO RIGHT RETURN TRUE, ELSE FALSE
{
  string left, other;
  
  left = PtrToStr(*this);
  other = PtrToStr(c);
  
  return(left >= other);
}




CreatureClass::AbilityType CreatureClass::SwitchSkillType(string str)
//SWITCHES A STRING TO AN ENUMERATED TYPE 
//PRE: STR IS THE STRING EQUIVELENT OF AN ABILITY TYPE
//POST: SWITCH THE STR WITH THE ENUMERATED TYPE
{
  AbilityType temp;
  
  if(str == "DEX")
    temp = DEX;
  else if(str == "CON")
    temp = CON;
  else if(str == "INT")
    temp = INT;
  else if (str == "CHA")
    temp = CHA;
  else if(str == "STR")
    temp = STR;
  else if(str == "WIS")
    temp = WIS;
  
  return temp;
}


