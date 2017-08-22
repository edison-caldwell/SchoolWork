// wpn.h

#ifndef _WPNH
#define _WPNH

#include <map>
#include "equip.h"
#include "dice.h"
#include "gamespace.h"

using namespace std;
using namespace GameSpace;

class WpnClass:public EquipClass
{
  public:
//*******datatypes
    enum WpnType {NOWPN, BALLISTIC, BLUDGEONING, ENERGY, PIERCING, SLASHING};
    // types of wpn
    
    static WpnType StrToWpn(string str);
    // converts a string to the WpnType
    
    static string WpnToStr(WpnType type);
    // converts an WpnType to a string

    struct WpnRec
    {
       int cost;
       int wt;
       int critical;
       int damRolls;
       int damFaces;
       int size;
       WpnType style;
       bool strength;
    };

//*******lookup static methods
    
    static int LookUpCost(string name);
    // Looks up the cost of a specific wpn
    // pre:  name should be the name of an wpn
    // post: returns the cost of the wpn, zero if not found
    
    static int LookUpWt(string name);
    // Looks up the weight of a specific wpn
    // pre:  name should be the name of an wpn
    // post: returns the weight of the wpn, zero if not found
    
    static WpnRec LookUpStats(string name);
    // Looks up and returns the stats for a given wpn
    // pre: name should be the name of an wpn
    // post: returns the entire wpn record
    
    static bool IsEquipment(string name);
    // Checks whether a name is a type of wpn
    // pre: none
    // post: returns true if name is an wpn, false otherwise

    static bool IsMelee(string name );
    // returns true when melee wpn
    // pre:  none.
    // post: returns true if melee, false otherwise

    static bool IsRange(string name ) ;
    // returns true when range wpn
    // pre:  none.
    // post: returns true if range, false otherwise


//***************************************Instance function members
//*******constructor
    WpnClass(string name);
    // Set data for wpn with name
        
//*******getters
    int Cost( ) const;
    // Returns the wpn cost
    // pre: none
    // post: the wpn cost is returned
    
    int Wt( ) const;
    // Returns the wpn weight
    // pre: none
    // post: the wpn weight is returned

    int Critical( ) const;
    // Returns the wpn critical range
    // pre:  none
    // post: the wpn's critical range is returned

    int Damage(string CreatureName) const;
    // returns the wpn's rolled damage value 
    //			(needs creature name to roll)
    // pre:  name of creature rolling damage
    // post: the wpn's damage is returned
    
    int Size( ) const;
    // returns the wpn size
    // pre:  none.
    // post: the wpn size is returned

    WpnType Style( ) const;
    // returns the wpn style
    // pre:  none.
    // post: the wpn style is returned

    bool IsMelee( ) const;
    // returns true when melee wpn
    // pre:  none.
    // post: returns true if melee, false otherwise

    bool IsRange( ) const;
    // returns true when range wpn
    // pre:  none.
    // post: returns true if range, false otherwise

    WpnRec LookUpStats( ) const;
    // Looks up and returns stats of the current wpn
    // pre: none
    // post: the entire wpn record is returned
    

//*******output
    void Write(ostream& stream) const;
    // Writes the wpn data to an output stream
    // order:
    //       RANGE#name#cost#weight#critical#ndf#size#style#
    //       or
    //       MELEE#name#cost#weight#critical#ndf#size#style#
    // pre:  stream must be open, headers already printed
    //       if necessary.
    // post: all member data in the wpn object has been inserted
    //       into output stream.
    

  private:
  //***************************************Private members
  
    WpnClass( );          // no default construction
         
    static void Load( );  // loads the data from WPN_FILE
    
    static bool Read(istream& stream,string& name, WpnRec& data);
    // Reads the wpn object data from an input stream
    // order:
    //       name#cost#weight#critical#ndf#size#style#
    // pre:  stream must be open.
    // post: data extracted from stream,
    //       if valid - data members have updated value, return true
    //       else data members unchanged, return false

//*******DATA
    static map <string,WpnRec> wpns; // data about wpns
    static const string DEF_NAME; //default wpn name (invalid)

};



#endif


