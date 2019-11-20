//Phillip Pascual
//BinarySearch.cpp
//5.6.2018
//Binary Search Function Definitions for Homework 2

#include <iostream>
#include "BinarySearch.h"
#include "Vector.h"
#include "list.h"

using namespace std;

//Binary Search for Vector
int binarySearch(int x, const Vector<int> &vec, int &steps) {
    int low = 0;
    int high = vec.size() - 1;
    steps = 0;

    while(low <= high) {
        int mid = (low + high) / 2;
        steps++;
        if (vec[mid] < x) {
            low = mid + 1;
        } else if (vec[mid] > x) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1; //If x not found
}

//Binary Search for List
int binarySearchList(int x, const List<int> &vec, int &steps) {
    int low = 0;
    int high = vec.size();
    int cost = 0;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (vec.nth(mid, steps) < x) {
            low = mid + 1;
            cost += steps;
        } else if (vec.nth(mid, steps) > x) {
            high = mid - 1;
            cost += steps;
        } else {
            return mid;
        }
    }
    steps = cost;
    return -1; //If x not found
}

