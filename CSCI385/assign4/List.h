//SORT CLASS

#ifndef LIST_
#define LIST_

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

class List{

	public:
		enum Sort{BUBBLE, SELECTION, HEAP, MERGE, QUICK};
		enum SortedBy{NONE, NORMAL, REVERSE};
		// typedef void (List::*FunctionPointer)();
		// FunctionPointer sortsArr[5] = {&List::BubbleSort, &List::SelectionSort, &List::HeapSort, &List::MergeSort, &List::QuickSort};

		
		List(int size, SortedBy type = List::NONE);
		List(const List& other);
		~List();
		List& operator=(const List& other);

		
		void BubbleSort();
		//Performs a Bubble sort on the list
		//Pre: Populate() has been called
		//Post: List is sorted
		
		void SelectionSort();
		//Performs a Selection sort on the list
		//Pre: Populate has been called
		//Post: List is sorted
		
		void HeapSort();
		//Performs a Heap sort on the list 
		//Pre: List has been populated, heap created.
		//Post: List has been sorted. 

		void MergeSort();
		//Performs a merge sort on the list.
		//Pre:List has been populated
		//Post: List has been sorted.

		void QuickSort();
		//Performs a Quick sort on the list.
		//Pre:List has been populated
		//Post: List has been sorted.
	

		void CheckSort(Sort type);
		//Compares the sorted list to a vector sorted by the predefined vector sort.
		//Pre: List has been populated.
		//Post: Comparison has been output to screen. 



		

	private:
		
		void Print();
		void PrintCheck();List();
		void Clone(const List& other);
		void Populate(SortedBy);
		void Parse(int*,int, int);
		void Merge(int*, int, int, int);
		void Heapify(int, int);
		void BuildHeap();
        void GottaGoFast(int*, int, int);

		int* arrPtr;
		int length;
		vector<int> check;
        static const string sortList[5];

};

#endif
