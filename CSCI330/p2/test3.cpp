#include <iostream>
#include "cc2.h"

using namespace std;

void TestSkills(CreatureClass temp);


int main( )
{
  /*Test AddSkill()
  
  CreatureClass temp("Test 1");
  
  temp.Write(cout);
  
  cout << endl;
  
 cout << temp.AddSkill("balance") << endl << endl;
  
  cout << temp.AddSkill("concentration") << endl << endl;
  
  cout << temp.AddSkill("Heal") << endl << endl;
  
  cout << temp.AddSkill("Jump") << endl << endl;
  
  //cout << temp.Level( ) << endl << endl;
  
  //cout << temp.UpdateXP(52000) << endl << endl;
  
  //cout << temp.Level( ) << endl << endl;
  
  //cout << temp.UpdateXP(789737) << endl << endl;
  
  //cout << temp.Level( ) << endl << endl;
  
  //cout << temp.AddSkill("JUMP") << endl;
  
  //cout << temp.AddSkill("JUMP") << endl;
  
  vector<string> vec;
  
  vec = temp.Skills( );
  
  for(vector<string>::iterator it = vec.begin( ); it < vec.end( ); it++)
    cout << *it << "  ";
  
  cout << endl << endl << "***Testing skills after function pass***\n\n";
  
  TestSkills(temp);
  
  CreatureClass other("Test 2");
  
  cout << "***New Creature, Amnesia, AddSkills***\n\n";
  
  other.Amnesia( );
  
  other.AddSkill("CONCENTRATE");
  
  other.AddSkill("SPOT");
  
  other.AddSkill("PERFORM");
  
  other.AddSkill("HIDE");
  
  other.Write(cout);
  
  cout << endl << endl;
  
  other = temp;
  
  cout << "***Testing Assignment for skills***\n\n";
  
  TestSkills(other);
  
  
  */

  CreatureClass temp("Test skck");
  
  temp.Amnesia( );
  
  temp.AddSkill("Balance");
  
  temp.AddSkill("concentration");
  
  temp.AddSkill("heal");
  
  temp.AddSkill("Jump");
  
  temp.AddSkill( "Open Lock");
  
  cout << endl;
  
  temp.Write(cout);
  
  cout << endl;
  
  cout << temp.SkillCheck("balance");
  
  
  
  return 0;
  
}

void TestSkills(CreatureClass temp)
{
  vector<string> vec;
  
  vec = temp.Skills( );
  
  for(vector<string>::iterator it = vec.begin( ); it < vec.end( ); it++)
    cout << *it << "  ";
  
  cout << endl << endl;
  
}
  
  