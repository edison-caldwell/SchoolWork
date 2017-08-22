#include "Human.h"

const int Human::ABL_ADJ[6] = { 0,  0,  0,  0,  0,  0};


Human::Human(string name, VocRules::VocType voc_type):
  Humanoid(name, voc_type, ABL_ADJ, VocRules::FTR)
{

}

Human::~Human( )
{

}

void Human::Write(ostream& out) const
{
  out << "HUMAN#";
  
  Humanoid::Write(out);
  
}

Human* Human::Clone( ) const
{
  return new Human(*this);
}
