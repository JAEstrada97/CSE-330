// BinarySearchTreeMain.cpp
// afler Mark A. Weiss, Chapter 4  
#include <iostream>
#include "BinarySearchTreeLab7.h"
using namespace std;

int main( )
{
  BinarySearchTree<int> mybst;
  int k;

  cout << "How many? ";
  cin >> k;
  cout << endl << endl;
  int next;
  for (int i = 1; i <= k; i++)
    {
      cout << "Integer: ";
      cin >> next;
      cout << endl;
      mybst.insert(next);
    }
  cout << endl;
  cout << "Values stored in BST: " << endl;
  mybst.printTree();
  cout << endl;
  mybst.printInternal();
  cout << endl;
  mybst.parent_check();
  
  for(int i = 1; i <= 3; i++)
    {
      cout << "Remove which value? ";
      cin >> next;
      cout << endl;
      mybst.remove(next);
    }
  cout << endl;
  cout << "Values after removing 3 from BST:" << endl;
  mybst.printTree();
  cout << endl;
  mybst.printInternal();
  cout << endl;
  mybst.parent_check();
  
  return 0;
}
