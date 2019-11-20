//Phillip Pascual
//BinarySearch.h
//5.6.2018
//Header Files for CSE330, Homework 2

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iostream>
#include "Vector.h"
#include "list.h"

using namespace std;

int binarySearch(int x, const Vector<int> &vec, int &steps);
int binarySearchList(int x, const List<int> &vec, int &steps);

#endif
