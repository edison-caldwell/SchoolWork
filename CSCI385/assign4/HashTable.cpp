#include "HashTable.h"

HashTable::HashTable()
{
    
}

HashTable::HashTable(const HashTable& other)
{
    
}


HashTable& HashTable::operator=(const HashTable& other)
{
    
}


void HashTable::CreateHash(bool sorted)
{
    srand(time(NULL));
    
    for(int i = 0; i < n; i++)
        Insert(rand() % (max + abs(min) + 1) - abs(min), sorted); 
}


void HashTable::SetMax(int m)
{
    max = m;
}


void HashTable::SetMin(int m)
{
    min = m;
}


void HashTable::SetSize(int size)
{
    n = size;
}


void HashTable::Find(int search)
{
    int i = abs(search % 10);

    probes = table[i].Find(search);
}


void HashTable::Insert(int temp, bool sorted)
{
    int index = abs(temp % 10);
    table[index].Insert(temp, sorted);
}


void HashTable::Print()
{
    for(int i = 0; i < 10; i++){
        cout << "Bucket: " << i << endl;
        table[i].Print();
        cout << endl << endl;
    }
}


int HashTable::Probes(int search)
{
    Find(search);
    return probes;
}





    
    
