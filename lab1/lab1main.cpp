/******************************************************************************
 * Phillip Pascual
 * lab1main.cpp
 * 4.3.18
 * Lab 1
 *****************************************************************************/

#include <iostream>
#include <vector>

#include "lab1.h"

using namespace std;

int main() {
    cout << "Enter a positive integer: ";
    int n;
    cin >> n;
    cout << endl;

    printDiag(n);

    SquareNumber mysq;
    for (int i = 1; i <=5; i++) {
        mysq.nextsq();
        cout << mysq.getsq() << " ";
    }
    cout << endl;

    SquareNumber sq2(mysq);
    for (int i = 1; i <= 5; i++) {
        cout << sq2.getsq() << " ";
        sq2.prevsq();
    }
    cout << endl;

    mysq = sq2;
    for (int i = 1; i <= 10; i++) {
        mysq.nextsq();
    }
    cout << mysq.getsq() << endl << endl;

    vector<int> num;
    num.push_back(5);
    num.push_back(-3);
    num.push_back(7);
    num.push_back(4);
    num.push_back(12);
    num.push_back(-6);

    maxSum(num);
}
