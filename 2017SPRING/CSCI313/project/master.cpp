#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>

using namespace std;

void ClearScreen();
void MainMenu();

const string RES_EXE = "reservation";
const string CHKOUT_EXE = "checkOut";
const string CNCL_EXE = "cancel";

int main(int argc, char * argv[])
{
    cout << endl << endl << endl;
    
    string command = "";
    
    MainMenu();
    cin >> command;
    
    while(command != "exit"){
        //ClearScreen();
        
        int pid = fork();
        
        cout << string(5, '\n');
        int fuck;
        if(pid == 0){
            if(command == "1"){
                fuck = execlp(RES_EXE.c_str(), (char*)NULL);
            }
            else if(command == "2"){
                fuck = execlp(CNCL_EXE.c_str(), (char*)NULL);
            }
            else if(command == "3"){
                fuck = execlp(CHKOUT_EXE.c_str(), (char*)NULL);
            }
            
        }
        else
            waitpid(pid, 0, NULL);
        
        cout << "\n\nfuck value: " << fuck << "\n\n";
        
        
        //sleep(5);
        
        //ClearScreen();
        
        cout << string(5, '\n');
        
        MainMenu();
        cin >> command;
    }
            
    
    return 0;
    
}


void ClearScreen()
{
    cout << string(100, '\n');
    
    return;
}

void MainMenu()
{
    cout << "\t\t1. Make a reservation.\n";
    cout << "\t\t2. Cancel a reservation.\n";
    cout << "\t\t3. Checkout.\n\t\tPlease type 1, 2, 3, or exit.\n\n\t\t";
    
    return;
}
