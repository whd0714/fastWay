/***
Heap for Priority Queue
***/
#ifndef _HEAP_H__
#define _HEAP_H__

#include "LinkedList.h"

#define HEAP_LEN 99

typedef int PriorityComp(Pair p1, Pair p2);

typedef struct _heap {
    PriorityComp* comp; //Function to compare priorities
    int numOfData;      //Num of Pairs in the Heap
    Pair heapArr[HEAP_LEN]; 
}Heap;

/**ADT**/
void HInit(Heap* ph, PriorityComp pc);  //Heap initialize
bool HIsEmpty(Heap* ph);                 //if Heap is empty, return true
                
void HInsert(Heap* ph, Pair p);         //Insert Pair into the Heap
Pair HDelete(Heap* ph);                 //Delete the first Pair in the Heap


#endif
