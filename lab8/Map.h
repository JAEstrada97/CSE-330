//Phillip Pascual
//Map.h
//5.22.18
//Header file for class Map

#ifndef MAP_H_
#define MAP_H_

#include "Pair.h"
//#include "Set.h"
#include "Set_1.h"
#include <iostream>
#include <string>

using namespace std;

template <typename K, typename V>
class Map {
    private:
        Set<Pair<K,V> > themap;
    public:
        Map() {}

        void printMap() const {
            typename Set<Pair<K,V> >::iterator itr = themap.begin();
            for (; itr != themap.end(); ++itr) {
                cout << (*itr).first << ":" << (*itr).second << endl;
            }
            return;
        }
        
        V & operator [] (K index) {
            typename Set<Pair<K,V> >::iterator here;
            Pair<K,V> probe(index, V());
            here = themap.insert(probe);
            return (*here).second;
        }
        
        //Tried to make an assignment operator overload here
        V & operator = (V & value) {
            themap.first = value;
            return *this;
        }

        void remove(K & key) {
            Pair<K,V> probe;
            probe.first = key;
            themap.remove(probe);
            return;
        }
};

#endif
