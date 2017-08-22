#include <iostream>
#include <iomanip>
#include <fstream>
#include "cc2.h"


using namespace std;

int main()
{
  fstream shrek;
  
  Dice::ReadRollsFromFile( );
  
  shrek.open("outfile");
  
  shrek << "****************CreatureClass AddSkills( )****************" << endl << endl;
  
  
  CreatureClass skillTest("SKILLTEST");
  
  GameSpace::PrintTest(shrek, "A");
  
  skillTest.Write(shrek);
  
  shrek << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << skillTest.AddSkill("HIDE") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << skillTest.AddSkill("JUMP") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << skillTest.AddSkill("NOT A SKILL") << endl;
  
  shrek << endl;
  
  GameSpace::PrintTest(shrek);
  
  skillTest.Write(shrek);
  
  shrek << endl;
  
  
  
  skillTest.Amnesia( );
  
  GameSpace::PrintTest(shrek);
  
  skillTest.Write(shrek);
  
  shrek << endl;
  
  skillTest.UpdateHP(-7);
  
  GameSpace::PrintTest(shrek);
  
  shrek << skillTest.AddSkill("HIDE") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << skillTest.AddSkill("JUMP") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << skillTest.AddSkill("NOT A SKILL") << endl;
  
  
  
  GameSpace::PrintTest(shrek);
  
  skillTest.Write(shrek);
  
  shrek << endl;
  
  skillTest.Amnesia( );
  
  GameSpace::PrintTest(shrek);
  
  skillTest.Write(shrek);
  
  shrek << endl;
  
  skillTest.UpdateHP(-2);
  
  GameSpace::PrintTest(shrek);
  
  shrek << skillTest.AddSkill("HIDE") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << skillTest.AddSkill("JUMP") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << skillTest.AddSkill("NOT A SKILL") << endl;
  
  
  GameSpace::PrintTest(shrek);
  
  skillTest.Write(shrek);
  
  shrek << endl;
  
  skillTest.Amnesia( );
  
  
  GameSpace::PrintTest(shrek);
  
  skillTest.Write(shrek);
  
  shrek << endl;
  
  skillTest.UpdateHP(-22);
  
  GameSpace::PrintTest(shrek);
  
  shrek << skillTest.AddSkill("HIDE") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << skillTest.AddSkill("JUMP") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << skillTest.AddSkill("NOT A SKILL") << endl;
  
  
  GameSpace::PrintTest(shrek);
  
  skillTest.Write(shrek);
  
  shrek << endl << endl  << endl;
  
  shrek << "****************CreatureClass SkillCheck( )****************" << endl << endl;
  
  CreatureClass testSkill("TESTSKILL");
  
  testSkill.Amnesia( );
  
  testSkill.AddSkill("HIDE");
  
  testSkill.AddSkill("JUMP");
  
  testSkill.AddSkill("NOT A SKILL");
  
  
  
  
  
  
  testSkill.Write(shrek);
  
  shrek << endl << endl;  
  
  GameSpace::PrintTest(shrek, "S");
  
  shrek << testSkill.SkillCheck("HIDE") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << testSkill.SkillCheck("JUMP") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << testSkill.SkillCheck("NOT A SKILL") << endl << endl;
  

  

  
  
  testSkill.UpdateHP(-7);
  
  
  
  
  
  
  testSkill.Write(shrek);
  
  shrek << endl << endl;  
  
  GameSpace::PrintTest(shrek);
  
  shrek << testSkill.SkillCheck("HIDE") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << testSkill.SkillCheck("JUMP") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << testSkill.SkillCheck("NOT A SKILL") << endl << endl;

  
  

  
  
  testSkill.UpdateHP(-2);

  
  

  
  
  testSkill.Write(shrek);
  
  shrek << endl << endl;  
  
  GameSpace::PrintTest(shrek);
  
  shrek << testSkill.SkillCheck("HIDE") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << testSkill.SkillCheck("JUMP") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << testSkill.SkillCheck("NOT A SKILL") << endl << endl;
  

  

  
  
  testSkill.UpdateHP(-22);

  
  

  
  
  testSkill.Write(shrek);
  
  shrek << endl << endl;  
  
  GameSpace::PrintTest(shrek);
  
  shrek << testSkill.SkillCheck("HIDE") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << testSkill.SkillCheck("JUMP") << endl;
  
  GameSpace::PrintTest(shrek);
  
  shrek << testSkill.SkillCheck("NOT A SKILL") << endl << endl;
  
  
  

  
  
  return 0;
}