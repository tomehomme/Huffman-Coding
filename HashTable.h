#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include <iostream>
#include "HuffmanCode.h"

using namespace std;

class HashTable {

 private:
	list<CharEntry> *hashTable;
	int size;

 public:
	HashTable(int);
	bool contains(const char &);
	// double getAverage(const char &);
	void put(const char &);
    int getSize()const;
 
 private:
	int computeHash(const char &);
};

#endif