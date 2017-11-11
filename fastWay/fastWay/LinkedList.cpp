#include "stdafx.h"
#include <iostream>
#include "LinkedList.h"

using namespace std;

void LInit(List* list) {
    Node* DMY = new Node; //making dummy node
    list->head = DMY;
    list->head->next = NULL;
    DMY->next = NULL;
    list->numOfNode = 0;
}

void LInsert(List* list, Pair p) {
    Node* newNode = new Node;
    newNode->pair = p;  //check
    
    newNode->next = list->head->next;   
    list->head->next = newNode;

    list->numOfNode++;

}

//Search the first node of List
bool LFirst(List* list, Pair* p) {
    //If the list is empty
    if (list->head->next == NULL)
        return false;   
    
    list->before = list->head;
    list->cur = list->head->next;

    *p = list->cur->pair;   //check
    return true;
    
}

bool LNext(List* list, Pair * p) {
    //If the node to query does not exist
    if (list->cur->next == NULL)
        return false;

    list->before = list->cur;
    list->cur = list->cur->next;

    *p = list->cur->pair;   //check
    return true;

}

Pair makePair(Vertex ver, int weight) {
    Pair p;
    p.vertex = ver;
    p.weigth = weight;
    return p;
}
void showPair(Pair p) {

    cout << "location name : " << p.vertex.location_name << endl;
    cout << "Address : " << p.vertex.address << endl;
    cout << "weight : " << p.weigth << endl;

}