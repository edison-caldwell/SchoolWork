//encounter

#ifndef _ENCOUNTER
#define _ENCOUNTER

#include "handle4.h"
#include <queue>

class Encounter
{
  public:
    enum EncounterType {RESCUED, COMBAT, ST_FORT, ST_REFLEX, ST_WILL,
                    BUY_WPN, BUY_ARM, ADD_SK, AMNESIA, INC_GP, INC_XP,
                    MAGIC_CHEST, MAGIC_WAND, MAGIC_TRAP};



	static bool IsRescued( );
	static void Rescued(); 
	static void Combat(Creature *c, Creature *m); 
	static void Battle(Creature *c1, Creature *c2);
        static void SavingThrow(int dc,VocRules::SavingThrowType kind,Creature *c); 
	static EquipClass * BuyWeapon(EquipClass *e, Creature *c);
	static EquipClass * BuyArmor(EquipClass *e, Creature *c);
	static void AddSkill(string sk, Creature *c); 
	static void Amnesia(Creature *c);
	static int IncreaseGP(int amt, Creature *c);
	static void IncreaseXP(int amt, Creature *c); 
	static EquipClass *MagicChest(int amt, EquipClass* e, queue<Creature *>q);
	static void MagicWand(int amt, queue<Creature *>q); 
	static void MagicTrap(int amt, queue<Creature *>q); 
  

  private:
    Encounter();
    static bool rescued;
};



#endif
