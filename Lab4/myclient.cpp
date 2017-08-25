#include <iostream>
#include "bst.h"
using namespace std;

int main()
{
        BinarySearchTree<int> T(-1);

        T.insert(5);
        T.insert(6);
        T.insert(4);
        T.insert(8);

        T.printTree();

        cout << T.findMin() << endl;
        cout << T.find(8) << endl;
        cout << T.find(9) << endl;
        return 0;
}

