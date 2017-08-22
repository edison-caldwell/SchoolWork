//BUCKET CLASS 
#ifndef BUCKET_
#define BUCKET_

#include <iomanip>
#include <iostream>

using namespace std;

class Bucket
{
public: 

    struct Node;
    
    typedef Node* nodePtr;

    struct Node{
        int value;
        nodePtr next;
        Node(int inValue)
        {
            value = inValue;
            next = NULL;
        }
    };



    /*Constructor, destructor, overloaded copy, ect.*/

    
    Bucket();
    //Constructor
    //Pre:
    //Post: List is instantiated.
    
    ~Bucket();
    //Destuctor
    //Pre:
    //Post: All memory deallocated

    Bucket(const Bucket& other);
    //Copy Constructor
    //Pre:
    //Post: this holds the same internal values as other

    Bucket& operator=(const Bucket& other);
    //Overloaded Assignment
    //Pre:
    //Post: this holds the same internal values as other;

    //friend ostream& operator<<(ostream &output, const List& l);



    /*Transormers (robots in disguise)******/
    void Insert(int, bool);
    //Pre: Item is not already in the list.
    //Post: Item added to list with all private data.
    
    void Remove();
    //Pre: 
    //Post: Last item is removed from list.
    
    /*Observers*****************************/

    int NodeValue() const;
    //Returns currentPtr->Name 
    //Pre:
    //Post: Name is returned

    /*Pointer manipulators*******************/
    
    int Find(int search);
    //Finds the value of search within the list
    //Pre: List exists.
    //Post: if found, the value is returned.

    void GetNext();
    //Sets temp to temp->next
    //Pre: temp is a pointer within the class
    //Post: The correct pointer is incremented.
    
    void GetPrevious(nodePtr temp);
    //Sets temp to temp->previous
    //Pre: 
    //Post: The correct pointer is decremented. 
    
    void Reset();
    //Sets currentPtr to head
    //Pre: 
    //Post: currentPtr is set to head

    void Print();
    

    
    
private:

    nodePtr head;
    nodePtr tail;
    nodePtr previous;
    nodePtr current;
    bool sorted;
};

#endif
    
    
