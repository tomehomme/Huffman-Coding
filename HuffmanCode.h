#ifndef HUFFMANCODE_H
#define HUFFMANCODE_H
#include <list>
#include <fstream>
#include <ostream>
#include "Heap.h"
#include "HashTable.h"

using namespace std;

const int MAX_SIZE = 200;


struct CharEntry{
    char chara;
    int numAppearances;
    CharEntry(): chara(' '), numAppearances(0){};
    CharEntry(const char& a): chara(a), numAppearances(0) {};
    void incApp(){numAppearances++;}
    char getCharacter(){return chara;}
};


class HuffmanCode{
    private:
        HashTable* hash; //hash of chars and its appearances
        Heap Priority; //priority queue to order which has the highest priority
        void ReadFile(); //reads the file and puts every char in its own bucket
        void heapify(); //heapifies the hash
        void Encode();
        int computeHash(char c);
    public:
        HuffmanCode();
        ofstream outputEncoding (const string& ); //outputs the encoded file


};


#endif