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
