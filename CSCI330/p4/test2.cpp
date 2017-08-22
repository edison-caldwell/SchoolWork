#include "handle4.h"

using namespace std;

void TestCopy(Creature* temp);

int main( )
{
  Dice::ReadRollsFromFile( );
  
  Creature* c[14];
  
  Creature temp("test", Creature::OGRE);
  
  temp.Write(cout);
  
  
  c[0] = new Creature("");
  
  c[1] = new Creature("HH1", Creature::HUMAN);
  
  c[2] = new Creature("FF2", Creature::HALFELF);
  
  c[3] = new Creature("EE3", Creature::ELF, VocRules::FTR);
  
  c[4] = new Creature("OO4", Creature::ORC, VocRules::WIZ);
  
  c[5] = new Creature("EE5", Creature::ELF, VocRules::NNE);

  c[6] = new Creature("TT6", Creature::TROLL);
  
  c[7] = new Creature("GG7", Creature::OGRE, VocRules::NNE);
  
  c[8] = new Creature("HH8", static_cast<Creature::RaceType>(15));
  
  c[9] = new Creature("HH9", static_cast<Creature::RaceType>(8), static_cast<VocRules::VocType>(19));
  
  c[10] = new Creature("HH10", static_cast<Creature::RaceType>(8), static_cast<VocRules::VocType>(5));
  
  c[11] = new Creature("OO11", Creature::ORC, VocRules::ROG);
  
  c[12] = new Creature("FF12", Creature::HALFELF, VocRules::BBN);
  
  c[13] = new Creature("EE13", Creature::ELF, VocRules::CLR);
  
  cout << endl;
  
  for(int i = 0; i < 14; i++)
  {
    cout << "TEST: " << i << endl;
    c[i]->Write(cout);
    cout << endl;
  }
  
  string pause;
  
  cout << endl << endl << "Change Equipment 1" << endl << endl;
  
  c[1]->Write(cout);
  
  cout << endl << endl;
  
  EquipClass* t0 = new WpnClass("Crossbow");
  
  if(!(c[1]->FindEquipment(t0)));
    cout << endl << c[1]->Weapon( ) << endl << endl;
  
  c[1]->Write(cout);
  
  getline(cin, pause);
  
  cout << endl << endl << "Change Equipment 2" << endl << endl;
  
  c[1]->Write(cout);
  
  cout << endl << endl;
  
  EquipClass* t1 = new ArmorClass("Buckler");
  
  if(!(c[1]->FindEquipment(t1)))
    cout << c[1]->Armor( ) << endl << endl;
  
  c[1]->Write(cout);
  
  getline(cin, pause);
  
  cout << endl << endl << "Change Equipment 3" << endl << endl;
  
  c[1]->Write(cout);
  
  cout << endl << endl;
  
  EquipClass* t2 = new WpnClass("Javelin");
  
  if(!(c[1]->FindEquipment(t2)))
    cout << c[1]->Weapon( ) << endl << endl;
  
  c[1]->Write(cout);
  
  getline(cin, pause);
  
  cout << endl << endl << "Change Equipment 4" << endl << endl;
  
  c[1]->Write(cout);
  
  cout << endl << endl;
  
  EquipClass* t3 = new ArmorClass("Lamellar");
  
  if(!(c[1]->FindEquipment(t3)))
    cout << c[1]->Armor( ) << endl << endl;
  
  c[1]->Write(cout);
  
  getline(cin, pause);
  
  cout << endl << endl << "Change Equipment 5" << endl << endl;
  
  c[1]->Write(cout);
  
  cout << endl << endl;
  
  EquipClass* t4 = new WpnClass("Dagger");
  
  if(!(c[1]->FindEquipment(t4)))
    cout << c[1]->Weapon( ) << endl;
  
  c[1]->Write(cout);
  
  getline(cin, pause);
  
  cout << endl << endl << "Change Equipment 6" << endl << endl;
  
  c[1]->Write(cout);
  
  cout << endl << endl;
  
  EquipClass* t5 = new ArmorClass("Leather");
  
  if(!(c[1]->FindEquipment(t5)))
    cout << c[1]->Armor( ) << endl;
  
  c[1]->Write(cout);
  
  getline(cin, pause);
  
  c[1]->SellEquipment("Poop");
  
  TestCopy(c[1]);
  
  c[1]->Write(cout);
  
  getline(cin,pause);
  
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
  Creature aa("H0r"), ab("h0r"), ac("F1r"), ad("O5r"), ae("T44r");
  
  cout << " < : " << (aa < ab) << ", " << (aa < ac) << ", " << (aa < ad) << ", " << (aa < ae) << endl << endl;
  
  cout << " > :  " << (aa > ab) << ", " << (aa > ac) << ", " << (aa > ad) << ", " << (aa > ae) << endl << endl;
  
  cout << " <= :" << (aa <= ab) << ", " << (aa <= ac) << ", " << (aa <= ad) << ", " << (aa <= ae) << endl << endl;
  
  cout << " >= :" << (aa >= ab) << ", " << (aa >= ac) << ", " << (aa >= ad) << ", " << (aa >= ae) << endl << endl;
  
  cout << " == : " << (aa == ab) << ", " << (aa == ac) << ", " << (aa == ad) << ", " << (aa == ae) << endl << endl;
  
  cout << " != : " << (aa != ab) << ", " << (aa != ac) << ", " << (aa != ad) << ", " << (aa != ae) << endl << endl;
  
  getline(cin,pause);
  
  
  Creature H12("H12");
  
  cout << "GP: " << H12.GP( ) << endl;
  
  getline(cin,pause);
  
  cout << "UPDATE GP +5: " << H12.UpdateGP(5) << endl;
  
  getline(cin,pause);
  
  cout << "GP: " << H12.GP( ) << endl;
  
  getline(cin,pause);
  
  H12.UpdateXP(999);
  
  H12.Write(cout);
  
  getline(cin,pause);
  
  H12.UpdateHP(19);
  
  cout << H12.HP( ) << endl;
  
  getline(cin,pause);
  
  Creature balls("kjhgkjhg", Creature::TROLL);
  
  balls.Write(cout);
  
  cout << balls.UpdateGP(23) << endl;
  
  getline(cin,pause);
  
  
  
  //Dice::SeeRolls( );
  
  Creature sack("E13", Creature::ELF);
  
  sack.Write(cout);
  
  cout << "UPDATE XP (15000): " << sack.UpdateXP(15000) << endl;
  
  cout << sack.HP( ) << endl << endl;
  
  Creature helf("F14", Creature::HALFELF);
  
  helf.Write(cout);
  
  helf.UpdateXP(2600001);
  
  cout << helf.HP( ) << endl << endl;
  
  Creature skillTest("H18");
  
  skillTest.Amnesia( );
  
  skillTest.Write(cout);
  
  skillTest.AddSkill("BALANCE");
  
  skillTest.Write(cout);
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
/*  
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
 
 Todd.Write(cout);*/
 
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
 

  
//   cout << "CHANGE EQUIPMENT\n***********\n\n";
//   
//   cout << Todd.UpdateHP(-100);
//   
//   cout << Todd.ChangeEquipment("Buckler");
//   
//   Todd.UpdateHP(100);
//   
//   cout << Todd.ChangeEquipment("uzi") << endl;
//   
//   cout << Todd.ChangeEquipment("dagger") << endl;
//   
//   cout << Todd.ChangeEquipment("Lamellar") << endl;
//   
//   cout << Todd.ChangeEquipment("fuckyou") << endl;
//   
//   cout << Todd.ChangeEquipment("Javelin") << endl;
//   
//   Todd.Write(cout);
  
  
  
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

void TestCopy(Creature* temp)
{
  temp->Write(cout);
}

