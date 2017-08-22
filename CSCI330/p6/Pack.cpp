#include "Humanoid.h"
#include "Pack.h"

PackClass::PackClass(vector<EquipClass*> other)
{
  for(int i = 0; i < other.size( ); i++)
  {
    EquipClass* temp = NULL;
    
    if(WpnClass::IsEquipment(other[i]->Name( )))
    {
      temp = new WpnClass(other[i]->Name( ));
      contents.push_back(temp); 
    }
    
    if(ArmorClass::IsEquipment(other[i]->Name( )))
    {
      temp = new ArmorClass(other[i]->Name( ));
      contents.push_back(temp);
    }
  }
}

void PackClass::AddEquip(EquipClass* item)
{
  contents.push_back(item);
}



PackClass::~PackClass( )
{  
    for(vector<EquipClass*>::iterator it = contents.begin( ); it != contents.end( ); it++)
    {
      delete *it;  
    }

  contents.clear( ); 
}




EquipClass* PackClass::DeleteEquip(string item)
{
  EquipClass* temp = NULL;
  
  vector<EquipClass*>::iterator it;
  
  bool found = false;
  
  it = contents.begin( );
  
  while(!found && it != contents.end())
  {
    if((*it)->Name( ) == item)
    {
      temp = *it;
      
      found = true;
    }
    else
      it++;
  }  
  
  
  if(found)
    contents.erase(it);
  
  return temp;
}



bool PackClass::InPack(string str)
{ 
//   vector<string> tempVec = ListPack( );
//   
//   bool temp = false;
//   
//   vector<string>::iterator it;
//   
//   for(int i = 0; i < tempVec.size( ); i++)
//   {
//     
//   
//   cout << *it;
//   
//    
//   
//   return temp; 
}



vector<EquipClass*> PackClass::GetPack( ) const
{
  return contents;
}



vector<string> PackClass::ListPack( )
{
  vector<string> temp;
  
  string str;
  
  if(contents.size( ) != 0)
  {
    for(vector<EquipClass*>::iterator it = contents.begin( ); it != contents.end( ); it++)
    {
      str = (*it)->Name( );
      
      temp.push_back(str);
    }
  }
 
  
  return temp;
}


void PackClass::Write(ostream& out)
{
  vector<string> temp = ListPack( );
  
  sort(temp.begin( ), temp.end( ));
  
  for(int i = 0; i < temp.size( ); i++)
  {
    out << temp[i];
    
    if(i != contents.size( ) - 1)
      out << ",";
  }
}



// PackClass& PackClass::operator=(const PackClass& p)
// { 
//   for(int i = 0; i < p.contents.size( ); i++)
//   {
//     if(WpnClass::IsEquipment(p.contents[i]->Name( )))
//       contents[i] = new WpnClass(p.contents[i]->Name( ));
//     
//     if(ArmorClass::IsEquipment(p.contents[i]->Name( )))
//       contents[i] = new ArmorClass(p.contents[i]->Name( ));
//   } 
//   
//   for(int i = 0; i < contents.size( ); i++)
//   {
//     cout << "HERE" << endl;
// 
//     cout << &(contents[i]) << "    " << &(p.contents[i]) << endl << endl;
//   }
// }

//     vector<EquipClass*>::iterator copy;
//     
//     copy = contents.begin( );
//     
//     for(vector<EquipClass*>::iterator it = p.contents.begin( ); it != p.contents.end( ); it++)
//     {
//       if(WpnClss
//   
//   
//     int size = (p.contents).size( );
//     
//     EquipClass* copy[size];
//     
//     for(int i = 0; i < size; i++)
//     {
//       if(WpnClass::IsEquipment(p.contents[i]->Name( )))
//       {  
//         copy[i] = new WpnClass(p.contents[i]->Name( ));
//         contents.push_back(copy[i]);
//         
//       }
//       else if(ArmorClass::IsEquipment(p.contents[i]->Name( )))
//       {
//         copy[i] = new ArmorClass(p.contents[i]->Name( ));
//         contents.push_back(copy[i]);
//       }
//     }
// }


// void PackClass::DefPack(VocRules::VocType voc)
// {
//   vector<EquipClass*> vec;
//   
//   EquipClass* temp[14];
//   
//   cout << VocRules::VocToStr(voc) << endl << endl;
//   
//   if(voc == VocRules::FTR)
//   {
//     cout << "FTR IN\n\n\n";
//     
//     temp[0] = new ArmorClass("Small Wooden Shield");
//     
//     vec.push_back(temp[0]);
//     
//     temp[1] = new WpnClass("Sword");
//     
//     vec.push_back(temp[1]);
// 
//     cout << "FTR OUT\n\n\n";
//   }
//   else if(voc == VocRules::BBN)
//   {
//     cout << "BBN IN\n\n\n";
//     
//     temp[2] = new ArmorClass("Studded Leather");
//     
//     vec.push_back(temp[2]);
//     
//     temp[3] = new WpnClass("Dagger");
//     
//     vec.push_back(temp[3]);
//     
//     temp[4] = new WpnClass("Short Bow");
//     
//     vec.push_back(temp[4]);
//     
//     cout << "BBN OUT\n\n\n";
//   }
//   else if(voc == VocRules::CLR)
//   {
//     cout << "CLR IN\n\n\n";
//     
//     temp[5] = new ArmorClass("Large Wooden Shield");
//     
//     vec.push_back(temp[5]);
//     
//     temp[6] = new WpnClass("Crossbow");
//     
//     vec.push_back(temp[6]);
//     
//     temp[7] = new WpnClass("Mace");
//     
//     vec.push_back(temp[7]);
//     
//     cout << "CLR OUT\n\n\n";
//   }
//   else if(voc == VocRules::ROG)
//   {
//     cout << "ROG IN\n\n\n";
//     
//     temp[8] = new ArmorClass("Leather Jacket");
//     
//     vec.push_back(temp[8]);
//     
//     temp[9] = new WpnClass("Rapier");
//     
//     vec.push_back(temp[9]);
//     
//     temp[10] = new WpnClass("Short Bow");
//     
//     vec.push_back(temp[10]);
//     
//     cout << "ROG OUT\n\n\n";
//   }
//   else if(voc == VocRules::WIZ)
//   {
//     cout << "WIZ IN\n\n\n";
//     
//     temp[11] = new WpnClass("Club");
//     
//     vec.push_back(temp[11]);
//     
//     temp[12] = new WpnClass("Dagger");
//     
//     vec.push_back(temp[12]);
//     
//     temp[13] = new WpnClass("Light Crossbow");
//     
//     vec.push_back(temp[13]);
//     
//     cout << "WIZ OUT\n\n\n";
//   }
//   
//   contents = vec;
// 
//   
//   
// }



