//Phillip Pascual
//Sort.h
//6.5.28
//Header files for Sort

#ifndef SORT_H
#define SORT_H

#include <vector>

using namespace std;

template<typename C>
void printVec(vector<C> v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

//Simple insertion sort
template<typename Comparable>
void insertionSort(vector<Comparable> & a) {
    for (int p = 1; p < a.size(); ++p) {
        Comparable tmp = std::move(a[p]);
        int j;
        for (j = p; j > 0  && tmp < a[j-1]; --j) {
            a[j] = std::move(a[j-1]);
        }
    a[j] = std::move(tmp);
    }
}

template<typename Comparable>
void selectionSort(vector<Comparable> & a) {
    for (int i = a.size() -1; i > 0; i--) {
        int largepos = 0;
        for (int j = 1; j <= 1; j++) {
            if (a[largepos] < a[j])
                largepos = j;
        }
        if (i != largepos)
            std::swap(a[i], a[largepos]);
    }
}

//prototype for mergesort functions
template<typename Comparable>
void merge(vector<Comparable> &, vector<Comparable> &, int, int);

template<typename Comparable>
void mergeSort(vector<Comparable> &, vector<Comparable> &, int, int);

//mergesort algorithm
template<typename Comparable>
void mergeSort(vector<Comparable> & a) {
    vector<Comparable> tmpVec(a.size());
    mergeSort(a, tmpVec, 0, a.size() - 1);
}

/* Internal method that makes recursive calls
 * a is an array of Comparable items
 * tmpVec is an array to place the merged result
 * left is the left-most index of the subarray
 * right is the right-most index of the subarray
*/

template<typename Comparable>
void mergeSort(vector<Comparable> &a, vector<Comparable> &tmpVec, int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(a, tmpVec, left, center);
        mergeSort(a, tmpVec, center + 1, right);
        merge(a, tmpVec, left, center + 1, right);
    }
}

/* Internal method that merges two sorted halves of a subarray
 * a is an array of Comparable items
 * tmpVec is an array to place the merged result
 * leftPos is the left-most index of the subarray
 * rightPos is the index of the start of the second half
 * rightEnd is the right-most index of the subarray
*/

template<typename Comparable>
void merge(vector<Comparable> &a, vector<Comparable> &tmpVec,
           int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos - 1;
    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmpVec[tmpPos++] = std::move(a[leftPos++]);
        } else {
            tmpVec[tmpPos++] = std::move(a[rightPos++]);
        }
    }
    while (leftPos <= leftEnd) {
        tmpVec[tmpPos++] = std::move(a[leftPos++]);
    }
    while (rightPos <= rightEnd) {
        tmpVec[tmpPos++] = std::move(a[rightPos++]);
    }
    for (int i = 0; i < numElements; ++i, --rightEnd) {
        a[rightEnd] = std::move(tmpVec[rightEnd]);
    }
}

#endif