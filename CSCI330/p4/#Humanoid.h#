#ifndef _HUMANOIDH
#define _HUMANOIDH

#include "cc4.h"
#include "SkillRules.h"

class PackClass;

class Humanoid: public CreatureClass
{
  
public:
  
  virtual Humanoid* Clone( ) const;
  
  virtual ~Humanoid( );
  
  string Voc( )const;
  
  int Level( ) const;
  
  int GP( ) const;
  
  int XP( ) const;
  
  vector<string> Pack( ) const;
  
  vector<string> EquipInventory( ) const;
  
  bool ChangeEquipment(string);
  
  EquipClass* BuyEquipment(EquipClass*);
  
  EquipClass* SellEquipment(string);
  
  virtual EquipClass* FindEquipment(EquipClass*);
  
  virtual int AttackRoll( ) const;
  
  virtual int SavingThrow(int) const;
  
  virtual void  Write(ostream&) const;
  
  int UpdateGP(int);
  
  int UpdateXP(int);
  
  Humanoid& operator=(const Humanoid&);
  
protected:
  
  Humanoid( );
  
  Humanoid(string name, VocRules::VocType voc_type, const int adjustments[], VocRules::VocType);
  
  Humanoid(const Humanoid&);
  
  void InitAbilities(const int[]);
  
  void InitVoc(VocRules::VocType);
  
  void InitLevel( );
  
  void InitGP( );
  
  void InitXP( );
  
  void InitPack(VocRules::VocType);
  
  
private:
  
  vector<string> GetDefSkills(VocRules::VocType);
  
  static void LoadVoc( );
  
  static const int LEVEL_MAX;
  
  static const int PROMOTION_TABLE [];
  
  static const int NUM_HP_ROLL; 
  
  static const int NUM_DICE_GP;
  
  static const int NUM_DICE_AB;
  
  static bool vocRead;
  
  static VocRules* voc_single;
  
  //*********PRIVATE DATA*********
  
  VocRules::VocType voc;
  
  int level;
  
  int gp;
  
  int xp;
  
  PackClass* pack;
  
};

#endif

