// cell.h

#ifndef _CELL
#define _CELL

#include <vector>
#include <iostream>
#include <sstream>
#include "gamespace.h"
#include "wpn.h"
#include "armor.h"
#include "handle4.h"
#include "enc.h"
using namespace std;
using namespace GameSpace;

class Cell
{
  public:

    Cell(pair<int,int> loc, int encounter);
    // Only valid constructor
        
    ~Cell( );
    // destructor for the board
    
    vector<Creature *> Occupants( ) const;
    // Returns the vector of occupants for a cell
    // pre:  none
    // post: returns a vector of occupants 
    
    bool EnterCell(queue<Creature *> q);
    // Moves a group of creatures into a cell
    // pre:   
    // post: creatures are occupants and encounter is done
    
    bool ExitCell(queue<Creature *> q);
    // Moves a group of creature out of the cell
    // pre: creatures must be occupants in the cell   
    // post: removes creatures from occ list
    //	returns true if all creatures are occupants, false otherwise   
    
    void PrintCell(ostream& out,queue<Creature *> q, int type) const;
    // Displays the cell
    // pre:  out should be open
    //       q is search party
    //       type indicates how the cell will be printed
    //         0- just the encounter number
    //         1- X if search party is in cell, O if not
    //         2- Full print with occupants followed by linefeed
    // post: cell is printed
        
  private:
     static const string event_str[14]; //description for enounters

      struct EncounterRec  // structure to hold encounter data
      {
  	Encounter::EncounterType ev;
  	string name;
  	string desc;
  	int val;
      };

      static vector<EncounterRec> enTable;  // class enounter table
      
      pair<int,int> loc;      // grid location of cell
      int encounter;          // encounter index
      vector<Creature *> occ; // cell occupants
      Creature * guest;       // cell guest - Elgeon or monster
      EquipClass *equip;      // cell equipment if magic spell
      int gp;                 // cell increase gp for found gold encounter

    // Disallowed methods
      Cell( );
      Cell(const Cell&);
      Cell& operator=(const Cell&);
      
      void HandleEncounter(queue<Creature *> q);
    // Process the encounter when group enters cell
    
    
      static void LoadEncounters( );
    // Loads encounter table from the file
    // pre:  
    //	     ENCOUNTER_FILE must be ready for input with encounter
    //		data, one record per line
    // post: encounter data is loaded in table
        
      int FindCreature(Creature *c) const;
    // Finds the Creature in the cell when given the Creature object
    // Search is done by the  name.  Name must be unique in the cell!!
    
        
};

#endif


