#ifndef _PACKH
#define _PACKH

#include <vector>
#include "cc3.h"


using namespace std;

class Humanoid;



class PackClass{
  
public:
  
//   void DefPack(VocRules::VocType);
  
  void AddEquip(EquipClass*);
  
  EquipClass* DeleteEquip(string);
  
  bool InPack(string);
  
  vector<EquipClass*> GetPack( ) const;
  
  vector<string> ListPack( );
  
  void Write(ostream&);
  
  PackClass(vector<EquipClass*>);
  
  PackClass( )
  { };
  
  bool Sort(EquipClass*, EquipClass*);
  

  
  //PackClass( );
  
  ~PackClass( );
  
  PackClass& operator=(const PackClass&);
  
private:
  
  vector<EquipClass*> contents;
  
};
#endif