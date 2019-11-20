// TreeSortHeapSort.h

// KV, June 2018

// implemention of TreeSort and HeapSort;

#ifndef TSORTHSORT_H_
#define TSORTHSORT_H_

#include <vector>
#include "BST_HW4.h"
#include "BinaryHeap_HW4.h"

using namespace std;

extern int CLUMSY_COUNT;

template <typename C>
void TreeSort(vector<C>& data, int& comps)
{
  CLUMSY_COUNT = 0;

  BinarySearchTree<C> bst;

  for (int i = 0; i < data.size(); i++)
    {
      bst.insert(data[i]);
    }

  int i = 0;
  typename BinarySearchTree<C>::iterator itr = bst.begin();

  for (; itr != bst.end(); ++itr)
    {
      data[i] = *itr;
      i++;
    }
  comps = CLUMSY_COUNT;
}

template <typename C>
void HeapSort(vector<C>& data, int& comps)
{
  CLUMSY_COUNT = 0;

  BinaryHeap<C> bhp;

  for (int i = 0; i < data.size(); i++) {
    bhp.insert(data[i]);
  }
  
  int j = 0;
  
  for (; bhp.size() != 0; j++) {
    data[j] = bhp.findMin();
    bhp.deleteMin();
  }

  comps = CLUMSY_COUNT;
}
      
#endif