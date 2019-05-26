#include "HuffmanCode.h"
#include <list>
#include <fstream>
#include <iostream>
#include <list>
#include "heap.h"

using namespace std;

HuffmanCode::HuffmanCode(){
    hash = new HashTable(MAX_SIZE);
    ReadFile();
}


int HuffmanCode::computeHash(char c){
    int bucket = c;
    return bucket%MAX_SIZE;
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

void HuffmanCode::heapify(){
    int i = 1; //using le pendu's heap method, start at 1
    for (list<CharEntry>::iterator it = hash->begin(); it!= hash->end(); it++){
        CharEntry* entry = it;
        Priority.enqueue(entry);
    }

}

