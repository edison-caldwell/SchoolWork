#ifndef CODE2HTML
#define CODE2HTML

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>


using namespace std;

enum Flag {EXECUTABLE = 0, b = 1, bold = 1, t = 2, italic = 2, r = 3,
    replace = 3, w = 4, wrap = 4, i = 5, o = 6, h = 7, help = 7};
	


const string AMPERSAND = "&amp;";
const string LESSTHAN = "&lt;";
const string GREATERTHAN = "&gt;";
const string PRETTY_SCRIPT_SRC = "<script src=\"https://cdn.rawgit.com/google/code-prettify/master/loader/run_prettify.js\"></script>";
const string PRETTY_PATTIES = "<pre class=\"prettyprint\">";

string ReplaceAll(string &str, const string& from, const string& to);
void ParseParameters(int numArgs, char* argArray[], vector<string> vec[], map<string, Flag> Flag_String);
Flag StringToEnum(char str[],  map<string, Flag> Flag_String);
void PrintParameters(vector<string> vec[]);
void ParseFile(vector<string> argTable[], map<string, Flag> Flag_String, istream& in, ostream& out);
Flag& operator++(Flag& orig);
Flag operator++(Flag& orig, int);
string Bold(string temp, vector<string> argTable[]);
string Italic(string temp, vector<string> argTable[]);
string Wrap(string temp, vector<string> argTable[]);
string Replace(string temp, vector<string> argTable[]);
void CheckParameters(vector<string> argTable[]);
void PrintHelp(int argc);

#endif
