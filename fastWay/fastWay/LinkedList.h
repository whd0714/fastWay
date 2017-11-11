#ifndef _LINKED_LIST_H__
#define _LINKED_LIST_H__

#include <string>

// vertex information
typedef struct _vertex {
    int vertex_num;
    std::string location_name; //const?
    std::string address;
}Vertex;


typedef struct _pair {
    Vertex vertex; 
    unsigned int weigth; 
}Pair;


//node will be stored in LinkedList
typedef struct _node {
    Pair pair;
    struct _node *next; 
}Node;

//LinkedList has dummy node
typedef struct _linkedlist {
    int numOfNode;
    Node* head;
    Node* cur;
    Node* before;
}List;


/** ADT **/
void Linit(List* list); //list initialize
void LInsert(List* list, Pair p);   //insert node at the front 

//returns true if successful, false if failed.
//LFirst : Search the first node of List
//LNext : Search next node of List
bool LFirst(List* list, Pair* p);    
bool LNext(List* list, Pair * p);   

Pair makePair(Vertex ver, int weight); //making new pair

#endif
