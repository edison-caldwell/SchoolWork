// board.h

#ifndef _BOARD
#define _BOARD

#include <vector>
#include <iostream>
#include <sstream>
#include <utility>
#include "gamespace.h"
#include "handle4.h"  
#include "cell.h"

using namespace std;
using namespace GameSpace;

class Board
{
  public:
    static Board* GetBoard( );
    // Returns a pointer to the board
    // pre:  board should already be created
    // post: returns a pointer to the board, NULL if no board created

    static void CreateBoard( );
    // Creates the board using a default size
    // pre:  none
    // post: the board is created, unless it already existed
    
    static void CreateBoard(int numRows, int numCols);
    // Creates the board using the size specified (numRows x numCols)
    // pre:  none
    // post: the board is created, unless it already existed
    
    static void DeleteBoard();
    // Deletes the board 
    // pre: none
    // post: board is deleted
    
    ~Board( );
    // destructor for the board
    
    pair<int,int> Size( ) const;
    // Returns the size of board as a pair
    // pre: none
    // post: returns the size of the board.

    vector<Creature *> Occupants(pair<int,int> loc) const;
    // Returns the vector of occupants for a cell
    // pre:  none
    // post: returns a vector of occupants, 
    //        empty if row,col not on board.
    
    bool PlaceCreatures(queue<Creature *> q, pair <int, int> loc);
    // Moves a group of creatures into a cell
    // pre:   
    // post:  remove creatures from current cell, 
    //			moves into a cell on the board
    
    bool MoveCreatures(queue<Creature *> q, pair<int, char> loc);
    // Moves a creature specific units in specified direction
    // pre:   must be on the board, units must be >=0,
    //        direction is 'N','S','E','W'
    // post: If permitted then creature is moved forward 
    //    a specific number of units.  If invalid the creature
    //	  location remains unchanged.
    
    
    void PrintBoard(ostream& out, queue<Creature *>q, int full ) const;
    // Displays the board
    // pre:  out should be open
    //       q is the search party,
    //       type indicates how the cell will be printed
    //         0- just the encounter number - grid format
    //         1- X if search party is in cell, O if not - grid format
    //         2- Full print with occupants - each cell on newline
    // post: Board is written to output file for creature
    
    void PrintCell(pair<int,int> loc, ostream& out, queue<Creature *>q, int full ) const;
    // Displays the cell at coordinates loc
    // pre: out should be open
    //      location is the cell to print
    //      queue is the search party
    //       type indicates how the cell will be printed
    //         0- just the encounter number
    //         1- X if search party is in cell, O if not
    //         2- Full print with occupants
    //         ALL types are followed by linefeed
    // post: cell is printed
                
  private:

    static Board * bd;  // instance of the board
    
    const int ROWSIZE;  // constant set when board is created
    
    const int COLSIZE;  // constant set when board is created
    
    static const int DEFAULT_COLSIZE;	// default COLSIZE
    static const int DEFAULT_ROWSIZE;	// default ROWSIZE
    
    typedef Cell * CellPtr;
    
    CellPtr *grid;  // grid that contains the board information
    
    // Disallowed methods
    Board( );
    Board(int r, int c);
    Board(const Board&);
    Board& operator=(const Board&);
    
    void LoadBoard( );
    // Loads the board & encounter table from the file
    // pre:  BOARD_FILE must be ready for input with integers
    //		indicating the encounter for that cell
    //	     ENCOUNTER_FILE must be ready for input with encounter
    //		data, one record per line
    // post: cells are created in row major order with encounter data.
        
    //void Display(ostream& out) const;
    // Displays the board revealing encounters
    // pre:  out should be open
    // post: board is written with encounters to the output file
    
    void PrintLine(ostream& out, int num, string s) const;
    // Prints a line to the output stream
    
    int OffSet(pair<int,int>loc) const;
    // Calculates the offset for the grid given the row & col value
    
    pair<int,int>FindNewLoc(pair<int,int> oldLoc, pair<int,char> move) const;
    // Returns the new row and column given the move data 

        
};

#endif


