//Phillip Pascual                                                               
//lab3main.cpp                                                                  
//4.17.2018                                                                     
//Main function and function declarations for Lab3                              
                                                                                
#include <cstdlib>                                                              
#include <vector>                                                               
#include <ctime>                                                                
#include <iostream>                                                             
                                                                                
#include "lab3.h"                                                               
                                                                                
using namespace std;                                                            
                                                                                
//Seeds RNG                                                                     
void randSeed()                                                                 
{                                                                               
    int seed = static_cast<int>(time(0));                                       
    srand(seed);                                                                
}                                                                               
                                                                                
//Returns a random integer between a and b                                      
int randInt(int a, int b)                                                       
{                                                                               
    return a + rand() % (b - a + 1);                                            
}                                                                               
                                                                                
//Fills vector with size k with random integers between from and upTo           
void randomVector(int k, int from, int upTo, vector<int> &v)                    
{                                                                               
    int rnum;                                                                   
    int r33;                                                                    
    for (int i = 1; i <= k; ++i)                                                
    {                                                                           
        rnum = randInt(from,upTo);                                              
        r33 = randInt(1,4);                                                     
        if (r33 == 3)                                                           
        {                                                                       
            v.push_back(-rnum);                                                 
        }                                                                       
        else                                                                    
        {                                                                       
            v.push_back(rnum);                                                  
        }                                                                       
    }                                                                           
    return;                                                                     
}                                                                               

int maxSubseqSumCube(const vector<int> &vec, int &ops)                          
{                                                                               
    int maxSum = 0;                                                             
    ops = 0;                                                                    
    for (int i = 0; i < vec.size(); ++i)                                        
    {                                                                           
        for (int j = 0; j < vec.size(); ++j)                                    
        {                                                                       
            int thisSum = 0;                                                    
            for (int k = i; k <= j; ++k)                                        
            {                                                                   
                thisSum += vec[k];                                              
                ops++;                                                          
            }                                                                   
            if (thisSum > maxSum)                                               
            {                                                                   
                maxSum = thisSum;                                               
            }                                                                   
        }                                                                       
    }                                                                           
    return maxSum;                                                              
}                                                                               
                                                                                
int maxSubseqSumQuad(const vector<int> &vec, int &ops)                          
{                                                                               
    int maxSum = 0;                                                             
    ops = 0;                                                                    
    for (int i = 0; i < vec.size(); ++i)                                        
    {                                                                           
        int thisSum = 0;                                                        
        for (int j = i; j < vec.size(); ++j)                                    
        {                                                                       
            thisSum += vec[j];                                                  
            ops++;                                                              
            if (thisSum > maxSum)                                               
            {                                                                   
                maxSum = thisSum;                                               
            }                                                                   
        }                                                                       
    }                                                                           
    return maxSum;                                                              
}

int maxSubseqSumLin(const vector<int> &vec, int &ops)
{
    int maxSum = 0;
    int thisSum = 0;
    ops = 0;

    for (int i = 0; i < vec.size(); ++i)
    {
        thisSum += vec[i];
        ops++;
        if (thisSum > maxSum)
        {
            maxSum = thisSum;
        }
        else if (thisSum < 0)
        {
            thisSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int noOps5 = 0;
    int noOps10 = 0;
    int noOps15 = 0;
    int noOps20 = 0;
    int noOps25 = 0;
    int noOps30 = 0;
    vector<int> test5,
                test10,
                test15,
                test20,
                test25,
                test30;

    //Fills test5 with 5 random ints and tests
    randomVector(5, -50, 50, test5);
    cout << "Test for vecsize = 5:" << endl;
    cout << "Max Sum:" << "  " << "# Ops:" << endl;
    cout << "--------" << "  " << "------" << endl;
    int maxSum5 = maxSubseqSumCube(test5,noOps5);
    cout << maxSum5 << "        " << noOps5 << "     " << "Cube" << endl;

    maxSum5 = maxSubseqSumQuad(test5,noOps5);
    cout << maxSum5 << "        " << noOps5 << "     " << "Quad" << endl;

    maxSum5 = maxSubseqSumLin(test5,noOps5);
    cout << maxSum5 << "        " << noOps5 << "      " << "Lin" << endl;

    //Fills test10 with 10 random ints and tests
    randomVector(10, -50, 50, test10);
    cout << "Test for vecsize = 10:" << endl;
    cout << "Max Sum:" << "  " << "# Ops:" << endl;
    cout << "--------" << "  " << "------" << endl;
    int maxSum10 = maxSubseqSumCube(test10,noOps10);
    cout << maxSum10 << "        " << noOps10 << "     " << "Cube" << endl;

    maxSum10 = maxSubseqSumQuad(test10,noOps10);
    cout << maxSum10 << "        " << noOps10 << "      " << "Quad" << endl;

    maxSum10 = maxSubseqSumLin(test10,noOps10);
    cout << maxSum10 << "        " << noOps10 << "      " << "Lin" << endl;

    //Fills test15 with 15 random ints and tests
    randomVector(15, -50, 50, test15);
    cout << "Test for vecsize = 15:" << endl;
    cout << "Max Sum:" << "  " << "# Ops:" << endl;
    cout << "--------" << "  " << "------" << endl;
    int maxSum15 = maxSubseqSumCube(test15,noOps15);
    cout << maxSum15 << "        " << noOps15 << "     " << "Cube" << endl;

    maxSum15 = maxSubseqSumQuad(test15,noOps15);
    cout << maxSum15 << "        " << noOps15 << "     " << "Quad" << endl;

    maxSum15 = maxSubseqSumLin(test15,noOps15);
    cout << maxSum15 << "        " << noOps15 << "      " << "Lin" << endl;

    //Fills test20 with 20 random ints and tests
    randomVector(20, -50, 50, test20);
    cout << "Test for vecsize = 20:" << endl;
    cout << "Max Sum:" << "  " << "# Ops:" << endl;
    cout << "--------" << "  " << "------" << endl;
    int maxSum20 = maxSubseqSumCube(test20,noOps20);
    cout << maxSum20 << "        " << noOps20 << "    " << "Cube" << endl;

    maxSum20 = maxSubseqSumQuad(test20,noOps20);
    cout << maxSum20 << "        " << noOps20 << "     " << "Quad" << endl;

    maxSum20 = maxSubseqSumLin(test20,noOps20);
    cout << maxSum20 << "        " << noOps20 << "      " << "Lin" << endl;

    //Fills test25 with 25 random ints and tests
    randomVector(25, -50, 50, test25);
    cout << "Test for vecsize = 25:" << endl;
    cout << "Max Sum:" << "  " << "# Ops:" << endl;
    cout << "--------" << "  " << "------" << endl;
    int maxSum25 = maxSubseqSumCube(test25,noOps25);
    cout << maxSum25 << "        " << noOps25 << "    " << "Cube" << endl;

    maxSum25 = maxSubseqSumQuad(test25,noOps25);
    cout << maxSum25 << "        " << noOps25 << "     " << "Quad" << endl;

    maxSum25 = maxSubseqSumLin(test25,noOps25);
    cout << maxSum25 << "        " << noOps25 << "      " << "Lin" << endl;

    //Fills test30 with 30 random ints and tests
    randomVector(30, -50, 50, test30);
    cout << "Test for vecsize = 30:" << endl;
    cout << "Max Sum:" << "  " << "# Ops:" << endl;
    cout << "--------" << "  " << "------" << endl;
    int maxSum30 = maxSubseqSumCube(test30,noOps30);
    cout << maxSum30 << "        " << noOps30 << "    " << "Cube" << endl;

    maxSum30 = maxSubseqSumQuad(test30,noOps30);
    cout << maxSum30 << "        " << noOps30 << "     " << "Quad" << endl;

    maxSum30 = maxSubseqSumLin(test30,noOps30);
    cout << maxSum30 << "        " << noOps30 << "      " << "Lin" << endl;

    return 0;
}
---------------------
//Phillip Pascual
//lab3.h
//4.17.2018
//Header file for Lab3

#ifndef LAB3_H
#define LAB3_H

#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

void randSeed(); //Seeds RNG
int randInt(int a, int b); //Returns a random integer between a and b

//Fills vector of size k with random integers
void randomVector(int k, int from, int upTo, vector<int> &v);

int maxSubseqSumCube(const vector<int> &vec, int &ops);
int maxSubseqSumQuad(const vector<int> &vec, int &ops);
int maxSubseqSumLin(const vector<int> &vec, int &ops);

#endif
