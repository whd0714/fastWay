#include <iostream>
#include "stdafx.h"
#include "Heap.h"

using namespace std;


int GetParentIDX(int idx); //find index of Parent 
int GetLChildIDX(int idx); //find index of left child
int GetRChildIDX(int idx); //find index of right child

//A function that returns a higher-priority node among child nodes
int GetHiPriChildIDX(Heap* ph, int idx);

void HInit(Heap* ph, PriorityComp pc) {
    ph->comp = pc;
    ph->numOfData = 0;
}

bool HIsEmpty(Heap* ph) {
    if (ph->numOfData == 0)
        return true;
    return false;
}

void HInsert(Heap* ph, Pair p) {
    int idx = ph->numOfData + 1;
    while (idx != 1) {
        
    }


}
Pair HDelete(Heap* ph);                 //Delete the first Pair in the Heap


int GetParentIDX(int idx) {
    return idx / 2;
}
int GetLChildIDX(int idx) {
    return idx * 2;
}
int GetRChildIDX(int idx) {
    return idx * 2 + 1;
}

int GetHiPriChildIDX(Heap* p, int idx) {

    //if there is no child node
    if (GetLChildIDX(idx) > p->numOfData)
        return 0;

    //if there is one child node
    if (GetLChildIDX(idx) == p->numOfData)
        return GetLChildIDX(idx);
   
    else {  //if there are two child nodes
        if (p->comp(p->heapArr[GetLChildIDX(idx)], p->heapArr[GetRChildIDX(idx)]))
            return GetLChildIDX(idx);
        else
            return GetRChildIDX(idx);

    }
}


void HInsert(Heap* p, Pair pair) {
    int idx = p->numOfData + 1; //Start comparing from last.
    while (idx != 1) { // if idx == 1,idx is root node.

        //if the child's priorities are higer
        if (p->comp(pair, p->heapArr[GetParentIDX(idx)]) > 0) {
            p->heapArr[idx] = p->heapArr[GetParentIDX(idx)];    // change the value of parents and the value of children 
            idx = GetParentIDX(idx);    //change idx
        }
        else
            break;
    }

    p->numOfData++;
    p->heapArr[idx] = pair; //insert the pair into the correct position

}

Pair HDelete(Heap *h) {

    int parentIdx = 1;
    int childIdx;

    Pair returndata = h->heapArr[1];
    //After moving last node to root node, locate the correct position.
    Pair lastdata = h->heapArr[h->numOfData];

    while (childIdx = GetHiPriChildIDX(h, parentIdx)) {

        //if last data's priorities are higer
        if (h->comp(lastdata, h->heapArr[childIdx]) >= 0) {
            break;
        }
        else {
            h->heapArr[parentIdx] = h->heapArr[childIdx];   //change value
            parentIdx = childIdx;
        }
    }
    h->heapArr[parentIdx] = lastdata;
    h->numOfData--;
    return returndata;

}