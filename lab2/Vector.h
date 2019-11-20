#ifndef VECTOR_H
#define VECTOR_H

//Phillip Pascual
//Vector.h
//4.10.2018
//Definitions and functions for class Vector

#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class Vector 
{
private:
    int theSize;
    int theCapacity;
    T* objects;
public:
    static const int SPARE_CAPACITY = 2;

    //Default constructor
    Vector(int initsize = 0): theSize(initsize),
                              theCapacity(initsize + SPARE_CAPACITY)
    { objects = new T[theCapacity]; }

    //Copy constructor
    Vector(const Vector &rhs): theSize(rhs.theSize),
                               theCapacity(rhs.theCapacity),
                               objects(0)
    {
        objects = new T[theCapacity];
        for (int k = 0; k < theSize; ++k) 
        {
            objects[k] = rhs.objects[k];
        }
    }

    //Operator overload for = (uses lvalues)
    Vector &operator= (const Vector &rhs)
    {
        Vector copy(rhs);
        std::swap(*this, copy);
        return *this;
    }

    //Deletes data on heap
    ~Vector()
    { delete [] objects; }

    //Move operator
    Vector(Vector &&rhs): theSize(rhs.theSize),
                          theCapacity(rhs.theCapacity),
                          objects(rhs.objects)
    {
        rhs.objects = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }

    //Operator overload for = (uses rvalue)
    Vector &operator= (Vector &&rhs)
    {
        std::swap(theSize, rhs.theSize);
        std::swap(theCapacity, rhs.theCapacity);
        std::swap(objects, rhs.objects);
        return *this;
    }

    //Returns empty/not empty state
    bool empty() const
        { return size() == 0; }

    //Returns size
    int size() const
        { return theSize; }

    //Returns capacity
    int capacity() const
        { return theCapacity; }

    //Operator overload for []
    T &operator[] (int index)
    {
        assert(index >= 0 && index < theSize);
        return objects[index];
    }

    //Another operator overload for []?
    const T &operator[] (int index) const
    {
        assert(index >= 0 && index < theSize);
        return objects[index];
    }

    //Resizes Vector
    void resize(int newSize)
    {
        if(newSize > theCapacity)
        {
            reserve(newSize * 2);
        }
        theSize = newSize;
    }

    //Reserves memory for Vector
    void reserve(int newCapacity)
    {
        if(newCapacity < theSize)
        {
            return;
        }
        T* newArray = new T[newCapacity];
        for (int k = 0; k < theSize; ++k)
        {
            newArray[k] = std::move(objects[k]);
        }
        theCapacity = newCapacity;
        std::swap(objects, newArray);
        delete [] newArray;
    }

    //Push_back function
    void push_back(const T &x)
    {
        if(theSize == theCapacity)
        {
            reserve(2 * theCapacity + 1);
        }
        objects[theSize++] = x;
    }

    //Push_back using rvalues
    void push_back(T &&x)
    {
        if(theSize == theCapacity)
        {
            reserve(2 * theCapacity + 1);
        }
        objects[theSize++] = std::move(x);
    }

    //Pop_back function
    void pop_back()
    {
        assert(!empty());
        --theSize;
    }

    //Return last element in Vector
    const T &back() const
    {
        assert(!empty());
        return objects[theSize-1];
    }

    //Return first element in Vector
    const T &front() const
    {
        assert(!empty());
        return objects[0];
    }

    //Erase function for Homework 1
    void erase(int k)
    {
        if(k == theSize)
        {
            pop_back();
            return;
        }
        objects[k] = objects[k+1];
        erase(k+1);
    }

    //Insert function for Homework 1
    void insert(int k, T x)
    {
        if (k == theSize + 1)
        {
            push_back(x);
            return;
        }
        push_back(back());
        for (int i = theSize-1; i > k; --i)
        {
            objects[i] = objects[i-1];
        }
        objects[k] = x;
    }
};

#endif
