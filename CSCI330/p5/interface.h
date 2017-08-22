// interface for Quest for Elgeon Game

#ifndef _INTERFACE
#define _INTERFACE

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <queue>
#include <utility>
#include "gamespace.h"
#include "board.h"

using namespace std;
using namespace GameSpace;

class Interface
{

public:

  
  static string GetEquipment(ostream& out, istream& in );
  // Call to get the armament equipment to swap
  // pre : out and in streams are open
  // post: string equip is retrieved from in stream
  //       the value is echoed to out stream
  //	   returns the Ucase of input value

  static pair<int,int> GetFirstMove(ostream& out, istream& in );
  // Call to get the placement of the serach party(first deployment only)
  // pre : out and in streams are open
  // post: coordinates<row,col> are retrieved from in stream
  //          format:row,col
  //       the value is echoed to out stream
  //	   does minimal validation to be sure coordinates on board
  //       returns coordinates for placement

  static pair<int,char> GetMove(ostream& out, istream& in );
  // Call to get the move of the search party
  // pre : out and in streams are open
  // post: move entry<unit,dir> is retrieved from in stream 
  //          format:unit,dir
  //       the value is echoed to out stream
  //	   does minimal validation to be sure 
  //       1<=units<=6  dir = ['N','S','E','W']
  //       returns move for searchParty movement

private:
  static int round; // maintains the round for game play
  Interface();  // static class - no construction
};

#endif



