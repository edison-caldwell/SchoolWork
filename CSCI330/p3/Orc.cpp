#include "Orc.h"

const int Orc::ABL_ADJ[6] = { 0,  0, -2, -2,  2, -1};



Orc::Orc(string name, VocRules::VocType voc_type):
  Humanoid(name, voc_type, ABL_ADJ, VocRules::BBN)
{

}

Orc::~Orc( )
{
  //cout << "\nORC       DESTRUCTOR\n*******************\n";
}

void Orc::Write(ostream& out) const
{
  out << "ORC#";
  
  Humanoid::Write(out);
}