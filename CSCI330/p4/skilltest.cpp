#include <iostream>
#include "p4.h"
#include "SkillRules.h"

using namespace std;


int main( )
{
  
  

  SkillRules* s = SkillRules::GetSkillRules( );

  cout << s->ValidateSkill("JUMP");

  s->Print(cout);

}


