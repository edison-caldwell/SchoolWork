// interface for Quest for Elgeon Game

#ifndef _REPORT
#define _REPORT

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include "gamespace.h"
#include "board.h"  // include for board header file
#include "armor.h"
#include "wpn.h"
#include "handle4.h"
#include "gm.h"

using namespace std;
using namespace GameSpace;

class Report
{

public:

  static void PlayerDeployment(ostream& out);
  // Provides data for player processing of deployment 
  // pre : out is open,
  //       inventory is loaded
  // post: inventory and search party leader data is sent to ostream
  
  static void PlayerMove(ostream& out);
  // Provides data for player processing of move
  // pre : out is open
  //       searchParty is ready to be placed or moved
  //       armament is loaded and swap is complete
  // post: board and searchParty leader are sent to ostream
  

  static void AfterSetUp(ostream& out);
  // Call immediately after GameSetUp( )
  // pre : out is open, 
  //	   board is loaded
  //       searchParty is initialized, 
  //       armament is loaded
  // post: armament, board and searchParty are sent to ostream
                            
                            
  static void BeforeDeployment(ostream& out);
  // Call immediately before any deployment processing
  // pre : out is open,
  //       armament is loaded
  // post: armament is sent to ostream
  
  //static string GetEquipment(ostream& out, istream& in );
  // Call to get the armament equipment to swap
  // pre : out and in streams are open
  // post: string equip is retrieved from in stream
  //       the value is echoed to out stream
  //	   returns the Ucase of input value

  static void BeforeMove(ostream& out);
  // Call after armament swap and before placement or move
  // pre : out is open
  //       searchParty is ready to be placed or moved
  //       armament is loaded and swap is complete
  // post: armament, board and searchParty are sent to ostream
  
  
  static void AfterMove(ostream& out);
  // Call immediately after move
  // pre : out is open
  //       searchParty has just be placed or moved
  // post: board previous and new location are sent to out stream
  //       searchParty is sent to ostream

  static void AfterHealing(ostream& out);
  // Call immediately after healing
  // pre : out is open
  //       searchParty has just be healed
  // post: 
  //       searchParty is sent to ostream

  static void GameOver(ostream& out);
  // Call from GameOver( )
  // pre : out is open 
  // post: armament, board and searchParty are sent to ostream
  //       report of Elgeon status also sent to ostream

  static void PrintMap(ostream& out, string teststr,map<string,int> aMap);
  // Outputs a map of pairs <string,int> to outstream
  // pre : out is open
  // post: outputs  each map pair preceded by test string "tag"
  //         to the out stream   

  static void PrintVec(ostream& out, string teststr,vector<EquipClass *> a);
  // Outputs a vector of EquipClass objects to outstream
  // pre : out is open
  // post: outputs  each EquipClass preceded by test string "tag"
  //         to the out stream   

  static bool Compare(EquipClass *e1, EquipClass*e2);
  // returns true is *e1 < *e2

  static void PrintBoard(ostream& out, string teststr, queue<Creature *>q, int type);
  // Outputs the board using Board::PrintCell( )
  // pre : out is open, type is value 0,1,2
  // post: outputs each cell of board preceded by test string "tag"
  //         to the out stream
  
  static void PrintSet(ostream& out, string teststr, set<string> s);
  // Outputs the set of Active Players
  // pre : out is open
  // post: outputs each creature that is active preceded by 
  //         test string "tag" to the out stream
  
  static void PrintQ(ostream& out, string teststr, queue<Creature *>q);
  // Outputs the queue using Creature::Write( )
  // pre : out is open
  // post: outputs each creature preceded by test string "tag"
  //         to the out stream
  
  static void PrintTest(ostream & out, string teststr);
  // Outputs the test string "tag"
  //  maintains a counter of consecutive teststr of same value
  //  counter is reset if new value for teststr passed in
  // pre : out is open
  // post: outputs the teststr "tag" to outstream

  static void InitReport( );  
  // Initialize the reporting system
  // Pre: none
  // Post: all static data has been initialized 
  
  static void NextRound( );
  // Update the round
  // pre: none
  // post: round has been incremented
  
private:
  static pair<int,int> prevCell;  // maintains prev cell for AfterMove( )
  static int round; // maintains the round for game play
  static GameMaster * gm;
  Report();  // static class - no construction
};

#endif



