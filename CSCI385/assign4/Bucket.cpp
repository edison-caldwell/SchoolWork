#include "Bucket.h"


Bucket::Bucket()
{    
    head = NULL;
    tail = NULL;
    current = NULL;
}


Bucket::~Bucket()
{
    if(head){
        Reset();

        GetNext(head);

        while(head)
        {
            delete current;
            GetNext(head);
            GetNext(current);
            
        }
    }

    return;
}


Bucket::Bucket(const Bucket& other)
{
    nodePtr newBucketPtr = NULL;

    if(!other.head){
        head = NULL;
        current = NULL;
        previous = NULL;
        tail = NULL;
        sorted = false;
    }
    else
    {   
        sorted = other.sorted;
        nodePtr toCopy = other.head;
        nodePtr prevNode = NULL;


        head = new Node(toCopy->value);
        head->previous = NULL;
        head->next = NULL;

        prevNode = head;
        newBucketPtr = head;

        toCopy = toCopy->next;
        
        while(toCopy!= NULL)
        {
            newBucketPtr->next = new Node(toCopy->value);
            
            newBucketPtr = newBucketPtr->next;
            
            newBucketPtr->previous = prevNode;
            
            prevNode = newBucketPtr;
            
            newBucketPtr->next = NULL;

            toCopy = toCopy->next;
        }
    }
        
    tail = newBucketPtr;

    Reset();
}


Bucket& Bucket::operator=(const Bucket& other)
{
    nodePtr newBucketPtr = NULL;

    if(!other.head){
        head = NULL;
        current = NULL;
        previous = NULL;
        tail = NULL;
    }
    else
    {   
        nodePtr toCopy = other.head;
        nodePtr prevNode = NULL;


        head = new Node(toCopy->value);
        head->previous = NULL;
        head->next = NULL;

        prevNode = head;
        newBucketPtr = head;

        toCopy = toCopy->next;
        
        while(toCopy!= NULL)
        {
            newBucketPtr->next = new Node(toCopy->value);
            
            newBucketPtr = newBucketPtr->next;
            
            newBucketPtr->previous = prevNode;
            
            prevNode = newBucketPtr;
            
            newBucketPtr->next = NULL;

            toCopy = toCopy->next;
        }
    }
        
    tail = newBucketPtr;

    Reset();
}


void Bucket::Insert(int inValue, bool sorted)
{
    cout << "Bucket Insert\n";
    if(!head){
        cout << "If head is null\n";
        head = new Node(inValue);
        tail = head;
    }
    else if(sorted){
        Reset();
        
        while(current->next && current->next->value > inValue)
            GetNext(current);
        
        nodePtr temp = new Node(inValue);
        
        temp->previous = current;
        temp->next = current->next;
        
        current->next->previous = temp;
        current->next = temp;
        
        if(tail->next)
            GetNext(tail);
    }
    else{
        
        tail->next = new Node(inValue);
        tail->next->previous = tail;
        GetNext(tail);
    }

    tail->next = NULL;
}


void Bucket::Remove()
{
    nodePtr temp = tail;
    GetPrevious(tail);
    
    delete temp;
}


bool Bucket::Find(int search)
{
   Reset();

   while(current->value != search && current)
   {
        GetNext(current);  
   }
   
   if(current->value == search)
       return true;
   
   return false;
}


int Bucket::NodeValue() const
{
    if(current)
        return current->value;
}

void Bucket::GetNext(nodePtr temp) 
{
    temp = temp->next;
    
    return;
}


void Bucket::GetPrevious(nodePtr temp) 
{
    temp = temp->previous;
    return;
}


void Bucket::Reset()
{
    current = head;
    return;
}


