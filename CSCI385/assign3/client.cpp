#include <iostream> //cout, cin
#include <stdlib.h> //rand, srand, NULL
#include <ctime> //time
#include "stopwatch.h" //StopWatch
//#include <fstream> //ofstream

using namespace std;

void HaHaHa();

int main()
{

    int x = 0, y = 0, z = 0, count = 0, size = 0;
    //integers x/y/z are for tranversing the list to apply the triplesum algorithm.
    //count is used to record the number of triple sums
    //size is the list length to be parsed. 
    
    StopWatch t;
    //Object of class StopWatch to record time run time. 
    
    cout << "\n\n" << "Please pick a list size: ";
    cin >> size;
    cout << "\n\n";
    
    int* arr = new int[size];
    //allocate memory for a 1D array of length "size"
    
    srand(time(NULL));
    //seed rand
    
    for(int i = 0; i < size; i++)
        arr[i] = rand() % 2000001 + (-1000000);
    //create the array with random integers. range: (-1000000,1000000)
    
    t.Start();
    //start the stopwatch
    
    while(x < size)
    {
        y = x + 1;
        
        while(y < size)
        {
            z = y + 1;
            
            while(z < size)
            {
                if((arr[x] + arr[y] + arr[z]) == 0)
                    count++;
                
                z++;
            }
            
            y++;
        } 
        x++;
    }
    
    t.Stop();
    //stop the stopwatch
    
    
    cout << "\n\n" << "List Size: " << size << endl;
    cout << "Triple Sums: " << count << endl;
    cout << "Time: " << t.GetTime() << " seconds" << "\n\n\n\n";
    
    delete[] arr;
    //deallocate memory
    
    HaHaHa();

    return 0; 
}


void HaHaHa()
{}
