//collaborated with Ajeet Kokatay and Ruth Navaratte
#include "HashTable.h"
#include "HuffmanCode.h"

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) {
	size = s;
    hashTable = new list<CharEntry>[size];
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const char &s) {
    return (s*19)%size;
}



/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const char &s) {
	 CharEntry newWord = CharEntry(s);
     int i = computeHash(s);
     if (!contains(s)){
       hashTable[i].push_front(CharEntry(s));
     }
     else{
         int bucket = computeHash(s);
         for (list<CharEntry>::iterator indx = hashTable[bucket].begin(); indx!= hashTable[bucket].end(); indx++){
                if (indx->getCharacter()==s){
                indx->incApp();
            }
            
        }
     }
}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

// double HashTable::getAverage(const char &s) {
//     int bucket = computeHash(s);
//     list<CharEntry> lis = hashTable[bucket];
//     for (list<CharEntry>::iterator it = lis.begin(); it!= lis.end(); it++){
//         if (it->getCharacter() == s){
//             return it->getAverage();
//         }
        
//     }
//      return 2.0;
// }

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(const char &s) {
    int bucket = computeHash(s);
    list<CharEntry> lis = hashTable[bucket];
    for (auto indx : lis){
        if (s==indx.getCharacter()){
            return true;
        }
        
    }
    return false;
}

int HashTable::getSize()const{
    return size;
}