#include "handle4.h"

/*****************************************************************************/
Creature::Creature( )
{
  handle = new Human("");
}
/*****************************************************************************/



/*****************************************************************************/
Creature::Creature(string name, RaceType inRace, VocRules::VocType voc): handle(NULL)
{
//   if(inRace == HUMAN || inRace == ELF || inRace == HALFELF || inRace == ORC || inRace == TROLL || inRace == OGRE)
  if(ValidRace(inRace))
    race = inRace;
  else race = HUMAN;
  
  cout << race << endl;
  
  switch(race)
  {
    case HUMAN   : handle = new Human(name, voc);
    break;
	
    case ELF     : handle = new Elf(name, voc);
    break;         
                   
    case HALFELF : handle = new HalfElf(name, voc);
    break;         
	           
    case ORC     : handle = new Orc(name, voc);
    break;         
	           
    case OGRE    : handle = new Ogre(name);
	break;     
	           
    case TROLL   : handle = new Troll(name);
    break;
  }
  
  
  
}
/*****************************************************************************/



/*****************************************************************************/
Creature::Creature(const Creature& c): handle(NULL)
{
  Copy(c);
}
/*****************************************************************************/



/*****************************************************************************/
Creature::Creature(CreatureClass* ptr): handle(ptr)
{

}
/*****************************************************************************/



/*****************************************************************************/
Creature::~Creature( )
{
  delete handle;
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::operator==(const Creature& c)
{
  return handle->operator==(*c.handle);
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::operator!=(const Creature& c)
{
  return handle->operator!=(*c.handle);
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::operator<(const Creature& c)
{
  return handle->operator<(*c.handle);
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::operator<=(const Creature& c)
{
  return handle->operator<=(*c.handle);;
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::operator>(const Creature& c)
{
  return handle->operator>(*c.handle);
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::operator>=(const Creature& c)
{
  return handle->operator>=(*c.handle);
}
/*****************************************************************************/



/*****************************************************************************/
Creature& Creature::operator=(const Creature& c)
{
  if(this != &c)
  {
    Copy(c);
  }
  
  return *this;
}
/*****************************************************************************/



/*****************************************************************************/
Creature::RaceType Creature::StrToRace(string str)
{
  RaceType temp = HUMAN;
  
  transform(str.begin( ), str.end( ), str.begin( ), ::toupper);
  
  if(str == "HUMAN")
    temp = HUMAN;
  else if(str == "ELF")
    temp = ELF;
  else if(str == "HALFELF")
    temp = HALFELF;
  else if(str == "ORC")
    temp = ORC;
  else if(str == "TROLL")
    temp = TROLL;
  else if(str == "OGRE")
    temp = OGRE;

  
  return temp;
}
/*****************************************************************************/



/*****************************************************************************/
string Creature::RaceToStr(RaceType r)
{ 
  string str = "";
  
  switch(r)
  {
    case HUMAN   : str = "HUMAN";
		  break;
    case ELF     : str = "ELF";
		  break;
    case HALFELF : str = "HALFELF";
		  break; 
    case ORC     : str = "ORC";
		  break;
    case TROLL   : str = "TROLL";
		  break;
    case OGRE    : str = "OGRE";
		  break;

  }
  
  return str; 
}
/*****************************************************************************/



/*****************************************************************************/
string Creature::Race( ) const
{
  return RaceToStr(race);
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::VocInt( ) const
{
  string voc;
  int temp;
  
  if(IsHumanoid( ) && handle)
  {
    Humanoid* h = dynamic_cast<Humanoid*>(handle);
    
    voc = h->Voc( );
    
    transform(voc.begin( ), voc.end( ), voc.begin( ), ::toupper);
    
    if(voc == "NNE")
      temp = 0;
    else if(voc == "BBN")
      temp = 1;
    else if(voc == "CLR")
      temp = 2;
    else if(voc == "FTR")
      temp = 3;
    else if(voc == "ROG")
      temp = 4;
    else if(voc == "WIZ")
      temp = 5;
  }
  else 
    temp = 0;
  
  return temp;
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::RaceInt( ) const
{
  return static_cast<int>(race);
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::IsHumanoid( ) const
{
  return (race != TROLL && race != OGRE);
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::IsMonster( ) const
{
  return (race == TROLL || race == OGRE);
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::ValidRace(RaceType temp)
{
  static_cast<int>(temp);
  return (temp > -1 && temp < 6);
}
/*****************************************************************************/



/*****************************************************************************/
void Creature::Copy(const Creature& c)
{
  delete handle;
  
  handle = NULL;
  
  handle = c.handle->Clone( );
  
  race = c.race;
}
/*****************************************************************************/



/*****************************************************************************/
string Creature::Name( ) const
{
  if(handle)
    return handle->Name( );
  else
    return "";
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::Row( ) const
{
  if(handle)
    return handle->Row( );
  else
    return 0;
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::Column( ) const
{
  if(handle)
    return handle->Column( );
  else
    return 0;
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::HP( ) const
{
  if(handle)
    return handle->HP( );
  else
    return 0;
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::Ability(CreatureClass::AbilityType ability) const
{
  if(handle)
    return handle->Ability(ability);
  else
    return 0;
}
/*****************************************************************************/



/*****************************************************************************/
string Creature::Weapon( ) const
{
  if(handle)
    return handle->Weapon( );
  else
    return "";
}
/*****************************************************************************/



/*****************************************************************************/
string Creature::Armor( ) const
{
  if(handle)
    return handle->Armor( );
  else
    return "";
}
/*****************************************************************************/



/*****************************************************************************/
vector<int> Creature::Abilities( ) const
{
  vector<int> temp;
  if(handle)
    return handle->Abilities( );
  else
    return temp;
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::SkillCheck(string skill) const
{
  if(handle)
    return handle->SkillCheck(skill);
  else
    return 0;
}
/*****************************************************************************/



/*****************************************************************************/
vector<string> Creature::Skills( )const
{
  vector<string> temp;
  
  if(handle)
    return handle->Skills( );
  else
    return temp;
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::Disabled( ) const
{
  if(handle)
    return handle->Disabled( );
  else
    return false;
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::Dying( ) const
{
  if(handle)
    return handle->Dying( );
  else
    return false;
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::Dead( ) const
{
  if(handle)
    return handle->Dead( );
  else
    return false;
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::Active( ) const
{
  if(handle)
    return handle->Active( );
  else 
    return false;
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::HasWeapon( ) const
{
  if(handle)
    return handle->HasWeapon( );
  else
    return false;
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::HasArmor( ) const
{
  if(handle)
    return handle->HasArmor( );
  else
    return false;
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::SetCell(int newRow, int newCol)
{
  if(handle)
    return handle->SetCell(newRow, newCol);
  else
    return false;
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::UpdateHP(int mod)
{
  if(handle)
    return handle->UpdateHP(mod);
  else
    return 0;
}
/*****************************************************************************/



/*****************************************************************************/
WpnClass* Creature::LoseWeapon( )
{
  if(handle)
    return handle->LoseWeapon( );
  else
    return NULL;
}
/*****************************************************************************/



/*****************************************************************************/
ArmorClass* Creature::LoseArmor( )
{
  if(handle)
    return handle->LoseArmor( );
  else
    return NULL;
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::AddSkill(string skill)
{
  if(handle)
  {
    return handle->AddSkill(skill);
  }
  else
    return false;
}
/*****************************************************************************/



/*****************************************************************************/
void Creature::Amnesia( )
{
  if(handle)
    handle->Amnesia( );
}
/*****************************************************************************/



/*****************************************************************************/
EquipClass* Creature::FindEquipment(EquipClass* requip)
{
  if(handle)
    return handle->FindEquipment(requip);
  else
    return NULL;
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::InitiativeCheck( ) const
{
  if(handle)
    return handle->InitiativeCheck( );
  else
    return 0;
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::AttackRoll( ) const
{
  if(handle)
    return handle->AttackRoll( );
  else
    return 0;
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::SavingThrow(int kind) const
{
  if(handle)
    return handle->SavingThrow(kind);
  else
    return 0;
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::Defense( ) const
{
  if(handle)
    return handle->Defense( );
  else
    return 0;
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::Damage( ) const
{
  if(handle)
    return handle->Damage( );
  else
    return 0;
}
/*****************************************************************************/



/*****************************************************************************/
void Creature::Write(ostream& out) const
{
  if(handle)
    handle->Write(out);
}
/*****************************************************************************/



/*****************************************************************************/
string Creature::Voc( ) const
{
  Humanoid* h = dynamic_cast<Humanoid*>(handle);
    
  if(h)
    return h->Voc( );
  else 
    return "NNE";
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::Level( ) const
{
  Humanoid* h = dynamic_cast<Humanoid*>(handle);
  
  if(h)
    return h->Level( );
  else
    return 0;
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::GP( ) const
{
  Humanoid* h = dynamic_cast<Humanoid*>(handle);
  
  if(h)
    return h->GP( );
  else
    return 0;
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::XP( ) const
{
  Humanoid* h = dynamic_cast<Humanoid*>(handle);
  
  if(h)
    return h->XP( );
  else
    return 0;
}
/*****************************************************************************/



/*****************************************************************************/
vector<string> Creature::Pack( ) const
{
  vector<string> temp;
  
  Humanoid* h = dynamic_cast<Humanoid*>(handle);
  
  if(h)
    return h->Pack( );
  else
    return temp;
}
/*****************************************************************************/



/*****************************************************************************/
vector<string> Creature::EquipInventory( ) const
{
  vector<string> temp;
  
  Humanoid* h = dynamic_cast<Humanoid*>(handle);
  
  if(h)
    return h->EquipInventory( );
  else
    return temp;
}
/*****************************************************************************/



/*****************************************************************************/
bool Creature::ChangeEquipment(string requip)
{
  Humanoid* h = dynamic_cast<Humanoid*>(handle);
  
  if(h)
    return h->ChangeEquipment(requip);
  else
    return false;
}
/*****************************************************************************/



/*****************************************************************************/
EquipClass* Creature::BuyEquipment(EquipClass* requip)
{
  Humanoid* h = dynamic_cast<Humanoid*>(handle);
  
  if(h)
    return h->BuyEquipment(requip);
  else
    return NULL;
}
/*****************************************************************************/



/*****************************************************************************/
EquipClass* Creature::SellEquipment(string requip)
{
  Humanoid* h = dynamic_cast<Humanoid*>(handle);
   
  if(h) 
    return h->SellEquipment(requip);
  else
    return NULL;
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::UpdateGP(int mod)
{
  Humanoid* h = dynamic_cast<Humanoid*>(handle);
  
  if(h)
    return h->UpdateGP(mod);
  else
    return 0;
}
/*****************************************************************************/



/*****************************************************************************/
int Creature::UpdateXP(int mod)
{
  Humanoid* h = dynamic_cast<Humanoid*>(handle);
  
  if(h)
    return h->UpdateXP(mod);
  else
    return 0;
}
/*****************************************************************************/


























































  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
