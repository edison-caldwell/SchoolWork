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
		
		void SelectionSort();
		
		void HeapSort();

		void MergeSort();

		void QuickSort();

		void CheckSort(Sort type);

		void Print();
		
		void PrintCheck();


		

	private:
		List();
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
