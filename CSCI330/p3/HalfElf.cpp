#include "HalfElf.h"

const int HalfElf::ABL_ADJ[6] = { 0,  0,  0,  0,  0,  0};

HalfElf::HalfElf(string name, VocRules::VocType voc_type):
  Humanoid(name, voc_type, ABL_ADJ, VocRules::ROG)
{

}

HalfElf::~HalfElf( )
{
  //cout << "\nHALFELF   DESTRUCTOR\n*******************\n";
}

void HalfElf::Write(ostream& out) const
{
  out << "HALFELF#";
  
  Humanoid::Write(out);
}