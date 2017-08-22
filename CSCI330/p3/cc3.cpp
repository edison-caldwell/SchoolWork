#include "cc3.h"
#include "SkillRules.h"



//***STATIC DATA***//

const int CreatureClass::DISABLED = 0;

const int CreatureClass::DEAD = -10;

const int CreatureClass::DEF_NAME_LEN = 8;

const string CreatureClass::DEF_NAME = "default";

SkillRules* CreatureClass::skillRules = NULL;

bool CreatureClass::skillRead = false;




//***CONSTRUCTORS***//

CreatureClass::CreatureClass(string name):
namePtr(NULL), weapon(NULL), armor(NULL)
{
  LoadSkillRules( );
  
  if(name == "")
    DefaultName( );
  else
  {
    name = GameSpace::TrimStr(name);
    
    namePtr = new char[name.length( )+1];
    
    strcpy(namePtr, name.c_str( ));
  }
  
  hp = 0;
  
  row = -1;
  
  col = -1;  
}



CreatureClass::CreatureClass( )
{
}



CreatureClass::~CreatureClass( )
{
  delete[] namePtr;
  delete weapon;
  delete armor;
}

CreatureClass::CreatureClass(const CreatureClass& c):
namePtr(NULL), weapon(NULL), armor(NULL)
{
  namePtr = new char[strlen(c.namePtr) + 1];
  
  strcpy(namePtr, c.namePtr);
  
  skills = c.skills;
  
  abilityScores = c.abilityScores;
  
  hp = c.hp;
  
  row = c.row;
  
  col = c.col;
  
  if(c.weapon)
    weapon = new WpnClass(c.weapon->Name( ));
  
  if(c.armor)
    armor = new ArmorClass(c.armor->Name( ));
  
}

//***HELPER FUNCTIONS***//

void CreatureClass::DefaultName( )
{ 
  namePtr = NULL;
  namePtr = new char [DEF_NAME_LEN];
  
  strcpy(namePtr, DEF_NAME.c_str( )); 
}



void CreatureClass::InitSkills(vector<string> setSkill)
{
  skills = setSkill;
}



void CreatureClass::InitAbilities(vector<int> setAbilities)
{
  abilityScores = setAbilities;
}



int CreatureClass::RollHP(int NumDice, DiceType faces, int mod)
{
  return (Dice::Roll(namePtr, GameSpace::HP, NumDice, faces) + mod);
}



void CreatureClass::LoadSkillRules( )
{
  if(skillRead)
    skillRules = SkillRules::GetSkillRules( );
  
  skillRead = true;
}



void CreatureClass::WriteAbilityScores(ostream& out) const
{
  if(abilityScores.size( ) != 0)
  {
    for(int i = 0; i < abilityScores.size( ); i++)
    {
      out << abilityScores[i];
      
      if(i < abilityScores.size( ) - 1)
	out << "#";
    }
  }
}



void CreatureClass::WriteSkills(ostream& out) const
{
  if(skills.size( ) != 0 )
  {
    for(int i = 0; i < skills.size( ); i++)
    {
      out << skills[i];
      
      if(i < skills.size( ) - 1)
	out << ",";
    }
  }
}



//***OBSERVERS***//

string CreatureClass::Name( ) const
//RETURNS NAME
//PRE: NAMEPTR EITHER POINTS TO NULL 
//POST: VALUE NAMEPTR POINTS TO IS RETURNED
{
  return namePtr;
}



int CreatureClass::Row( ) const
//RETURNS ROW
//PRE: ROW HOLDS A VALUE
//POST: ROW IS RETURNED
{
  return row;
}



int CreatureClass::Column( ) const
//RETURNS COLUMN
//PRE: COLUMN HOLDS A VALUE
//POST: COLUMN IS RETURNED
{
  return col;
}



int CreatureClass::HP( ) const
//RETURNS HP AS AN INT
//PRE: HP HOLDS A VALUE
//POST:HP IS RETURNED
{
  return hp;
}



int CreatureClass::Ability(AbilityType ability) const
//RETURNS ABILITY SCORE INDEXED BY ABILITY TYPE
//PRE: ABILITYSCORES HOLDS VALUES AND ABILITY IS AN ENUMERATED VALUE OF ABILITYTYPE
//POST: ABILITYSCORES INDEXED BY ABILITY IS RETURNED
{
  return abilityScores[ability];
}



bool CreatureClass::Dead( ) const
//CHECKS HEALTH TO BE LESS THAN -10 
//PRE: HEALTH HAS A VALUE
//POST: IF HEALTH IS LESS THAN -10 RETURN FALSE, ELSE RETURN TRUE
{ 
  return(hp <= DEAD);   
}



bool CreatureClass::Dying( ) const
//CHECKS HEALTH TO BE BETWEEN -1 AND 9
//PRE: HEALTH HAS A VALUE
//POST: IF HP IS BETWEEN -1 AND -9 RETURN TRUE, ELSE RETURN FALSE
{
  return(hp > DEAD && hp < DISABLED);
}



bool CreatureClass::Disabled( ) const
//COMPARES HEALTH TO ZERO
//PRE: STATSCORES[HP] HAS A VALUE
//POST: IF STATSCORES[HP] == ZERO RETURN TRUE, ELSE RETURN FALSE
{
  return(hp <= DISABLED);
}



int CreatureClass::AbilityMod(AbilityType ability) const
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
  
  if((newRow > -1 && newColumn > -1) || (newRow == -1 && newColumn == -1))
  {
    row = newRow; col = newColumn;
  }
  else temp = false;
  
  return temp;
}



int CreatureClass::UpdateHP(int modification)
//CHANGES THE HP RELIENT ON MODIFICATION
//PRE: HP HAS A VALUE
//POST: STATSCORES[HP] IS INCREASED OR DECREASED DEPENDING ON MODIFICATION
{
  hp += modification;
  
  return hp;
}



string CreatureClass::Weapon( ) const
{
  string temp;
  
  if(weapon)
    temp = weapon->Name( );
  else temp = "";
  
  return temp;
}


string CreatureClass::Armor( ) const
{
  string temp;
  
  if(armor)
    temp = armor->Name( );
  else temp = "";
  
  return temp;
}



vector<int> CreatureClass::Abilities( ) const
{
  return abilityScores;
}



vector<string> CreatureClass::Skills( ) const
{
  return skills;
}



int CreatureClass::SkillCheck(string skill)
{
  int check = 0;
  
  transform(skill.begin( ), skill.end( ), skill.begin( ), ::toupper);
  
  if(hp > -10)
  {
    if(find(skills.begin( ), skills.end( ), skill) != skills.end( ))
    {
      check = Dice::Roll(namePtr, GameSpace::SKCK, 1, D20);
      
      check += AbilityMod(skillRules->GetSkillType(skill));
    }
  } 
  
  return check;
}



bool CreatureClass::HasWeapon( ) const
{
  return weapon;
}


bool CreatureClass::HasArmor( ) const
{
  return armor;
}



EquipClass* CreatureClass::LoseEquipment( )
{
  delete weapon;
  weapon = NULL;
  
  delete armor;
  armor = NULL;
  
}



WpnClass* CreatureClass::LoseWeapon( )
//HELD WEAPON IS LOST AND RETURNED TO CLIENT
//PRE: WEAPON IS NULL OR POINTS TO AN OBJECT
//POST: WEAPON IS DELETED AND SET TO NULL. WEAPONS VALUE IS RETURNED
{
  EquipClass* temp = NULL;
  
  if(weapon)
  {
    temp = weapon;
    
    weapon = NULL;
  }
  
  return dynamic_cast<WpnClass*>(temp);
  
}




ArmorClass* CreatureClass::LoseArmor( )
//HELD ARMOR IS LOST AND RETURNED TO CLIENT
//PRE: ARMOR IS NULL OR POINTS TO AN OBJECT
//POST: ARMOR IS DELETED AND SET TO NULL. WEAPONS VALUE IS RETURNED
{
  EquipClass* temp = NULL;
  
  if(armor)
  {
    temp = armor;
    
    armor = NULL;
  }
  
  return dynamic_cast<ArmorClass*>(temp);
}



bool CreatureClass::AddSkill(string skill)
{
  bool added = false;
  
  transform(skill.begin( ), skill.end( ), skill.begin( ), ::toupper);
  
  if(Active( ) && skillRules->ValidateSkill(skill))
  {
    if(find(skills.begin( ), skills.end( ), skill) == skills.end( ))
      skills.push_back(skill); 
    
    added = true;
  }
  else if(find(skills.begin( ), skills.end( ), skill) != skills.end( ))
    added = true;
  
  return added;
}



void CreatureClass::Amnesia( )
{
  skills.clear( );
}



EquipClass* CreatureClass::FindEquipment(EquipClass* requip)
{
  EquipClass* temp = NULL;
  
  WpnClass* w = dynamic_cast<WpnClass*>(requip);
  
  ArmorClass* a = dynamic_cast<ArmorClass*>(requip);
  
  if(Active( ) && requip)
  {
    if(w)
    {
      //if(weapon)
      temp = weapon;
      
      weapon = w;
    }
    else if(a)
    {
      //if(armor)
      temp = armor;
      
      armor = a;
    }
  }
  else if(!Active( ))
    temp = requip;
  
  return temp; 
}                                               



bool CreatureClass::Active( )const
{
  return (hp > 0);
}



int CreatureClass::InitiativeCheck( ) const
{
  return Dice::Roll(namePtr, GameSpace::INIT, 1, D20) + AbilityMod(DEX);
}



int CreatureClass::Defense( ) const
{
  int armor_bonus = 0;
  
  if(armor)
    armor_bonus = armor->Bonus( );
    
  return 10 + AbilityMod(DEX) + armor_bonus;
}



int CreatureClass::Damage( ) const
{
  int damage = 0;
  
  if(weapon && Active( ))
  {
    if(WpnClass::IsMelee(weapon->Name( )))
      damage = AbilityMod(STR);
     
    damage += weapon->Damage(namePtr);
  }
  else if(!weapon && Active( ))
    damage = AbilityMod(STR);

  return damage;  
}



void CreatureClass::Write(ostream& out) const
{
  out << namePtr << "#(" << row << "," << col << ")#" << hp << "#[";
  
  WriteAbilityScores(out);
  
  out << "]#(";
  
  WriteSkills(out);
  
  out << ")#";
  
  if(armor)
    out << armor->Name( );
  
  out << "#";
  
  if(weapon)  
    out << weapon->Name( );
  
  out << "#\n";
  
}


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

//***OVERLOADED OPS***/

CreatureClass& CreatureClass::operator=(const CreatureClass& c)
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
  }
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

{
  string left, other;
  
  left = PtrToStr(*this);
  other = PtrToStr(c);
  
  return(left >= other);
}


bool CreatureClass::operator==(const CreatureClass& c)
//COMPARES RIGHT OBJECT TO LEFT
//PRE: RIGHT HAS A VALUE FOR NAMEPTR
//POST: IF NAMEPTR AND RIGHT.NAMEPTR ARE THE SAME THING RETURN TRUE,  ELSE FALSE
{
  string left, other;
  
  left = PtrToStr(*this);
  other = PtrToStr(c);
  
  return(left == other);
}  




bool CreatureClass::operator!=(const CreatureClass& c)
//COMPARES RIGHT OBJECT TO LEFT
//PRE:RIGHT HAS A VALUE FOR NAMEPTR
//POST: IF NAMPTR AND RIGHT.NAMEPTR ARE THE SAME THING RETURN FALSE,  ELSE TRUE
{ 
  string left, other;
  
  left = PtrToStr(*this);
  other = PtrToStr(c);
  
  return(left != other);
}

