//Phillip Pascual
//BinarySearchTreeMain.cpp
//5.8.18
//Main function for Lab 6

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "BinarySearchTreeLab7.h"

using namespace std;

void randSeed() {
    int seed = static_cast<int>(time(0));
    srand(seed);
    return;
}

int randInt(int a,int b) {
    return a + rand() % (b - a + 1);
}

int main() {
    BinarySearchTree<int> bst;
    vector<int> removed;

    randSeed();

    cout << "How big? ";
    int size;
    cin >> size;
    cout << endl;

    for (int i = 1; i <= size; ++i) {
        bst.insert(randInt(1,999));
    }
    bst.printInternal();

    int take;
    for (int i = 1; i <= 5; ++i) {
        cout << "Number to remove: ";
        cin >> take;
        cout << endl;
        bst.remove(take);
        removed.push_back(take);
    }

    cout << "Tree with removed elements:" << endl;
    bst.printInternal();
    cout << endl;

    for (int i = 0; i < removed.size(); ++i) {
        bst.insert(removed[i]);
    }
    cout << "Tree with re-inserted elements:" << endl;
    bst.printInternal();
    return 0;
}
