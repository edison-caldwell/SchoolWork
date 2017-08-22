//GM.H

#ifndef _GM_H
#define _GM_H


#include "handle4.h"
#include "interface.h"
#include "board.h"
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Interface;

class GameMaster
{
public:
  static GameMaster* GetGM( );
  //Description: Returns an instance of the GameMaster singleton.
  //Pre:
  //Post: If pointer to singleton already exists, return that pointer, else 
  //allocate new memory for GameMaster and return the pointer.
  
  static void DeleteGM( );
  //Description: Deletes the instance of the GameMaster singleton.
  //Pre: GM is not NULL.
  //Post: All memory for GM is freed.
  
  ~GameMaster( );
  //Description: Descructor for GameMaster singleton
  //Pre:
  //Post: Dynamically allocated memory (Search Party and Armament) is freed.
  
  queue<Creature*> SearchParty( ) const;
  //Description: Returns the search party as a queue.
  //Pre: Search Party initialized.
  //Post:Search Party is returned as a queue.
  
  set<string> ActivePlayers( )const;
  //Description: Returns a set of the players who are active (Not dead, dying, 
  //or disabled).
  //Pre: Active Players has been initialized.
  //Post: Active Players is returned as a set.
  
  map<string,int> Inventory( ) const;
  //Description: Returns the inventory map.
  //Pre: InitArmament has been called by client.
  //Post: Inventory is returned as a map.
  
  vector<EquipClass*> Armament( ) const;
  //Description: Returns the armament vector.
  //Pre: InitArmament has been called by client.
  //Post: Armement is returned as a vector of EquipClass pointers.
  
  
  void InitBoard(int, int);
  //Description: Initializes the board with x rows and y colums.
  //Pre: 
  //Post: Board is created with x rows and y colums.
  
  void InitSearchParty( );
  //Description: Initializes the search party: allocates memory for each party 
  //member & their weapons/armor.
  //Pre: 
  //Post: Search Party is initialized, promoted to level 10, given 25 gold,
  //and pushed into fiesta queue
  
  void InitArmament( );
  //Description: Initialized the armament vector and the inventory map.
  //Pre:
  //Post: Inventory and armament are populated, matching armament.in.
  
  void Deployment( );
  //Description: Readies the party for a mission. The leader of the party has 
  //a chance to switch their weapon or armor.
  //Pre: InitArmament has been called by the client.
  //Post: Leader has had a chance to change their weapon with something in the
  //armament. Armament vector and inventory map are updated accordingly.
  
  void MoveSearchParty( );
  //Decription: If first move, users picks the cell they wish to enter, else the
  //user picks the number of cells they wish to move and the direction.
  //Pre: InitArmament, InitBoard, and InitSearchParty have been called by 
  //client.
  //Post: Party is either placed onto the board or cell is updated, triggering
  //the encounter for that cell.
  
  void Healing( );
  //Description: Allows the party to heal. Creature must be Dying or Disabled to
  //be healed. The creature then attempts to heal themself, if the creature is
  //not healed, the party in turn attemps to heal the creature until either:
  //te creature is active or each party member has attempted to heal.
  //Pre: Search Party has been initialzed.
  //Post: Creature is healed until active or search party is exhausted. 
  
  void UpdateLeader( );
  //Description: Updates the leader with the next creature in the queue. 
  //Pre: Search Party has been initialized.
  //Post: Leader is updated with next creature in the queue. If that creature is
  //not active then the queue is cycled through until either every creature has
  //attempted to be leader or and active creature is found. If no active
  //party member exists the game is over.
  
  bool GameOver( );
  //Description: Checks to see if either the party has all died or Elgeon was
  //found after a mission. If either of these holds true, return true. Else
  //return false.
  //Pre: 
  //Post: Returns true is conditions are met, otherwise false. 
  
  void InitActivePlayers( );
  //Description: Populates the set with all active players.
  //Pre:
  //Post: Set of active players is initalized.
  
  void WriteParty( ); //Debugging purposes only
  //Description: Prints out the members of the Search Party.
  //Pre: Search Party has been initialized.
  //Post: Information about each party member is echoed to the screen.
  
private:
  GameMaster( );
  //Description: Default constructor for GameMaster. Will never be called.
  //Private to force the user to use GetGM( ).
  //Pre:
  //Post:
  
  static GameMaster* gm;
  //Desription: Static pointer to singleton of GameMaster.
  
  queue<Creature*> fiesta;
  //Description: Search Party queue
  
  set<string> active_players;
  //Description: Active Players set.
  
  vector<EquipClass*> armament;
  //Description: Armament vector.
  
  map<string,int> inventory;
  //Description: Inventory mapping. 
  
  static Board* board;
  //Description: Static pointer to board singleton.
  
  
  //STATIC VARS
  static const int PARTY_SIZE; //4
  static bool gm_loaded; //No longer used.
  static bool Elgeon; //No longer used.
};

#endif
  
  
  