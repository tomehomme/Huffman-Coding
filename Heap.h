#ifndef __HEAP_H
#define __HEAP_H

#include "HuffmanCode.h"
#include "HashTable.h"

#include <list>
#include <fstream>
#include <iostream>

const int MAX_HEAP_SIZE = 60;

struct CharEntry{
    char chara;
    int numAppearances;
    CharEntry(): chara(' '), numAppearances(0){};
    CharEntry(const char& a): chara(a), numAppearances(0) {};
    void incApp(){numAppearances++;}
    char getCharacter(){return chara;}
};

class Heap {
private:
  CharEntry* arr[MAX_HEAP_SIZE];      // Notice this is an array of PrintJob pointers
  int numItems;  //current number of items in heap

public:
  /*Initializes an empty heap.*/
  Heap();
  void heapify(const HashTable* hash);

  /*Inserts a PrintJob to the heap without
  violating max-heap properties.*/
  void enqueue ( CharEntry* );

  /*Removes the node with highest priority from the heap. 
  Follow the algorithm on priority-queue slides. */
  void dequeue ( );

  /*Returns the node with highest priority.*/
  CharEntry* highest ( );

  /*Prints the PrintJob with highest priority in the following format:
  Priority: priority, Job Number: jobNum, Number of Pages: numPages
  (Add a new line at the end.)*/
  void print ( );

private:
  bool isEmpty() const; //returns if there is no print queue
  /*This function is called by dequeue function
  to move the new root down the heap to the 
  appropriate location.*/
  void trickleDown(int);

  //You can include additional private helper functions here
  void bubbleUp(int); //called by enqueue to bring the new job to the right position

  
  
    

};
#endif