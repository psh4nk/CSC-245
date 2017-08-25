#include <iostream>
#include "BinaryHeap.h"

int main()
{
	BinaryHeap<char> PQ(50);
	PQ.insert('A');
	PQ.insert('B');
	PQ.insert('C');
	PQ.insert('D');
	PQ.insert('E');
	PQ.insert('F');
	PQ.insert('G');
	PQ.insert('H');
	PQ.insert('I');
	PQ.insert('J');
	PQ.deleteMin();
	cout << "Printing Left Subtree of the Root of the Heap : ";
        PQ.printLtSubtree();
	cout << "\n";
	cout << "The Height of Heap is : "  << PQ.Height() << endl;
	cout << "The Maximum Value of Heap Is : " << PQ.findMax() << endl; 
	return 0;
}
