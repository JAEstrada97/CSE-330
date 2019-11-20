//Phillip Pascual
//lab5.cpp
//5.3.18
//CSE 330, Spring 2018 Lab 5

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector.h"
#include "list.h"

using namespace std;

//Binary Search for Vector
int binarySearch(int x, const Vector<int> & vec, int & steps)
{
    int low = 0;
    int high = vec.size() - 1;
    steps = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        steps++;
        if (vec[mid] < x)
        {
            low = mid + 1;
        } else if (vec[mid] > x)
        {
            high = mid - 1;
        } else
            return mid;
    }
    return -1; //Not found
}

//Binary Search for List
int binarySearchList(int x, const List<int> & vec, int & steps)
{
    int low = 0;
    int high = vec.size();

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (vec.nth(mid,steps) < x)
        {
            low = mid + 1;
        } else if (vec.nth(mid,steps) > x)
        {
            high = mid - 1;
        } else
            return mid;
    }
    return -1; //Not found
}

void randSeed()
{
    int seed = static_cast<int>(time(0));
    srand(time(0));
    return;
}

int randInt(int a, int b)
{
    return a + rand() % (b - a + 1);
}

void randomVectorAsc(int k, Vector<int> & vec)
{
    if (k <= 0)
    {
        return;
    }
    int rnum = randInt(1,9);

    vec.push_back(rnum);
    int prev = rnum;
    for (int i = 1; i <= k - 1; ++i)
    {
        int next = prev + randInt(1,9);
        vec.push_back(next);
        prev = next;
    }
    return;
}

void randomListAsc(int k, List<int> & vec)
{
    if (k <= 0)
    {
        return;
    }
    int rnum = randInt(1,9);

    vec.push_back(rnum);
    int prev = rnum;
    for (int i = 1; i <= k - 1; ++i)
    {
        int next = prev + randInt(1,9);
        vec.push_back(next);
        prev = next;
    }
    cout << vec.size() << endl;
    cout << endl;
}

int main()
{
    Vector<int> searchVector;
    List<int> searchList;
    int steps;

    randomListAsc(25,searchList);
    randomVectorAsc(1000,searchVector);

    /*for (int i = 0; i < searchVector.size(); ++i)
    {
        cout << searchVector[i] << " ";
    }
    cout << endl;*/
    
    for (int i = 0; i < searchList.size(); ++i)
    {
       cout << searchList.nth(i,steps) << " ";
    }
    cout << endl;

    int search;
    cout << "Please enter number to search for: ";
    cin >> search;

    /*cout << "Index position: " << binarySearch(search, searchVector, steps)
        << endl;
    cout << "Number of steps: " << steps;
    cout << endl;*/

    cout << "Index position: " << binarySearchList(search,searchList,steps)
        << endl;
    cout << "Number of steps: " << steps;
    cout << endl;

    return 0;
}
