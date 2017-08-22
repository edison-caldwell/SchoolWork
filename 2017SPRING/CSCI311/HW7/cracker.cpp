#define _XOPEN_SOURCE
#include <iostream>
#include <string.h>
#include <algorithm>
#include <unistd.h>
#include <fstream>
#include "stopwatch.h"

using namespace std;

//string Increment(string, char, int &);

const string ENCRYPTED_PASS = "DBtH8T8yNcN0U";
const char SALT[3] = "DB";

int main(int argc, char * argv[])
{
    string lower = string(argv[0]);
    string upper = string(argv[1]);    
    string attack = lower;
       
    StopWatch timer;
    timer.Start();

    bool first = true;
    
    for((first) ? attack[0] = lower[0] : attack[0] = 'a'; attack[0] != '{'; attack[0] = static_cast<char>(attack[0] + 1)){
        for((first) ? attack[1] = lower[1] : attack[1] = 'a'; attack[1] != '{'; attack[1] = static_cast<char>(attack[1] + 1)){
            for((first) ? attack[2] = lower[2] : attack[2] = 'a'; attack[2] != '{'; attack[2] = static_cast<char>(attack[2] + 1)){
                for((first) ? attack[3] = lower[3] : attack[3] = 'a'; attack[3] != '{'; attack[3] = static_cast<char>(attack[3] + 1)){
                    for((first) ? attack[4] = lower[4] : attack[4] = 'a'; attack[4] != '{'; attack[4] = static_cast<char>(attack[4] + 1)){
                        for((first) ? attack[5] = lower[5] : attack[5] = 'a'; attack[5] != '{'; attack[5] = static_cast<char>(attack[5] + 1)){
                            
                            if(attack == upper){
                                exit(EXIT_SUCCESS);
                            }

                            char * temp = crypt(attack.c_str(), SALT);                                                                                 
                            
                            if(strcmp(temp, ENCRYPTED_PASS.c_str()) == 0)
                            {
                                timer.Stop();
                                ofstream out;
                                out.open("password");
                                cout << "\n\nPassword found!\tTime: " << timer.GetTime() << " seconds\n\n";
                                out << attack << "\nTime: " << timer.GetTime() << " milliseconds";
                                out.close();                            
                                exit(EXIT_SUCCESS);
                            }
                            first = false;                         
                        }       
                    }
                }
            }
        }      
    }

    return 0;
}
