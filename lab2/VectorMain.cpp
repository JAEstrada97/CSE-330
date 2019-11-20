//Phillip Pascual
//VectorMain.cpp
//4.10.18
//Main function to test Vector Class

#include <iostream>
#include "Vector.h"

using namespace std;

void printVector(Vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    Vector<int> v1;
    for (int i = 1; i <= 10; ++i)
    {
        v1.push_back(i);
    }

    cout << "v1: ";
    printVector(v1);

    Vector<int> v2(v1);

    cout << "v2(v1): ";
    printVector(v2);

    Vector<int> v3 = v2;

    cout << "v3 = v2: ";
    printVector(v3);

    Vector<int> v4(static_cast<Vector<int>&&>(v3));

    cout << "v4(&&v3): ";
    printVector(v4);
    cout << "v3: ";
    printVector(v3);

    Vector<int> v5 = static_cast<Vector<int>&&>(v2);

    cout << "v5=&&v2: ";
    printVector(v5);
    cout << "v2: ";
    printVector(v2);

    v5.erase(3);
    cout << "v5 (index 3 erased): ";
    printVector(v5);
    v5.erase(8);
    cout << "v5 (index 8 erased): ";
    printVector(v5);

    v5.insert(3,100);
    cout << "v5 (100 inserted at index 3): ";
    printVector(v5);
    v5.insert(9,999);
    cout << "v5 (999 inserted at index 9): ";
    printVector(v5);

    Vector<int> test;
    for (int i = 0; i < 10; ++i)
    {
        test.push_back(i+1);
    }
    cout << "Homework vector: ";
    printVector(test);

    return 0;
}
