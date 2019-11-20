//Phillip Pascual
//homework2.cpp
//5.6.2018
//Main for Homework 2

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector.h"
#include "list.h"
#include "BinarySearch.h"
#include "BinarySearch.cpp"

using namespace std;

//Seeds RNG
void randSeed() {
    int seed = static_cast<int>(time(0));
    srand(seed);
    return;
}

//Returns a random integer between a and b
int randInt(int a, int b) {
    return a + rand() % (b - a + 1);
}

//Generates ascending random Vector of size k
void randomVectorAsc(int k, Vector<int> &vec) {
    if (k <= 0) {
        return;
    }
    
    randSeed();

    int rnum = randInt(1,9);

    vec.push_back(rnum);
    int prev = rnum;
    for (int i = 1; i <= k - 1; ++i) {
        int next = prev + randInt(1,9);
        vec.push_back(next);
        prev = next;
    }
    return;
}

//Generates ascending random List of size k
void randomListAsc(int k, List<int> &vec) {
    if (k <= 0) {
        return;
    }
    
    randSeed();

    int rnum = randInt(1,9);

    vec.push_back(rnum);
    int prev = rnum;
    for (int i = 1; i <= k - 1; ++i) {
        int next = prev + randInt(1,9);
        vec.push_back(next);
        prev = next;
    }
    return;
}

//Vector test function
void vectorTest(Vector<int> &vec,int &steps) {
    cout << "How many times to test Vector: ";
    int times;
    cin >> times;

    for (int i = 1; i <= times; ++i) {
        cout << "Test #: " << i << endl;
        randomVectorAsc(32,vec);
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i] << " ";
        }
        cout << endl;
        cout << "Please enter number to search for: ";
        int search;
        cin >> search;
        cout << "Index position: " << binarySearch(search,vec,steps) << endl;
        cout << "Cost: " << steps << endl;
        cout << "--------------------" << endl;
        //Erases Vector for next test
        while (!vec.empty()) {
            vec.pop_back();
        }
    }
    cout << endl;
}

//List test function
void listTest(List<int> &vec, int &steps) {
    cout << "How many times to test List: ";
    int times;
    cin >> times;

    for (int i = 1; i <= times; ++i) {
        cout << "Test #: " << i << endl;
        randomListAsc(32,vec);
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec.nth(i,steps) << " ";
        }
        cout << endl;
        cout << "Please enter number to search for: ";
        int search;
        cin >> search;
        cout << "Index position: " << binarySearchList(search,vec,steps) <<
            endl;
        cout << "Cost: " << steps << endl;
        cout << "--------------------" << endl;
        //Erases List for for next test
        vec.clear();
    }
    cout << endl;
}

int main() {
    Vector<int> searchVector;
    List<int> searchList;
    int steps;

    cout << "Which data structure to test (1-Vector, 2-List): ";
    int choice;
    cin >> choice;

    while (choice != 1 && choice != 2) {
        cout << "Please enter 1 or 2: ";
        cin >> choice;
    }

    if (choice == 1) {
        vectorTest(searchVector,steps);
    } else {
        listTest(searchList,steps);
    }

    return 0;
}
