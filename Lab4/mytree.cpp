#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
	BinarySearchTree<int> t(0);
	
	t.insert(6);
	t.insert(2);
	t.insert(8);
	t.insert(1);
	t.insert(4);
	t.insert(3);
	t.insert(9);

	//Post order call
	t.postOrder();
	
	//Height call
	if( t.isEmpty() )
		cout << "Tree is empty. Fill tree to calculate height." << endl;
	else
		cout << "Height of the tree: " << t.height() << endl;
	
	//numLeaves call
	if( t.isEmpty() )
		cout << "Tree is empty. Fill tree to calculate number of leaves." << endl;
	else 	
		cout << "Number of leaves: " << t.numLeaves() << endl;;
	
	//isBalanced call
	if( t.isEmpty() )
		cout << "Tree is empty. Fill tree to see if tree is balanced." << endl;
	else if( t.isBalanced() )
		cout << "Tree is balanced. " << endl;
	else if( !t.isBalanced() )
		cout << "Tree is not balanced. " << endl;

	return 0;
}
