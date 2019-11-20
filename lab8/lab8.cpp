//Phillip Pascual
//lab3.cpp
//5.22.18
//Main for CSE 330, Lab 3

#include <iostream>
#include "Map.h"
#include "Pair.h"
//#include "Set.h"
#include "Set_1.h"
#include <cstring>

using namespace std;

int main() {
    Map<string,int> basket;

    basket["apple"] = 5;
    basket["plum"] = 7;
    basket["banana"] = 6;
    basket["grape"] = 34;

    basket.printMap();

    cout << "Testing remove..." << endl << endl;

    string temp = "apple";

    basket.remove(temp);

    basket.printMap();

    cout << "Testing change value..." << endl << endl;

    basket["plum"] = 3;

    basket.printMap();

    return 0;
}
