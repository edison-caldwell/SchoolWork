//CSCI 330
//Fall 2015 (161)
//Program 5
//Implementation of CreatureClass to create a Creature
//    for the Quest for Elgeon Game


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "dice.h"
#include "gamespace.h"
#include "voc.h"
#include "armor.h"
#include "wpn.h"
#include "handle4.h"
#include "report.h"
#include "gm.h"

using namespace std;
using namespace GameSpace;

int main()
{
//  Dice::SeeRolls();
  Dice::ReadRollsFromFile( );
//  Dice::WriteRollsToFile( );
  ofstream fout;
  fout.open(COMBAT_FILE.c_str());
  fout<< "COMBAT Data"<<endl<<LINE1<<endl<<endl;
  fout.close();
  
  fout.open(TESTOUTFILE.c_str());

  fout <<"============="<<endl;
  fout << "Program 5 output" <<endl;
  fout <<"============="<<endl<<endl;

  cout <<"============="<<endl;
  cout << "Program 5 output" <<endl;
  cout <<"============="<<endl<<endl;

   Report::InitReport( );
   GameMaster *gm = GameMaster::GetGM();
   gm->InitBoard(5,3);
   gm->InitSearchParty();
   gm->InitArmament( );
   Report::AfterSetUp(fout);
   do
   {
      Report::NextRound();
      Report::BeforeDeployment(fout);
      gm->Deployment( );
      Report::BeforeMove(fout);
      gm->MoveSearchParty( );
      Report::AfterMove(fout);
      gm->Healing( );
      Report::AfterHealing(fout);
      if (!gm->GameOver( ))
        gm->UpdateLeader( );
   } while (!gm->GameOver());

   Report::GameOver(fout);
   GameMaster::DeleteGM();
   VocRules::DeleteVocRules( );
   return 0;
}

