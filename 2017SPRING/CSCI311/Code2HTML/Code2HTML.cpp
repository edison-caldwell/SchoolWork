#include "Code2HTML.h"

int main(int argc, char* argv[])
{
    ifstream inFile;
    ofstream writeFile;
    string outfile, inputfile;
    vector<string> argTable[o+1];
    
    
    map<string, Flag> Flag_String;
    Flag_String["-b"] = b;
    Flag_String["--bold"] = bold;
    Flag_String["-t"] = t;
    Flag_String["--italic"] = italic;
    Flag_String["-r"] = r;
    Flag_String["--replace"] = ::replace;
    Flag_String["-w"] = w;
    Flag_String["--wrap"] = wrap;
    Flag_String["-i"] = i;
    Flag_String["-o"] = o;
    Flag_String["-h"] = h;
    Flag_String["--help"] = h;
    Flag_String["?"] = h;  
    
    ParseParameters(argc, argv, argTable, Flag_String);
    //PrintParameters(argTable);
        
    if(argc == 1 && (isatty(fileno(stdin)) && isatty(fileno(stdout))))
    {
        errno = EINVAL;
        perror("usage: ./Code2HTML < infile > outfile\nusage: .Code2HTML -i [infile] -o [outfile]");
        exit(EXIT_FAILURE);
    }
    
    if(!isatty(fileno(stdin)))
    {
        if(!isatty(fileno(stdout)))
        {
            cout << PRETTY_SCRIPT_SRC << endl << PRETTY_PATTIES << endl;
            ParseFile(argTable, Flag_String, cin, cout);
        }
        else
        {
            outfile = argTable[o][0];
            writeFile.open(outfile.c_str());
            writeFile << PRETTY_SCRIPT_SRC << endl << PRETTY_PATTIES << endl;
            ParseFile(argTable, Flag_String, cin, writeFile);
        }
    }
    else if(isatty(fileno(stdin)))
    {
        inputfile = argTable[i][0];
        inFile.open(inputfile.c_str());
        
        if(!isatty(fileno(stdout))){
            cout << PRETTY_SCRIPT_SRC << endl << PRETTY_PATTIES << endl;
            ParseFile(argTable, Flag_String, inFile, cout);
        }
        else
        {
            outfile = argTable[o][0];
            writeFile.open(outfile.c_str());
            writeFile << PRETTY_SCRIPT_SRC << endl << PRETTY_PATTIES << endl;
            ParseFile(argTable, Flag_String, inFile, writeFile);
        }
    }
    
    return 0;
}


Flag& operator++(Flag& orig)
{
    orig = static_cast<Flag>(static_cast<int>(orig)+1);
    
    if(orig > o)
        orig = o;
    
    return orig;
}


Flag operator++(Flag& orig, int other)
{
    Flag temp = orig;
    
    ++orig;
    
    return temp;
}


void ParseParameters(int numArgs, char* argArray[], vector<string>
vec[],  map<string, Flag> Flag_String)
{
    int breakCondition = 0;
    Flag index = EXECUTABLE;
    
    vec[index].push_back(argArray[breakCondition]);
    breakCondition++;
    
    while(breakCondition < numArgs)
    {
        index = StringToEnum(argArray[breakCondition],  Flag_String);
        breakCondition++;
        
        if(index == h)
        {
            PrintHelp(numArgs);
            
            if(numArgs == 2){
                exit(EXIT_SUCCESS);
            }
        }
        else if(index == r)
        {
            for(int i = 0; i < 2; i++){
                vec[index].push_back(argArray[breakCondition]);
                breakCondition++;
            }
        }
        else if(index == w)
        {
            for(int i = 0; i < 3; i++)
            {
                vec[index].push_back(argArray[breakCondition]);
                breakCondition++;
            }
        }
        else
        {
            vec[index].push_back(argArray[breakCondition]);
            breakCondition++;
        }
    }
    return;
}


void PrintParameters(vector<string> vec[])
{
    for(int i = 0; i < o; i++)
    {
        cout <<  endl;
        int size = vec[i].size();
    
        for(int j = 0; j < size; j++)
        {
            cout << "[" << i << "]";
            cout <<  "[" << j << "] " << vec[i][j] <<  endl;
        }
    }
}


void ParseFile(vector<string> argTable[], map<string, Flag> Flag_String, istream& in, ostream& out)
{
    string temp;
    getline(in, temp, '\n');
 
    while(in)
    {   
        temp = ReplaceAll(temp, "&", AMPERSAND);
        temp = ReplaceAll(temp, "<", LESSTHAN);
        temp = ReplaceAll(temp, ">", GREATERTHAN);
        temp = Replace(temp, argTable);
        temp = Bold(temp, argTable);
        temp = Italic(temp, argTable);
        temp = Wrap(temp, argTable);
        out << temp << endl;
        getline(in, temp);    
    }
    
    return;
}


Flag StringToEnum(char str[],  map<string, Flag> Flag_String)
{
    return Flag_String[str];
    
}


string ReplaceAll(string &str, const string& from, const string& to) 
{
    //PrintParameters(argTable);
    
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) 
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}


string Bold(string temp, vector<string> argTable[])
{
    for(int i = 0; i < argTable[b].size(); i++)
    {
        temp = ReplaceAll(temp, argTable[b][i], "<b>"+argTable[b][i]+"</b>");
    }
    
    return temp;
}


string Italic(string temp, vector<string> argTable[])
{
    for(int i = 0; i < argTable[t].size(); i++)
    {
        temp = ReplaceAll(temp, argTable[t][i], "<i>"+argTable[t][i]+"</i>");
    }
    
    return temp;
}


string Wrap(string temp, vector<string> argTable[])
{
    for(int i = 0; i < argTable[w].size(); i+=3)
    {
        temp = ReplaceAll(temp, argTable[w][i], argTable[w][i+1]+argTable[w][i]+argTable[w][i+2]);
    }
    
    return temp;
}

string Replace(string temp, vector<string> argTable[])
{
    //PrintParameters(argTable);
    for(int i = 0; i < argTable[r].size()/2; i+=2)
    {
        temp = ReplaceAll(temp, argTable[r][i], argTable[r][i+1]);
    }
    
    return temp;
}

void PrintHelp(int argc)
{
    string temp;
    
    ifstream in;
    in.open("help.txt");
    
    getline(in, temp);
    
    while(in)
    {
        cout << temp << endl;
        getline(in, temp);
    } 
    
    return;
}





//found example of replace method on stack overflow. I understand the functionality after reviewing the function. 
//stackoverflow.com/questions/2896600/how-to-replace=all=occurrences-of-a-character-in-string


