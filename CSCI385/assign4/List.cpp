#include "List.h"



const string List::sortList[5] = {"Bubble Sort", "Selection Sort", "Heap Sort", "Merge Sort", "Quick Sort"};


List::List()
{

}


List::List(int size, SortedBy type)
{
	arrPtr = new int[size];
	length = size;

	Populate(type);
}


List::~List()
{
	delete [] arrPtr;
}


List::List(const List& other)
{
	if(!other.arrPtr)
	{
		arrPtr = NULL;
	}
	else
	{
		Clone(other);
	}
}


List& List::operator=(const List& other)
{
	if(!other.arrPtr)
	{
		arrPtr = NULL;
	}
	else
	{
		Clone(other);
	}
}


void List::Populate(SortedBy type)
{
	srand(time(NULL));

	for(int i = 0; i < length; i++)
	{
		check.push_back(rand() % 2001 - 1000);
	}
		
	if(type == NORMAL){
			
		sort(check.begin(), check.end());

		for(int i = 0; i < length; i++){
			arrPtr[i] = check[i];
		}
	}
	else if(type == REVERSE)
	{
		sort(check.begin(), check.end());

		for(int i = 0; i < length; i++){
			arrPtr[i] = check[(length-1) - i];
		}

	}
	else if(type == NONE)
	{
		for(int i = 0; i < length; i++)
			arrPtr[i] = check[i];

		sort(check.begin(), check.end());
	}
	
	return;
	
}


void List::BubbleSort()
{
	int temp;

	for(int i = 0; i < length; i++){
		for(int j = 0; j < length - i - 1; j++){
			if( arrPtr[j] > arrPtr[j+1]){
				temp = arrPtr[j];
				arrPtr[j] = arrPtr[j + 1];
				arrPtr[j + 1] = temp;
			}
		}
	}

	return;
}


void List::SelectionSort()
{
	int temp, low, index;
	for(int i = 0; i < length; i++){
		low = arrPtr[i];
		index = i;
		
		for(int j = i+1; j < length; j++){
			if(low > arrPtr[j]){
				low = arrPtr[j];
				index = j;
			}
		}

		temp = arrPtr[i];
		arrPtr[i] = arrPtr[index];
		arrPtr[index] = temp;
	}

	return;
}


void List::HeapSort()
{
	BuildHeap();

	int temp, size;

	size = length-1;

	for(int i = size; i >= 0; i--){
		temp = arrPtr[0];
		arrPtr[0] = arrPtr[size];
		arrPtr[size] = temp;
		size--;
		Heapify(0, size);

	}
}


void List::BuildHeap()
{
	for(int i = (length/2); i >= 0; i--){
		Heapify(i, length-1);
	}
}


void List::Heapify(int i, int size)
{
	int temp, left, right, biggest;
	
	left = 2*i;
	right = 2*i + 1;

	if(left <= size && arrPtr[left] > arrPtr[i])
		biggest = left;
	else
		biggest = i;

	if(right <= size && arrPtr[right] > arrPtr[biggest])
		biggest = right;

	if(biggest != i){
		temp = arrPtr[i];
		arrPtr[i] = arrPtr[biggest];
		arrPtr[biggest] = temp;
		Heapify(biggest, size);
	}


	return;
}


void List::MergeSort()
{
    Parse(arrPtr, 0, length - 1); 
}


void List::Parse(int* arr, int left, int right)
{
   	if (left < right)
	{
		int middle = left + (right - left)/2;

		Parse(arr, left, middle);
		Parse(arr, middle + 1, right);

		Merge(arr, left, middle, right);
	}
}


void List::Merge(int* arr, int left, int middle, int right)
{
	int i, j, k;
	int num1 = middle - left + 1;
	int num2 = right - middle;

	int leftArr[num1], rightArr[num2];

	for (i = 0; i < num1; i++){
		leftArr[i] = arr[left + i];
    }
    
	for (j = 0; j < num2; j++){
		rightArr[j] = arr[middle + 1+ j];
    }

	i = 0; 
	j = 0; 
	k = left; 
    
	while (i < num1 && j < num2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			i++;
		}
		else
		{
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}

	
	while (i < num1)
	{
		arr[k] = leftArr[i];
		i++;
		k++;
	}

	
	while (j < num2)
	{
		arr[k] = rightArr[j];
		j++;
		k++;
	}
}


void List::QuickSort()
{
    GottaGoFast(arrPtr, 0, length - 1);
}

void List::GottaGoFast(int* arr, int left, int right)
{
    int i = left, j = right;
    int temp;
    int pivot = arr[(left + right) / 2];
    
    while(i <= j){
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        
        if(i <= j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    
    if(left < j)
        GottaGoFast(arr, left, j);
    if(i < right)
        GottaGoFast(arr, i, right);
}

void List::CheckSort(Sort type)
{
    for(int i = 0; i < length; i++){
        if(arrPtr[i] != check[i]){
            cout << "By comparison to vector.sort() algorithm, the " << sortList[type] << " failed.";
            return;
        }
    }    
        
    cout << "By comparison to vector library sort algorithm, the " << sortList[type] << " succeded for " << length << " units.";
    
    return;
    
}


void List::Clone(const List& other)
{
	arrPtr = new int[other.length];

		for(int i = 0; i < other.length; i++)
		{
			arrPtr[i] = other.arrPtr[i];
		}

		length = other.length;
}


void List::Print()
{
	for(int i = 0; i < length; i++){
		cout << arrPtr[i] << " ";
	}

	return;
}


void List::PrintCheck()
{
	for(int i = 0; i < length; i++){
		cout << check[i] << " ";
	}

	return;
}



