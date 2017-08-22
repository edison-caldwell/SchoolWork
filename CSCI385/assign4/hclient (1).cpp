#include "HashTable.h"
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>

int main()
{    
    int arr[10] = {25,50,100,200,250,25,50,100,200,250};
    HashTable tests[10];


    bool sorted = false;

    ofstream outFile;

    

    for(int i = 0; i < 10; i++){
        if(i > 4)
            sorted = true;

        tests[i].SetSize(arr[i]);
        tests[i].SetMax(125);
        tests[i].SetMin(-125);
        tests[i].CreateHash(sorted);

        cout << "Hash table size " << arr[i] << " created.\n";

    }
    
    ostringstream sstream;
    
    ofstream avgFile;
    avgFile.open("Averages.txt");

    sorted = false;

    for(int i = 0; i < 10; i++){

        float avg = 0;

        string pause;

        sstream << i;

        string file = "HashTable" + sstream.str() + ".txt";

        outFile.open(file.c_str());

        tests[i].Print();
        //getline(cin, pause, '\n');
        cout << endl;

        cout << "Hash table with " << arr[i] << " units.";

        if(i > 4)
            cout << "\nEach bucket is sorted.\n";

        cout << endl;

        for(int j = -125; j <= 125; j++){
            cout << "|Probes for " << j << ": " << tests[i].Probes(j) << "|\n";
            outFile << j << " " << tests[i].Probes(j) << endl;
            avg += tests[i].Probes(j); 
        }

        avg /= arr[i];
        if(i > 4)
            sorted = true;

        avgFile << arr[i] << " " << sorted << " " << avg << endl;

        outFile.close();
        sstream.clear();
        sstream.str(std::string());
        cout << "\n\n";
    }

    avgFile.close();


    //delete [] tests;

    return 0;
}
    
    
