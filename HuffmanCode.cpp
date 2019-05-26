#include "HuffmanCode.h"
#include "Heap.h"
#include "HashTable.h"
#include <list>
#include <fstream>
#include <iostream>
#include <list>


using namespace std;



HuffmanCode::HuffmanCode(){
    hash = new HashTable(MAX_SIZE);
    ReadFile();
    hash->heapify(Priority);
}

void HuffmanCode::ReadFile(){
    cout << "Enter the file name you would like to encode: " << endl;
    ifstream fileName;
    string name;
    getline(cin,name);
    cout << endl;
    fileName.open(name);
    while (!fileName.is_open()){
        cout << name << " Failed to open." << endl << endl;
        cout << "Re-enter file name: " << endl;
        getline(cin,name);
        fileName.open(name);
    }
    char curr;
    while (fileName>>curr){
        hash->put(curr); //puts words in the file into a hash
    }
}


