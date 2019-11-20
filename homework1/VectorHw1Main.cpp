//Phillip Pascual
//VectorHw1Main.cpp
//4.14.18
//Homework 1, Spring 2018

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
    Vector<int> test;
    
    for (int i = 0; i < 10; ++i)
    {
        test.push_back(i+1);
    }

    cout << "Original Vector: ";
    printVector(test);
    cout << endl;

    //1. Erase the element at the highest index
    test.erase(10);
    cout << "1: Erase the element at the highest index:" << endl;
    printVector(test);
    cout << endl;

    //2. Erase the element at index 3
    test.erase(3);
    cout << "2: Erase the element at index 3:" << endl;
    printVector(test);
    cout << endl;

    Vector<int> test2;

    for (int i = 0; i < 10; ++i)
    {
        test2.push_back(i+1);
    }

    //3. Insert integer 777 at position 10
    test2.insert(10,777);
    cout << "3: Insert integer 777 at position 10:" << endl;
    printVector(test2);
    cout << endl;

    //4. Insert integer 777 at position 5
    test2.insert(5,777);
    cout << "4: Insert integer 777 at position 5:" << endl;
    printVector(test2);
    cout << endl;

    return 0;
}
