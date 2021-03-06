#ifndef LIST_
#define LIST_

#include <iostream>

using namespace std;


class List{
	public:
		struct Node;
		typedef Node* nodePtr;
		struct Node{
			int data;
			nodePtr next;
			nodePtr prev;

		};

		List();
		~List();
		List& operator=(const List& other);
		List(const List& other);
        
        void Reset();
        bool GetNext();
        int GetData();
		void Insert(int i);
		void Print();


	private:
		nodePtr head;
		nodePtr current;
		nodePtr tail;
};
#endif
