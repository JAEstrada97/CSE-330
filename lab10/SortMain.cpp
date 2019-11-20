//Phillip Pascual
//SortMain.cpp
//6.5.18
//Main for CSE 330, Lab 9

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "Sort.h"

using namespace std;

int randSeed() {
    int seed = static_cast<int>(time(0));
    srand(seed);
}

int rng(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main() {

    randSeed();

    vector<int> originalVector;
    for (int i = 0; i < 20; ++i) {
        originalVector.push_back(rng(1,100));
    }

    for (int j = 0; j < originalVector.size(); ++j) {
        cout << originalVector[j] << " ";
    }
    cout << endl;

    //printVec(originalVector);

    return 0;
}
