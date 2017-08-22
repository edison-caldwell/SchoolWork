#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

void FindBounds(int, string &, string &);

const char CRACKER[8] = "cracker";
const int ALPHA = 26;
const char LETTERS_ARR[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int main(int argc, char * argv[])
{

   if(argc != 3){
        cerr << "\n\nInvalid arguments. Process terminating...\n\n";
        return 1;
    }

    if(argc == 3 && string(argv[1]) != "-N"){
        cerr << "\n\nInvalid arguments. Process terminating...\n\n";
        return 1;
    }

    vector<int> pids;
    string lower = "aaaaaa";
    string  upper = "aaaaaa";
    int processes = atoi(argv[2]);
    int increment = ALPHA/processes;
    int index = increment;
    
    for(int i = 0; i < processes; i++)
    {   
        FindBounds(index, lower, upper);
        //cout << lower << endl << upper << endl << endl;
        int pid = fork();
        if(pid == 0){
            execlp(CRACKER, lower.c_str(), upper.c_str(), (char *)("&"), (char *)NULL);
        }
        
        pids.push_back(pid);

        if(index > 25 || (index < 25 && i == processes - 2))
            index = 25;
        else
            index = index + increment;    

        lower = upper;
    } 

    idtype_t idtype = P_ALL;
    siginfo_t infop;
    
    waitid(idtype, 0, &infop, WEXITED);
    
    int winner = infop.si_pid;

    for(int i = 0; i < pids.size(); i++){
        if(pids[i] != winner)
            kill(pids[i], SIGKILL);
    }
    return 0;
}


void FindBounds(int increment, string &low, string & up)
{ 
    if(increment == 26)
        --increment;
    string temp(6, LETTERS_ARR[increment]);
    up = temp;

    return;
}


