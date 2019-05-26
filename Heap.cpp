#include "Heap.h"
#include "HuffmanCode.h"
#include "HashTable.h"

#include <iostream>
using namespace std;

Heap::Heap(){
    numItems = 0;
}


void Heap::enqueue (CharEntry* job){ //inserts to the back and then bubbles up
    if (numItems != MAX_HEAP_SIZE){
        arr[numItems+1] = job;
        numItems++;
        bubbleUp(numItems); //index of the new job is numItems
    }
}

 CharEntry* Heap::highest ( ){
    return arr[1];
 }
 
bool Heap::isEmpty() const{
    return numItems==0;
}

void Heap::bubbleUp(int currIndex){
    if (currIndex == 0 || arr[currIndex]->numAppearances<=arr[currIndex/2]->numAppearances){
        return;
    }
    swap(arr[currIndex],arr[currIndex/2]); //swap the parent and the child if child>=parent
    bubbleUp(currIndex/2); //recursively bubble up with parent's index
}

void Heap::print() { //prints the heap
    if (!isEmpty()){
        for (int i = 1; i<numItems+1; i++){
         cout << "Priority: " << arr[i]->numAppearances << endl;
        }
    }
   
}

 void Heap::dequeue ( ){
     if (!isEmpty()){
         swap(arr[1],arr[numItems+1]);
         numItems--;
         trickleDown(1); //trickle down starting at root 
     }
 }

 void Heap::trickleDown(int currIndex){
     if (currIndex*2+1 >= numItems+1){
        return;
    }
    if(arr[currIndex]->numAppearances >= arr[currIndex*2]->numAppearances && arr[currIndex]->numAppearances >= arr[currIndex*2+1]->numAppearances){ //if it is greater than both children, stop
        return;
    }
    if (arr[currIndex*2]->numAppearances >= arr[currIndex*2+1]->numAppearances){ //go with the bigger path
        swap(arr[currIndex],arr[currIndex*2]);
        trickleDown(currIndex*2); //recursive with next child's index
    }
    else{
        swap(arr[currIndex],arr[currIndex*2+1]); //swap the parent and the child if parent>child
        trickleDown(currIndex*2+1); //recursively trickle down with child's index
    }
 }


