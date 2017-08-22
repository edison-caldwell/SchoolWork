#include "Humanoid.h"
#include "Pack.h"


const int Humanoid::LEVEL_MAX = 20;

const int Humanoid::PROMOTION_TABLE[]=
// Level 0 has 0, Level 1 base is 1, Level 2 base is 3000...
{0,1000,3000,6000,10000,16000,24000,36000,
  52000,76000,110000,160000,220000,320000,
  440000,640000,890000,1300000,1800000,2600000};
  
  const int Humanoid::NUM_HP_ROLL = 1;
  
  const int Humanoid::NUM_DICE_GP = 1;
  
  const int Humanoid::NUM_DICE_AB = 3;
  
  bool Humanoid::vocRead = false;
  
  VocRules* Humanoid::voc_single = NULL;
  
  
  void Humanoid::LoadVoc( )
  {
    voc_single = VocRules::GetVocRules( );
    
    vocRead = true;
  } 
  
  
  
  Humanoid::Humanoid(string name, VocRules::VocType voc_type, const int adjustments[], VocRules::VocType def):
  CreatureClass(name), pack(NULL)
  {
    if(!vocRead)
      LoadVoc( );
    
    ////cout << "HUMANOID  CONST\n*******************\n";
    
    pack = new PackClass;
    
    if(voc_type == VocRules::NNE || voc_type < VocRules::NNE || voc_type > VocRules::WIZ)
      voc = def;
    else
      InitVoc(voc_type);
    
    
    InitAbilities(adjustments);
    
    InitLevel( );
    
    InitGP( );
    
    InitXP( );
    
    //    InitPack(voc);
    
    CreatureClass::InitSkills(GetDefSkills(voc));
    
    int startHP = CreatureClass::RollHP(NUM_HP_ROLL, static_cast<CreatureClass::DiceType>(voc_single->HitDie(voc)), CreatureClass::AbilityMod(CreatureClass::CON));
    
    if(startHP < 1)
      startHP = 1;
    
    CreatureClass::UpdateHP(startHP);
  }
  
  
  Humanoid::Humanoid( ):
  CreatureClass("")
  {
    
  }
  
  
  
  Humanoid::~Humanoid( )
  {       
    delete pack;
  }
  
  
  
  Humanoid::Humanoid(const Humanoid& h):
  CreatureClass(h)
  {
    voc = h.voc;
    
    level = h.level;
    
    gp = h.gp;
    
    xp = h.xp; 
    
    pack = new PackClass(h.pack->GetPack( ));
    
    
  }
  
  
  
  void Humanoid::InitAbilities(const int adj[])
  {
    vector<int> scores;
    
    for(int i = CreatureClass::DEX; i <= CreatureClass::WIS; i++)
      scores.push_back(Dice::Roll(CreatureClass::Name( ), static_cast<RollType>(i), NUM_DICE_AB, CreatureClass::D6) + adj[i]);
    
    CreatureClass::InitAbilities(scores);
  }
  
  
  
  void Humanoid::InitVoc(VocRules::VocType voc_type)
  {
    voc = voc_type;
  }
  
  
  
  void Humanoid::InitGP( )
  {
    gp = 0;
    
    UpdateGP(Dice::Roll(CreatureClass::Name( ), GameSpace::GP, NUM_DICE_GP, CreatureClass::D4));  
  }
  
  
  
  void Humanoid::InitXP( )
  {
    xp = 0;
  }
  
  
  
  void Humanoid::InitLevel( )
  {
    level = 1;
  }
  
  
  
  vector<string> Humanoid::GetDefSkills(VocRules::VocType voc_type)
  {
    return CreatureClass::skillRules->DefSkills(voc_type);
  }
  
  
  
  string Humanoid::Voc( ) const
  {
    return VocRules::VocToStr(voc);
  }
  
  
  
  int Humanoid::Level( ) const
  {
    return level;
  }
  
  
  
  int Humanoid::GP( ) const
  {
    return gp;
  }
  
  
  
  int Humanoid::XP( ) const
  {
    return xp;
  }
  
  
  
  vector<string> Humanoid::Pack( ) const
  {
    return pack->ListPack( );
  }
  
  
  
  vector<string> Humanoid::EquipInventory( ) const
  {
    vector<string> temp = pack->ListPack( );
    
    if(weapon)
      temp.push_back(weapon->Name( ));
    
    if(armor)
      temp.push_back(armor->Name( ));
    
    return temp;
  }
  
  
  
  bool Humanoid::ChangeEquipment(string name)
  { 
    bool temp = false;
    
    EquipClass* equip = NULL;
    
    transform(name.begin(), name.end( ), name.begin( ), ::toupper);
    
    if(CreatureClass::Active( ))
    {
      if(!weapon && WpnClass::IsEquipment(name))
      {
	weapon = dynamic_cast<WpnClass*>(pack->DeleteEquip(name));
	
	temp = true;
      }
      else if(!armor && ArmorClass::IsEquipment(name))
      {
	armor = dynamic_cast<ArmorClass*>(pack->DeleteEquip(name));
	
	temp = true;
      }
      else if(name == weapon->Name( ) || name == armor->Name( ))
      {
	temp = true;
      }
      else if(name != weapon->Name( ) && name != armor->Name( ) && (weapon || armor))
      {
	equip = pack->DeleteEquip(name);
	
	if(equip)
	{
	  
	  if(FindEquipment(equip) == NULL)
	  {
	    temp = true;
	  }
	}
      }
    }
    
    return temp;
  }
  
  
  
  EquipClass* Humanoid::BuyEquipment(EquipClass* purchase)
  {
    ArmorClass* a = dynamic_cast<ArmorClass*>(purchase);
    WpnClass* w = dynamic_cast<WpnClass*>(purchase);
    EquipClass* temp = purchase;
    
    
    if(purchase && CreatureClass::Active( ))
    {
      if(w && WpnClass::IsEquipment(w->Name( )))
      {
	if(gp >= w->Cost( ))
	{
	  temp = FindEquipment(purchase);
	  
	  gp -= w->Cost( );  
	}
      }
      else if(a && ArmorClass::IsEquipment(a->Name( )))
      {
	if(gp >= a->Cost( ))
	{
	  temp = FindEquipment(a);
	  
	  gp += -(a->Cost( ));
	}
      }
    }
    
    return temp;
  }
  
  
  
  EquipClass* Humanoid::SellEquipment(string item)
  {
    EquipClass* temp = NULL;
    
    ArmorClass* a;
    
    WpnClass* w;
    
    transform(item.begin(), item.end( ), item.begin( ), ::toupper);
    
    if(CreatureClass::Active( ) && (WpnClass::IsEquipment(item) || ArmorClass::IsEquipment(item)))
    {
      temp = pack->DeleteEquip(item);
      
      a = dynamic_cast<ArmorClass*>(temp);
      
      w = dynamic_cast<WpnClass*>(temp);
      
      if(a)
	gp += a->Cost( );
      else if(w)
	gp += w->Cost( );
      else if(item == weapon->Name( ))
      {
	gp += weapon->Cost( );
	
	temp = LoseWeapon( );
	
      }
      else if(item == armor->Name( ))
      {	
	gp += armor->Cost( );
	
	temp = LoseArmor( );
      }
    }
    
    return temp;
  }
  
  
  
  EquipClass* Humanoid::FindEquipment(EquipClass* loot)
  {   
    EquipClass* temp = NULL;
    
    if(loot)
    {
      temp = CreatureClass::FindEquipment(loot);
      
      if(temp && temp != loot )
      {
	pack->AddEquip(temp);
	
	temp = NULL;
      }
    } 
    
    return temp;
  }
  
  
  
  int Humanoid::AttackRoll( ) const
  {
    int temp = 0;
    
    if(CreatureClass::Active( ))
    {
      temp = Dice::Roll(CreatureClass::Name( ), GameSpace::ATT, 1, CreatureClass::D20);
      
      if(weapon)
      {
	if(WpnClass::IsRange(weapon->Name( )))
	  temp += CreatureClass::AbilityMod(CreatureClass::DEX);
	else
	  temp += CreatureClass::AbilityMod(CreatureClass::STR);
      }
      else
	temp += CreatureClass::AbilityMod(CreatureClass::STR);
      
      temp += voc_single->BaseAttackBonus(voc, level);
    }
    
    if(temp < 0)
      temp = 0;
    
    return temp;
  }
  
  
  
  int Humanoid::SavingThrow(int type) const
  {
    int lastgrace = 0;
    
    if(CreatureClass::Active( ))
    {
      lastgrace += voc_single->BaseSaveBonus(voc, level, static_cast<VocRules::SavingThrowType>(type));
      
      lastgrace += Dice::Roll(CreatureClass::Name( ), GameSpace::SVTH, 1, D20);
      
      if(type == VocRules::FORT)
	lastgrace += AbilityMod(CreatureClass::CON);
      else if(static_cast<VocRules::SavingThrowType>(type) == VocRules::REFLEX)
	lastgrace += AbilityMod(CreatureClass::DEX);
      else if(static_cast<VocRules::SavingThrowType>(type) == VocRules::WILL)
	lastgrace += AbilityMod(CreatureClass::WIS);
    }
    
    return lastgrace;   
  }
  
  
  
  void Humanoid::Write(ostream& out) const
  {
    out << Voc( ) << "#";
    
    CreatureClass::Write(out);
    
    out << "\t" << level << "#" << xp << "#" << gp << "#(";
    
    pack->Write(out);
    
    out << ")#\n";
  }
  
  
  
  int Humanoid::UpdateGP(int mod)
  {
    gp += mod;
    
    if(gp<0)
      gp = 0;
    
    return gp;
  }
  
  
  
  int Humanoid::UpdateXP(int value)
  {
    
    int oneUP = 0;
    
    if(value > 0 && CreatureClass::Active( ))
    {
      xp += value;
      
      for(int i = 0; i < VocRules::LEVEL_MAX; i++)
      {
	if(xp >= PROMOTION_TABLE[i] && level <= i)
	  oneUP++;
      }
      
      if(oneUP > 0)
      {
	for(int i = 0; i < oneUP; i++)
	{
	  int mod = Dice::Roll(CreatureClass::Name( ), GameSpace::HP, 1, voc_single->HitDie(voc)) 
	  + CreatureClass::AbilityMod(CreatureClass::CON);
	  
	  if(mod < 1)
	    mod = 1;
	  
	  CreatureClass::UpdateHP(mod);
	}
      }
      
      level += oneUP;
      
    }
    return xp;
    
  }
  
  
  
  Humanoid& Humanoid::operator=(const Humanoid& h)
  {
    if(h.pack)
    {
      delete pack;
      
      pack = new PackClass(h.pack->GetPack( ));
    }
    else
    {
      delete pack;
      
      pack = NULL;
    }
    
    voc = h.voc;
    
    level = h.level;
    
    gp = h.gp;
    
    xp = h.xp;
   
  }
  
  
  
  Humanoid* Humanoid::Clone( ) const
  {
    return new Humanoid(*this);
  }
  
  
  
  
  