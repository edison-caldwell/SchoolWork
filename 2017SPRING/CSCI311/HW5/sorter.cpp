#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fcntl.h>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void ReadFile(int size, off_t offset, vector<int> &vec, char* argv[]);
void WriteFile(int size, off_t offset, vector<int> vec, char* argv[]);
void PrintVec(vector<int> vec);

mode_t mode;

int main(int argc, char* argv[])
{
    if(argc != 2){
        errno = EACCES;
        perror("Usage: ./sorter [inputFile] \nExit Status: ");
        exit(EXIT_FAILURE);
    }
    
    int a = -1, b = -1, a1 = -1, b1 = -1;
    //     int initArr[100];
    //     int * left_a, * right_a, * left_b, * right_b;
    //     int * bottom;
    //     int * top;
    //     int * result;
    //int readFD = 0, writeFD = 1;
    
    //int* buffer;
    //ssize_t rwAmmt;
    
    //     bottom = (int*)mmap(NULL, sizeof(int)*50, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    //     top = (int*)mmap(NULL, sizeof(int)*50, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    //     result = (int*)mmap(NULL, sizeof(int)*100, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    //     left_a = (int*)mmap(NULL, sizeof(int)*25, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);  
    //     left_b = (int*)mmap(NULL, sizeof(int)*25, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    //     right_a = (int*)mmap(NULL, sizeof(int)*25, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    //     right_b = (int*)mmap(NULL, sizeof(int)*25, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    
    mode = S_IRUSR | S_IWUSR |
            S_IRGRP | S_IWGRP |
            S_IROTH | S_IWOTH;
    
    //     int count = 0;
    //     for(int i = 0; i < 100; i++)
    //     {
    //         if(count == 25)
    //             count = 0;
    // 
    //         if(i < 25)
    //             left_a[count] = initArr[i];
    //         else if(i < 50)
    //             right_a[count] = initArr[i];
    //         else if(i < 75)
    //             left_b[count] = initArr[i];
    //         else if(i < 100)
    //             right_b[count] = initArr[i];
    // 
    //         count++;
    //     }
    
    a = fork();
    
    
    
    if(a == 0){
        b = fork();
        
        if(b == 0){
            b1 = fork();
            
            if(b1 == 0){
                vector<int> vec_b1;
                
                ReadFile(25, 75, vec_b1, argv);
                //PrintVec(vec_b1);
                sort(vec_b1.begin(), vec_b1.end());
                //PrintVec(vec_b1);
                WriteFile(25, 75, vec_b1, argv);
            
                exit(EXIT_SUCCESS);
            }
            else{
                vector<int> vec_b;
                vector<int> vec_b1;
                vector<int> res(50);
                
                ReadFile(25, 50, vec_b, argv);
                //cout << "\n\nProc_B before sort\n";
                //PrintVec(vec_b);
                sort(vec_b.begin(), vec_b.end());
                //cout << "\n\nProc_B after sort\n";
                //PrintVec(vec_b);
                waitpid(b1, NULL, 0);
                
                ReadFile(25, 75, vec_b1, argv);
                merge(vec_b.begin(), vec_b.end(), vec_b1.begin(), vec_b1.end(), res.begin());
                //cout << "\n\nB and B1 merge results\n";
                //PrintVec(res);
                WriteFile(50, 50, res, argv);
                
                exit(EXIT_SUCCESS);
            }
            
        }
        else {
            a1 = fork();
            
            if(a1 == 0){
                vector<int> vec_a1;
                ReadFile(25, 25, vec_a1, argv);
                sort(vec_a1.begin(), vec_a1.end());                
                WriteFile(25, 25, vec_a1, argv);
                
                exit(EXIT_SUCCESS);
                
            }
            else{
                vector<int> vec_a;
                vector<int> vec_a1;
                vector<int> top;
                vector<int> bottom(50);
                vector<int> res(100);
                
                ReadFile(25, 0, vec_a, argv);
                sort(vec_a.begin(), vec_a.end());
                WriteFile(25, 0, vec_a, argv);
                waitpid(a1, NULL, 0 );
               
                ReadFile(25, 25, vec_a1, argv);
                merge(vec_a.begin(), vec_a.end(), vec_a1.begin(), vec_a1.end(), bottom.begin());
                WriteFile(50, 0, bottom, argv);
                
                waitpid(b, NULL, 0);
                ReadFile(50, 50, top, argv);
                merge(bottom.begin(), bottom.end(), top.begin(), top.end(), res.begin());
                WriteFile(100, 0, res, argv);
            }
        }
        
    }
    
   // waitpid(a, NULL, 0);
    return 0;
}


void ReadFile(int size, off_t offset, vector<int> &vec, char * argv[])
{
    int readFD = open(argv[1], O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    lseek(readFD, sizeof(int)*0, SEEK_SET);
    lseek(readFD, offset*sizeof(int), SEEK_SET);
    int temp = 0;
    int rAmmount = 0;
    
    for(int i = 0; i < size; i++){
        rAmmount = read(readFD, &temp, sizeof(int));
        vec.push_back(temp);
        //cout << rAmmount << "\t" << vec[i] << endl;
        
    }

    close(readFD);

    return;
}

void WriteFile(int size, off_t offset, vector<int> vec, char* argv[])
{
    int writeFD = open(argv[1], O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    lseek(writeFD, sizeof(int)*0, SEEK_SET);
    lseek(writeFD, offset*sizeof(int), SEEK_SET);

    
    for(int i = 0; i < size; i++){
        write(writeFD, &vec[i], sizeof(int));
    }
    
    close(writeFD);

    return;
}

void PrintVec(vector<int> vec)
{
    cout << "\n\n\n";
    for(int i = 0; i < vec.size(); i ++){
        cout << "[" << i << "]\t" << vec[i] << endl;
    }
}

