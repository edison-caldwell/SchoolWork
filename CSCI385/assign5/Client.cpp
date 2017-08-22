#include "Graph.h"


int main()
{
    int sValue;
	Graph test;

	test.SetNumNodes();

	test.SetAdjList();
    
    cout << "\n\n";
    
    test.PrintAdjLists();
    
    cout << "Please pick a node between 0 and " << test.GetNumNodes() - 1 << " to perform\na breadth first search on: ";
    cin >> sValue;
    test.BreadthFirstSearch(sValue);
    
    cout << "\n\n";
    test.PrintBFS();
    cout << "\n\n";
    
    cout << "Please pick a node between 0 and " << test.GetNumNodes() - 1 << " to perform\na depth first search on: ";
    cin >> sValue;
    test.DepthFirstSearch(sValue);
    
    cout << "\n\n";
    test.PrintDFS();
    cout << "\n\n";
    
	return 0;
}
