// BinarySearchMain.cpp
// KV, April 2018

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector.h"
#include "List.h"
#include "BinarySearch.h"

using namespace std;

void rand_seed()
{
  int seed = static_cast<int>(time(0));
  srand(seed);
  return;
}

int rand_int(int a, int b)
{
  return a+ rand() % (b - a + 1);
}

void random_vector_asc(int k, Vector<int>& vec)
{
  if (k <= 0)
    return;
  int rnum = rand_int(1,9);
  
  vec.push_back(rnum);
  int prev = rnum;
  for (int i = 1; i <= k-1; i++)
    {
      int next = prev + rand_int(1,9);
      vec.push_back(next);
      prev = next;
    }
  return;
}

void random_list_asc(int k, List<int>& lst)
{
  if (k <= 0)
    return;
  int rnum = rand_int(1

		      ,9);
  lst.push_back(rnum);
  int prev = rnum;
  int next;
  for (int i = 2; i <= k; i++)
    {
      next = prev + rand_int(1,9); 
      lst.push_back(next);
      prev = next;
    }
  return;
}
      

int main()
{
  Vector<int> searchvec;


  rand_seed();
  random_vector_asc(25,searchvec);

  for (int i = 0; i < searchvec.size(); i++)
    cout << searchvec[i] << " ";
  cout << endl << endl;

  // search for 5 numbers;
  cout << "Now  searching the vector ..." << endl;
  int next;
  for (int i = 1; i <= 5; i++)
    {
      int cost = 0;
      cout << "Search for which number? ";
      cin >> next;
      cout << endl;

      int found = binary_search(next, searchvec, cost);

      if (found != -1)
	{
	  cout << "Item " << next << " found at index " << found
	       << " at cost " << cost << endl;
	}
      else
	cout << "item " << next << " not found at cost " << cost << endl; 
    }
  cout << endl << endl;
       
  List<int> searchlst;
  random_list_asc(25,searchlst);

  List<int>::iterator itr = searchlst.begin();
  for (; itr != searchlst.end(); ++itr)
    cout << *itr << " ";
  cout << endl << endl;
  

  // search for 5 numbers
  cout << "Searching the list ..." << endl;
  
  for (int i = 1; i <= 5; i++)
    {
      int cost = 0;
      cout << "Search for which number? ";
      cin >> next;
      cout << endl;

      int found = binary_search(next, searchlst, cost);

      if (found != -1)
	{
	  cout << "Item " << next << " found at index " << found
	       << " at cost " << cost << endl;
	}
      else
	cout << "Item " << next << " not found at cost " << cost << endl;
    }

  cout << endl;
  return 0;
}

    
