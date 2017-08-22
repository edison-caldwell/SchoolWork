#include "List.h"
#include "stopwatch.h"
#include <iomanip>
#include <fstream>


int main()
{
	int sizes[4] = {20,200,2000,20000};
	string files[5] = {"Bubble.txt", "Selection.txt", "Heap.txt", "Merge.txt", "Quick.txt"};
	List::Sort type[5] = {List::BUBBLE, List::SELECTION, List::HEAP, List::MERGE, List::QUICK};
	List::SortedBy sortType[3] = {List::NONE, List::NORMAL, List::REVERSE};
	string sortOrder[3] = {"RANDOMLY" , "FORWARD" , "BACKWARD"};
	

	StopWatch timer;

	ofstream out;

	for(int i = 0; i < 5; i++)
	{
		out.open(files[i].c_str());

		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 3; k++){
				
				List myList(sizes[j], sortType[k]);

				timer.Start();

				if(i == 0)
					myList.BubbleSort();
				else if(i == 1)
					myList.SelectionSort();
				else if(i == 2)
					myList.HeapSort();
				else if(i == 3)
					myList.MergeSort();
				else if(i == 4)
					myList.QuickSort();

				timer.Stop();

				out << sizes[j] << " " <<  sortType[k] << " " << timer.GetTime() << endl;

				myList.CheckSort(type[i]);
				cout << "\nThe list was originally " << sortOrder[k] << " sorted.";
				cout << "\nThe run time was: " << timer.GetTime() << " milliseconds.\n\n";
			}
		}

		out.close();
	}
    
	return 0; 
}



