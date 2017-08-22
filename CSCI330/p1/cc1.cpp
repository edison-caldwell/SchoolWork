#include "cc1.h"

using namespace std;

//*******************************************************************************************
//Stat Declarations**************************************************************************
const int CreatureClass::NUM_DICE_HP_HUMANOID = 1;          //Number of dice rolled for humanoid hp roll
const int CreatureClass::NUM_DICE_GP = 1;                   //number of dice rolled for gp roll
const int CreatureClass::NUM_DICE_HP_TROLL = 6;             //number of dice rolled for troll hp
const int CreatureClass::NUM_DICE_HP_OGRE = 4;              //number of dice rolled for ogre hp
const int CreatureClass::NUM_DICE_AB = 3;                   //number of dice rolled for abilities
const int CreatureClass::NUM_DICE_SIDES[5] = {4,6,8,10,12}; //array of dice sides indexed by DiceType
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




const CreatureClass::VocType CreatureClass::DEF_VOC[6] = 
{
  //Array of default vocations indexed by race
  /*HUMAN*/   FTR,
  /*ELF*/     WIZ,
  /*HALFELF*/ ROG,
  /*ORC*/     BBN,
  /*TROLL*/   NNE,
  /*OGRE*/    NNE
};




const int CreatureClass::HIT_DIES[6] = 
{
  //Array of hit dies for hp indexed by voc
  
  /*NNE*/  8,
  /*BBN*/ 12, 
  /*CLR*/  8,
  /*FTR*/ 10,
  /*ROG*/  6,
  /*WIZ*/  4,
};



//*******************************************************************************************
//METHOD IMPLEMENTATIONS*********************************************************************
//*******************************************************************************************
CreatureClass::CreatureClass( )
//default constructor
//PRE: NONE;
//POST: OBJECT IS CREATED WITH DEFAULT VALUES OF:
//ROW = -1, COLUMN = -1, NAMEPTR = NULL, RACE = HUMAN, VOC = FTR, XP = 0 AND ROLLS FOR ABILITY SCORES, HP, AND GP
{
  namePtr = NULL;
  race = HUMAN;
  voc = FTR;
  
  RollStats();
}




CreatureClass::CreatureClass(string name, RaceType race_type, VocType voc_type)
//parameterized constructor (name, race, voc)
//PRE: PARAMETERS ARE CORRECT TYPES
//POST: OBJECT INSTANTIATED WITH PARAMETERIZED VALUES. IF RACE IS NOT PARAMETERIZED, RACE AND VOC ARE DEFAULTED.
//      IF ONLY VOC IS NOT PARAMETERIZED 
{
  //*******************TRIMMING WHITESPACE FROM NAME******
  name = GameSpace::TrimStr(name);
  
  //*******************CHECKING NAME LENGTH***************
  if(name.length( ) > NAME_MAX)
    name = name.substr(0, NAME_MAX);
  
  //*******************DETERMINING NAME*******************
  namePtr = NULL;
  namePtr = new char[name.length( )+1];
  strcpy(namePtr, name.c_str( ));
  
  //*******************DETERMINING RACE*******************
  if(race_type > OGRE || race_type < HUMAN)
    race = HUMAN;
  else
    race = race_type;
  
  //*******************DETERMINING VOC******************* 
  
  
  if(Humanoid( ))
  {
    if(voc_type == NNE || voc_type < NNE || voc_type > WIZ)
      voc = DEF_VOC[race];
    else
      voc = voc_type;
  }
  else if(Monster( ))
    voc = NNE;
  
  //*******************ROLLING FOR STATS*******************
  RollStats( );
}




CreatureClass::CreatureClass(const CreatureClass& c)
//COPY CONSTURCTOR
//PRE: OBJECT EXISTS 
//POST: NEW OBJECT IS DEEP COPY OF ORIGINAL
{
  if(c.namePtr == NULL)
    namePtr = NULL;
  else
  {
    namePtr = NULL;
    namePtr = new char[strlen(c.namePtr) + 1];
    strcpy(namePtr, c.namePtr);
  }
  softCopy(c);
}




CreatureClass::~CreatureClass( )
{
  delete [] namePtr;
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
  return(race != TROLL && race != OGRE) ;
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
  return(statScores[hp] == DYING_DISABLED_LIM);
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
{
  string name;
  
  if(!namePtr)
    name = "";
  else
    name = namePtr;
  
  if(Humanoid( ))
  {
    for(int i = DEX; i <= WIS; i++)
      abilityScores[i] = Dice::Roll(name, static_cast<RollType>(i), NUM_DICE_AB, NUM_DICE_SIDES[D6]) + (AB_ADJ[race][i]);
    

    statScores[hp] = Dice::Roll(name, GameSpace::HP, NUM_DICE_HP_HUMANOID, HIT_DIES[voc]);
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
      statScores[hp] = Dice::Roll(name, GameSpace::HP, NUM_DICE_HP_TROLL, HIT_DIES[voc]) + TROLL_HP_MOD;
      
      statScores[level] = TROLL_LEVEL;
      
      for(int i = DEX; i <= WIS; i++)
	abilityScores[i] = AB_ADJ[TROLL][static_cast<AbilityType>(i)];
    }
    else if(race == OGRE)
    {
      statScores[hp] = Dice::Roll(name, GameSpace::HP, NUM_DICE_HP_OGRE, HIT_DIES[voc]) + OGRE_HP_MOD;
      
      statScores[level] = OGRE_LEVEL;
      
      for(int i = DEX; i <= WIS; i++)
	abilityScores[i] = AB_ADJ[OGRE][static_cast<AbilityType>(i)];
    }
  }
  statScores[row] = DEF_ROW;
  statScores[column] = DEF_COL;
  statScores[xp] = DEF_XP;
}



//*******************************************************************************************
//OVERLOADED OPERATORS***********************************************************************
//*******************************************************************************************
bool CreatureClass::operator==(const CreatureClass& right) const
//COMPARES RIGHT OBJECT TO LEFT
//PRE: RIGHT HAS A VALUE FOR NAMEPTR
//POST: IF NAMEPTR AND RIGHT.NAMEPTR ARE THE SAME THING RETURN TRUE,  ELSE FALSE
{
  bool temp;
  
  string left, other;
  
  if(namePtr == NULL)
    left = "";
  else
    left = namePtr;
  
  if(right.namePtr == NULL)
    other = "";
  else
    other = right.namePtr;
  
  transform(left.begin(), left.end(), left.begin(), ::toupper);
  transform(other.begin(), other.end(), other.begin(), ::toupper);
  
  return(left == other);
}  




bool CreatureClass::operator!=(const CreatureClass& right) const
//COMPARES RIGHT OBJECT TO LEFT
//PRE:RIGHT HAS A VALUE FOR NAMEPTR
//POST: IF NAMPTR AND RIGHT.NAMEPTR ARE THE SAME THING RETURN FALSE,  ELSE TRUE
{ 
  string left, other;
  
  if(namePtr == NULL)
    left = "";
  else
    left = namePtr;
  
  if(right.namePtr == NULL)
    other = "";
  else
    other = right.namePtr;
  
  transform(left.begin(), left.end(), left.begin(), ::toupper);
  transform(other.begin(), other.end(), other.begin(), ::toupper);
  
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
    delete[] namePtr;
    namePtr = NULL;
    if ((c.namePtr != NULL) && (c.namePtr[0] != '\0'))
    {
      len = strlen(c.namePtr);
      namePtr = new char[len+1];
      strcpy(namePtr, c.namePtr);
    }
  }
  softCopy(c);
}




ostream& operator<<(ostream& out, const CreatureClass& c)
//OUTPUTS ALL VALUES OF OBJECT
//PRE: OBJECT EXISTS
//POST: ALL VALUES OUTPUT TO SCREEN DELIMINATED BY '#'
{
  out << c.race << "#" << c.voc << "#";
  
  if(c.namePtr == NULL)
    out << "#(";
  else
    out << c.namePtr << "#("; 
  
  out << c.statScores[CreatureClass::row] << "," << c.statScores[CreatureClass::column] << ")#";
  out << c.statScores[CreatureClass::hp] << "#";
  out << c.statScores[CreatureClass::level] << "#";
  out << c.statScores[CreatureClass::xp] << "#";
  out << c.statScores[CreatureClass::gp] << "#";
  out << c.abilityScores[CreatureClass::DEX] << "#";
  out << c.abilityScores[CreatureClass::CON] << "#";
  out << c.abilityScores[CreatureClass::INT] << "#";
  out << c.abilityScores[CreatureClass::CHA] << "#";
  out << c.abilityScores[CreatureClass::STR] << "#";
  out << c.abilityScores[CreatureClass::WIS] << "#" << endl << endl << endl;
}