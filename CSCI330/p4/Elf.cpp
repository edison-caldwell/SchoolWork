#include "Elf.h"



const int Elf::ABL_ADJ[6] = { 2, -2,  0,  0,  0,  0};

Elf::Elf(string name, VocRules::VocType voc_type):
  Humanoid(name, voc_type, ABL_ADJ, VocRules::WIZ)
{
  
}

Elf::~Elf( )
{
  //cout << "\nELF       DESTRUCTOR\n*******************\n";
}

void Elf::Write(ostream& out) const
{
  out << "ELF#";
  
  Humanoid::Write(out);
}

Elf* Elf::Clone( ) const
{
  return new Elf(*this);
}