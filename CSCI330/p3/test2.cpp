#include "p3.h"

using namespace std;

void TestCopy(CreatureClass* temp);

int main( )
{
  Dice::ReadRollsFromFile( );
// //   
// //   CreatureClass* c[14];
// //   
// //   
// //   c[0] = new Human("");
// //   
// //   c[1] = new Human("H11");
// //   
// //   c[2] = new HalfElf("FF2");
// //   
// //   c[3] = new Elf("EE3", VocRules::FTR);
// //   
// //   c[4] = new Orc("OO4", VocRules::WIZ);
// //   
// //   c[5] = new Elf("EE5", VocRules::NNE);
// // 
// //   c[6] = new Troll("TT6");
// //   
// //   c[7] = new Ogre("GG7");
// //   
// //   c[8] = new Human("HH8", static_cast<VocRules::VocType>(15));
// //   
// //   c[9] = new Human("HH9", static_cast<VocRules::VocType>(19));
// //   
// //   c[10] = new Human("HH10", static_cast<VocRules::VocType>(5));
// //   
// //   c[11] = new Orc("OO11", VocRules::ROG);
// //   
// //   c[12] = new HalfElf("FF12", VocRules::BBN);
// //   
// //   c[13] = new Elf("EE13", VocRules::CLR);
// //   
// //   
// //   for(int i = 0; i < 14; i++)
// //   {
// //     c[i]->Write(cout);
// //     cout << endl;
// //   }
// //   
// //   EquipClass* t0 = new WpnClass("Crossbow");
// //   
// //   if(!(c[1]->FindEquipment(t0)));
// //     cout << c[1]->Weapon( ) << endl;
// //   
// //   c[1]->Write(cout);
// //   
// //   EquipClass* t1 = new ArmorClass("Buckler");
// //   
// //   if(!(c[1]->FindEquipment(t1)))
// //     cout << c[1]->Armor( ) << endl;
// //   
// //   c[1]->Write(cout);
// //   
// //   EquipClass* t2 = new WpnClass("Javelin");
// //   
// //   if(!(c[1]->FindEquipment(t2)))
// //     cout << c[1]->Weapon( ) << endl;
// //   
// //   c[1]->Write(cout);
// //   
// //   EquipClass* t3 = new ArmorClass("Lamellar");
// //   
// //   if(!(c[1]->FindEquipment(t3)))
// //     cout << c[1]->Armor( ) << endl;
// //   
// //   c[1]->Write(cout);
// //   
// //   EquipClass* t4 = new WpnClass("Dagger");
// //   
// //   if(!(c[1]->FindEquipment(t4)))
// //     cout << c[1]->Weapon( ) << endl;
// //   
// //   c[1]->Write(cout);
// //   
// //   EquipClass* t5 = new ArmorClass("Leather");
// //   
// //   if(!(c[1]->FindEquipment(t5)))
// //     cout << c[1]->Armor( ) << endl;
// //   
// //   c[1]->Write(cout);
// //   
// //   dynamic_cast<Human*>(c[1])->SellEquipment("Poop");
// //   
// //   TestCopy(c[1]);
// //   
// //   dynamic_cast<Human*>(c[1])->Write(cout);
// //   
// //   
// //   
// //   
// //   
// // 
// //   cout << "\n\n\n\n";
// //   
// //   Troll segfault("T24");
// //   
// //   EquipClass* ret = NULL;
// // 
// //   EquipClass* cbow = new WpnClass("Crossbow");
// //   
// //   EquipClass* jav = new WpnClass("Javelin");
// //   
// //   string str;
// // 
// //   
// //   cout << "\n\nBASE\n*******\n\n";
// //   segfault.Write(cout);
// //   cout << "******\n\n";
// //   
// //   
// // 
// //   
// //   
// //   cout << "Finding: " << cbow->Name( ) << endl << "******" << endl << endl;
// //   
// //   ret = segfault.FindEquipment(cbow);
// //   
// //   cout << "Checking return: \n******\n";
// //   
// //   if(!ret)
// //     cout << "return = NULL" << endl;
// //   else 
// //     cout << "return name: " << ret->Name( ) << endl;
// //   
// //   cout << "Deleting return: \n******\n";
// // 
// //   delete ret;
// //   
// //   cout << "Weapon: \n******\n";
// //   
// //   cout << segfault.Weapon( ) << "\n";
// // 
// //   EquipClass* ret1 = NULL;
// //   
// //   
// // 
// //   
// //   
// //   cout << "Creature: \n******\n\n";
// //   
// //   segfault.Write(cout);
// //   
// //   cout << "Finding: " << jav->Name( ) << "\n******\n"; 
// // 
// //   ret1 = segfault.FindEquipment(jav);
// //   
// //   cout << "Checking return: \n******\n";
// //   
// //   if(!ret1)
// //     cout << "return NULL" << endl << endl;
// //   else 
// //     cout << "return name: " << ret1->Name( ) << endl << endl;
// //   
// //   cout << "Deleting return: \n******\n";
// // 
// //   delete ret1;
// //   
// //   cout << "Weapon: \n******\n\n";
// //   
// //   cout << endl << segfault.Weapon( ) << "\n\n";
// // 
// //   
// // 
// //   
// //     
// //   
// //   ret1 = segfault.FindEquipment(new WpnClass("Club"));
// //   
// //   segfault.Write(cout);
// // 
// //   cout << ret1->Name( ) << endl << endl;  
// // 
// // 
// // 
// // 
// //   
// //   Human aa("H0r"), ab("e1r"), ac("F1r"), ad("O5r"), ae("T44r");
// //   
// //   cout << " < : " << (aa < ab) << ", " << (aa < ac) << ", " << (aa < ad) << ", " << (aa < ae) << endl << endl;
// //   
// //   cout << " > :  " << (aa > ab) << ", " << (aa > ac) << ", " << (aa > ad) << ", " << (aa > ae) << endl << endl;
// //   
// //   cout << " <= :" << (aa <= ab) << ", " << (aa <= ac) << ", " << (aa <= ad) << ", " << (aa <= ae) << endl << endl;
// //   
// //   cout << " >= :" << (aa >= ab) << ", " << (aa >= ac) << ", " << (aa >= ad) << ", " << (aa >= ae) << endl << endl;
// //   
// //   cout << " == : " << (aa == ab) << ", " << (aa == ac) << ", " << (aa == ad) << ", " << (aa == ae) << endl << endl;
// //   
// //   cout << " != : " << (aa != ab) << ", " << (aa != ac) << ", " << (aa != ad) << ", " << (aa != ae) << endl << endl;
// //   
// //   
   Human H12("H12");
// //   
   cout << "GP: " << H12.GP( ) << endl;
// //   
   cout << "UPDATE GP: " << H12.UpdateGP(5) << endl;
// //   
   cout << "GP: " << H12.GP( ) << endl;
// //   
   H12.UpdateXP(999);
// //   
   H12.Write(cout);
// //   
   H12.UpdateHP(19);
// //   
   cout << H12.HP( ) << endl;
// //   
// //   Troll balls("");
// //   
// //   cout << balls.UpdateGP(23) << endl;
// //   
// //   
// //   
// //   Dice::SeeRolls( );
// //   
// //   Elf sack("E13");
// //   
// //   sack.Write(cout);
// //   
// //   cout << "UPDATE XP (15000): " << sack.UpdateXP(15000) << endl;
// //   
// //   cout << sack.HP( ) << endl << endl;
// //   
// //   HalfElf helf("F14");
// //   
// //   helf.Write(cout);
// //   
// //   helf.UpdateXP(2600001);
// //   
// //   cout << helf.HP( ) << endl << endl;
// //   
   Human skillTest("H18");
// //   
   skillTest.Amnesia( );
// //   
   cout << skillTest.AddSkill("balance")<< endl;
// //   
   cout << skillTest.AddSkill("concentration")<< endl;
// //   
   cout << skillTest.AddSkill("heal")<< endl;
// //   
   cout << skillTest.AddSkill("jump")<< endl;
// //   
   cout << skillTest.AddSkill("open lock")<< endl;
// // 
// //   
   cout << skillTest.SkillCheck("balance")<< endl;
 //   
   cout << skillTest.SkillCheck("concentration")<< endl;
// //   
   cout << skillTest.SkillCheck("heal")<< endl;
// //   
   cout << skillTest.SkillCheck("jump")<< endl;
// //   
   cout << skillTest.SkillCheck("open lock") << endl;
// //   
   cout << skillTest.SkillCheck("search") << endl << endl;
// //   
// //   Human E1("H22");
// //   
// //   cout << E1.Weapon( ) << endl;
// //   
// //   cout << E1.HasWeapon( ) << endl;
// //   
// //   E1.Write(cout);
// //   
// //   vector<string> inventory = E1.EquipInventory( );
// //   
// //   for(int i = 0; i < inventory.size( ); i++)
// //     cout << inventory[i] << " ";
// //   
// //   if(E1.LoseEquipment( ) == NULL);
// //     cout << "NULL" << endl;
// //   
// //   
  
  Elf Todd("O30");
  
  
 Todd.FindEquipment(new WpnClass("Uzi"));
 
 Todd.Write(cout);
  
 Todd.FindEquipment(new ArmorClass("Padded"));
 
 Todd.Write(cout);

 Todd.FindEquipment(new ArmorClass("Leather"));

 Todd.Write(cout);
 
 Todd.FindEquipment(new ArmorClass("lamellar"));

 Todd.Write(cout);
 
 Todd.FindEquipment(new WpnClass("javelin"));

 Todd.Write(cout);
 
 Todd.FindEquipment(new WpnClass("dagger"));

 Todd.Write(cout);
 
 Todd.FindEquipment(new WpnClass("crossbow"));

 Todd.Write(cout);
 
 Todd.FindEquipment(new ArmorClass("buckler"));
 
 Todd.Write(cout);
 
//  Todd.SellEquipment("buckler");
//  
//  cout << Todd.GP( ) << endl;
//  
//  Todd.SellEquipment("Crossbow");
//  
//  Todd.Write(cout);
//  
//  cout << Todd.GP( ) << endl;
//  
//  Todd.SellEquipment("Lamellar");
//  
//  Todd.Write(cout);
//  
//  cout << Todd.GP( ) << endl;
//  
//  Todd.SellEquipment("Javelin");
//  
//  Todd.Write(cout);
//  
//  cout << Todd.GP( ) << endl;
//  
//  Todd.SellEquipment("Leather");
//  
//  Todd.Write(cout);
//  
//  cout << Todd.GP( ) << endl;
//  
//  Todd.SellEquipment("half-plate");
//  
//  cout << Todd.GP( ) << endl;
//  
//  Todd.SellEquipment("Chain");
//  
//  cout << Todd.GP( ) << endl;


// Elf C1("E32");
// 
// C1.FindEquipment(new WpnClass("UZI"));
// 
// cout << C1.Weapon( ) << endl;
// 
// cout << C1.InitiativeCheck( ) << endl;
// 
// cout << C1.Defense( ) << endl;
// 
// cout << C1.SavingThrow(1) << endl;
// 
// cout << C1.SavingThrow(2) << endl;
// 
// cout << C1.SavingThrow(3) << endl;
// 
// cout << C1.AttackRoll( ) << endl;
// 
// cout << C1.Damage( ) << endl;
// 
// C1.FindEquipment(new WpnClass("hatchet"));
// 
// cout << C1.AttackRoll( ) << endl;
// 
// cout << C1.Damage( ) << endl;
// 
// C1.LoseWeapon( );
// 
// cout << C1.AttackRoll( ) << endl;
// 
// cout << C1.Damage( ) << endl;
// 
// cout << "\n\n\n\n";
// 
// Troll C17("T33");
// 
// C17.FindEquipment(new ArmorClass("Thick Skin"));
// 
// cout << C17.InitiativeCheck( ) << endl;
// 
// cout << C17.Defense( ) << endl;
// 
// cout << C17.SavingThrow(1) << endl;
// 
// cout << C17.SavingThrow(2) << endl;
// 
// cout << C17.SavingThrow(3) << endl;
// 
// C17.FindEquipment(new WpnClass("Uzi"));
// 
// cout << C17.AttackRoll( ) << endl;
// 
// cout << C17.Damage( ) << endl;
// 
// C17.FindEquipment(new WpnClass("Hatchet"));
// 
// cout << C17.AttackRoll( ) << endl;
// 
// cout << C17.Damage( ) << endl;
// 
// C17.LoseWeapon( );
// 
// cout << C17.AttackRoll( ) << endl;
// 
// cout << C17.Damage( ) << endl;







// cout << "\n\n\n\n";
//  
//  
//  
//  Todd.SellEquipment("Buckler"); 
 

  
  cout << "CHANGE EQUIPMENT\n***********\n\n";
  
  cout << Todd.UpdateHP(-100);
  
  cout << Todd.ChangeEquipment("Buckler");
  
  Todd.UpdateHP(100);
  
  cout << Todd.ChangeEquipment("uzi") << endl;
  
  cout << Todd.ChangeEquipment("dagger") << endl;
  
  cout << Todd.ChangeEquipment("Lamellar") << endl;
  
  cout << Todd.ChangeEquipment("fuckyou") << endl;
  
  cout << Todd.ChangeEquipment("Javelin") << endl;
  
  Todd.Write(cout);
  
  
  
//   cout << Todd.ChangeEquipment("Javelin") << endl << endl << endl;
  
//   Todd.LoseWeapon( );
//   Todd.LoseArmor( );
//   
//   Todd.UpdateHP(-5);
//   
//   Todd.Write(cout);
//   
//   Todd.ChangeEquipment("Leather");
//   
//   Todd.Write(cout);
//   
// //   cout << "Armor: " << Todd.Armor( ) << endl;
//   
//   Todd.ChangeEquipment("Dagger");
//   
//   Todd.Write(cout);
//   
// //   cout << "Weapon: " << Todd.Weapon( ) << endl;
//   
//   cout << Todd.ChangeEquipment("uzi") << endl;
//   
//   Todd.Write(cout);
//   
// //   cout << "Weapon: " << Todd.Weapon( ) << endl;
//   
//   cout << Todd.ChangeEquipment("dagger") << endl;
//   
//   Todd.Write(cout);
//   
// //   cout << "Weapon: " << Todd.Weapon( ) << endl;
//   
//   cout << Todd.ChangeEquipment("Lamellar") << endl;
//   
//   Todd.Write(cout);
//   
// //   cout << "Armor: " << Todd.Armor( ) << endl;
//   
//   cout << Todd.ChangeEquipment("fuckyou") << endl;
//   
//   Todd.Write(cout);
//   
//   cout << Todd.ChangeEquipment("Javelin") << endl;
//   
//   Todd.Write(cout);
//   
// //   cout << "Weapon: " << Todd.Weapon( ) << endl;
//   
//   EquipClass* d_lete = NULL;
//   
//   cout << Todd.ChangeEquipment("half-plate") << endl;
//   
//   Todd.Write(cout);
//   
//   cout << Todd.ChangeEquipment("Chain") << endl;
//   
//   Todd.Write(cout);
//   
//   cout << "\n\n\n\n\n\n\n\n\n\n";
//   
//   HalfElf Y1("F28");
//   
//   Y1.UpdateGP(6);
//   
//   d_lete = Y1.BuyEquipment(new ArmorClass("Buckler"));
//   
//   delete d_lete;
//   
//   d_lete = NULL;
//   
//   cout << endl << Y1.GP( ) << endl;
//   
//   cout << Y1.Armor( ) << endl;
//   
//   Y1.UpdateGP(9);
//   
//   d_lete = Y1.BuyEquipment(new WpnClass("CrossBow"));
//   
//   delete d_lete;
//   
//   d_lete = NULL;
//   
//   Y1.Write(cout);
//   
//   Y1.UpdateGP(20);
//   
//   d_lete = Y1.BuyEquipment(new ArmorClass("lamellar"));
//  
//   delete d_lete;
//   
//   d_lete = NULL;
//   
//   Y1.Write(cout);
//   
//   Y1.UpdateGP(4);
//   
//   d_lete = Y1.BuyEquipment(new WpnClass("Javelin"));
//   
//   delete d_lete;
//   
//   d_lete = NULL;
//   
//   Y1.Write(cout);
//   
//   cout << Y1.Weapon( ) << endl;
//   
//   Y1.UpdateGP(11);
//   
//   d_lete = Y1.BuyEquipment(new ArmorClass("llamellar"));
//   
//   delete d_lete;
//   
//   d_lete = NULL;
//   
//   cout << Y1.GP( ) << endl;
//   
//   Y1.Write(cout);
  
  
  
  
  
  
  
  
  
  
//   cout << "BUY EQUIPMENT\n***********\n\n";
//   
//   Human buy("buy");
//   
//   buy.UpdateGP(9999);
//   
//   buy.BuyEquipment(new WpnClass("uzi"));
//    
//   buy.BuyEquipment(new WpnClass("dagger"));
//    
//   buy.BuyEquipment(new ArmorClass("Lamellar"));
//    
//   buy.BuyEquipment(new WpnClass("fuckyou"));
//        
//   buy.BuyEquipment(new WpnClass("Javelin"));
//   
//   buy.Write(cout);
//   
//   buy.SellEquipment("uzi");
//       
//   buy.SellEquipment("dagger");
//       
//   buy.SellEquipment("Lamellar");
//       
//   buy.SellEquipment("fuckyou");
//       
//   buy.SellEquipment("Javelin");
//   
//   buy.Write(cout);
//   
//   
//   HalfElf S26("F19");
//   
//   S26.UpdateHP(-6);
//   
//   S26.Write(cout);
//   
//   cout << S26.AddSkill("bluff") << endl;
//   
//   cout << S26.SkillCheck("bluff") << endl;
//   
//   cout << S26.AddSkill("Search") << endl;
//   
//   cout << S26.SkillCheck("Search") << endl;


  

  
}

void TestCopy(CreatureClass* temp)
{
  dynamic_cast<Human*>(temp)->Write(cout);
}

