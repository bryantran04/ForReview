#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


class hashTable {
private:
    unsigned long hash(string & s);
    vector<list<string> > *bucketVector;
    bool checkprime(unsigned int p);
    int getNextPrime (unsigned int n);
    double loadFactor;
    int tableSize;

public:
    hashTable(int size);
    ~hashTable();
    void insert(string & s);
    bool contains(string & s);



};



#endif
