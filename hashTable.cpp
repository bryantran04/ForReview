#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include "hashTable.h"

using namespace std;


hashTable::hashTable(int size){
	bucketVector = new vector<list<string> > ;
	loadFactor = .5;

	 tableSize = size / loadFactor;

	if (!checkprime(tableSize)){
		tableSize = getNextPrime(tableSize);
	}

	for(int i =0; i <tableSize; i++){
		list<string> bucket;
		bucketVector->push_back(bucket);
	}


}

hashTable::~hashTable(){
	while (!bucketVector->empty()){
		while (!bucketVector->end()->empty()){
			bucketVector->end()->end()->clear();
		}
		bucketVector->end()->clear();
	}

	delete bucketVector;
	bucketVector = NULL;
}


unsigned long hashTable::hash(string &s){
	unsigned long sum= 0;
	for (int i =0; i <s.size(); i++){
		sum *= 37;
		sum += s[i];
	}
	return (sum % tableSize);
}



void hashTable::insert(string & s){

	if (!contains(s)){
		
		bucketVector->at(hash(s)).push_back(s);
	}


}

bool hashTable::contains(string &s){
	

	bool found = find(bucketVector->at(hash(s)).begin() , bucketVector->at(hash(s)).end() , s) != bucketVector->at(hash(s)).end();
	return found;
}


bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}