#include <iostream>
#include <string.h>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

string PROMPT = "mash=> ";

void Prompt(string p = PROMPT);
void ClearScreen();
vector<char *>GetAndParse();

int main(int argc, char* argv[])
{   
    //cout << "\n\nWELCOME TO MASH\n\n";
    int test = 0;   
    int child = 0;
    string command = "NOT EXIT";
    ClearScreen();
    vector<char *> args;
    
    cout << "\n\nWELCOME TO MASH, A SIMPLE SHELL IMPLEMENTED IN C!\nTHE COMMANDS AVAILABLE ARE:\n\t\tRUN\n\t\tPIPE\n\t\tREDIRECT\n\t\t";
    cout << "STARWARS\n\t\tDRUGWARS\n\t\tEXIT\n\n";
    
    do{
        Prompt(PROMPT);
        cin >> command;

        if(command == "RECOMPILE")
        {
            cout << "\nREBUILDING...\n\n";
            int pid = fork();
            if(pid == 0)
            {
                char * temp = new char[20];
                strcpy(temp, "g++");
                args.push_back(temp);
    
                temp = new char[20];
                strcpy(temp, "mash.cpp");
                args.push_back(temp);
                 
                temp = new char[20];
                strcpy(temp, "-o");
                args.push_back(temp);

                temp = new char[20];
                strcpy(temp, "mash");
                args.push_back(temp);

                execvp(args[0], &args[0]);                      
            }
            else{
                waitpid(pid, NULL, 0);
                char * temp = new char[20];
                strcpy(temp, "mash");
                args.push_back(temp);
                execvp(args[0], &args[0]);
            }
        }

        child = fork();
        
        if(child == 0 && command != "EXIT"){
            /*for(int i = 0; i < args.size(); i++)
            {
                cout << args[i] << endl;
            }*/
            if(command == "RUN"){
                cout << "What command could you like to run? ";
                cin.ignore();
                args = GetAndParse();
                test = execvp(args[0], &args[0]);
            }
            else if(command == "REDIRECT"){
                string inFile = "", outFile = "";
                int in, out;
                
                cin.ignore();

                cout << "What is the input file? ";
                getline(cin, inFile);
                cout << "What is the output file? ";
                getline(cin, outFile);
                cout << "What command do you want to run? ";
                //cin.ignore();
                args = GetAndParse();
                
                if(inFile != ""){
                    in = open(inFile.c_str(), O_CREAT | O_RDONLY, S_IREAD | S_IWRITE);
                    dup2(in, STDIN_FILENO);
                }

                if(outFile != ""){           
                    out = open(outFile.c_str(), O_CREAT | O_WRONLY, S_IRWXU);
                    dup2(out, STDOUT_FILENO);
                }
                
                int redirect = fork();

                if(redirect == 0)
                    execvp(args[0], &args[0]);
                else
                    waitpid(redirect, NULL, 0);
                    
                close(in);
                close(out);               
                exit(EXIT_SUCCESS);                
            }
            else if(command == "PIPE"){
                string first, second;
                vector<char *> args2;

                cin.ignore();
                cout << "What is the first command? ";
                args = GetAndParse();
                
                cout << "What is the second command? ";
                args2 = GetAndParse();

                int fd[2];

                pipe(fd);

                int pid = fork();

                if(pid == 0)
                {
                    close(fd[1]);
                    close(0);
                    dup(fd[0]);
                    close(fd[0]);
                    execvp(args2[0], &args2[0]);
                    //exit(EXIT_SUCCESS);
                } 
                else
                {   
                    int pid = fork();

                    if(pid == 0)
                    {
                        close(fd[0]);
                        close(1);
                        dup(fd[1]);
                        close(fd[1]);
                        execvp(args[0], &args[0]);
                        exit(EXIT_SUCCESS);                
                    }
                    else
                        waitpid(pid, NULL, 0);
                }    
            }
            else if(command == "STARWARS"){
                string telnet = "telnet", serv = "towel.blinkenlights.nl";
                char * temp = new char [25];

                strcpy(temp, telnet.c_str());
                args.push_back(temp);
                temp = new char [25];
                strcpy(temp, serv.c_str());
                args.push_back(temp);
                test = execvp(args[0], &args[0]);
                
                                      
                exit(EXIT_SUCCESS);
            }
            else if(command == "DRUGWARS"){
                string telnet = "telnet", serv = "zombiemud.org";
                char * temp;

                temp = new char[20];
                strcpy(temp, telnet.c_str());
                args.push_back(temp);
                
                temp = new char[20];
                strcpy(temp, serv.c_str());
                args.push_back(temp);

                test = execvp(args[0], &args[0]);

                exit(EXIT_SUCCESS);
            }

            if(test == -1){
                cout << "exec failure\n";
            }
            test = 0;

            exit(EXIT_SUCCESS);
        }
        else{
            waitpid(child, NULL, 0);
        }
        
    }while(command != "EXIT");
    
    return 0;
}

void Prompt(string p)
{
    cout << p;
}

void ClearScreen()
{
    cout << string(100, '\n');
    return;
}

vector<char *> GetAndParse()
{
    vector<char *> args;
    string input;
    char* temp;
  
    
    getline(cin, input);

    stringstream parse(input);
    
    while(getline(parse, input, ' '))
    {
        temp = new char[20];
        strcpy(temp, input.c_str());
        args.push_back(temp);
    }
    
    return args;    
}

//this is a comment
