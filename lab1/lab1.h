#ifndef LAB1_H
#define LAB1_H

#include <iostream>

/******************************************************************************
 * Phillip Pascual
 * lab1.h
 * 4.3.18
 * Put all function and class code into this file
 *****************************************************************************/

using namespace std;

//Exercise 1,2
void printDiag(int n) {
    char matrix[n][n];
    
    //Fills 2-d array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = i+49;
            } else {
                matrix[i][j] = '_';
            }
        }
    }

    //Prints 2-d array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//Exercise 3
class SquareNumber {
public:
    SquareNumber(): base(0) {}
    SquareNumber(int n): base(n) {}
    //Copy constructor
    SquareNumber(const SquareNumber &other): base(other.base) {}
    void nextsq() {
        base++;
    }
    int getsq() {
        return base*base;
    }
    void prevsq() {
        base--;
    }

    SquareNumber &operator=(const SquareNumber &other) {
        base = other.base;
        return *this;
    }
private:
    int base;
};

//Exercise 4
void maxSum(vector<int> v) {
    int sum = 0;
    int max = 0;

    for (int i = 0; i < v.size()-1; i++) {
        sum = v[i];
        for (int j = i+1; j < v.size(); j++) {
            sum += v[j];
            if (sum > max) {
            max = sum;
            }
        }
        
    }
    cout << "Max subsequent sum: " << max << endl;
}
#endif
