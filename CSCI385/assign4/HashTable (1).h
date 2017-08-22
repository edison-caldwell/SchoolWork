//Hash table class
#ifndef _HASHTABLE
#define _HASHTABLE

#include "Bucket.h"
#include "stdlib.h"

class HashTable{
    
public:
    HashTable();
    
    HashTable(const HashTable& other);
    
    HashTable& operator=(const HashTable& other);
    
    void CreateHash(bool);
    
    void SetMax(int);
    
    void SetMin(int);
    
    void SetSize(int);
    
    void Find(int);
    
    void Insert(int, bool sorted);

    void Print();

    int Probes(int);
    
private:
    Bucket table[10];
    int min;
    int max;
    int n;
    int probes;
    
};

#endif
