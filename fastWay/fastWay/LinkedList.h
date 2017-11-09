#ifndef _LINKED_LIST_H__
#define _LINKED_LIST_H__

#include <string>

//지점 정보 
typedef struct _vertex {
    int vertex_num;
    std::string location_name; //const?
    std::string address;
}Vertex;

//linked list에 저장할 pair struct
typedef struct _pair {
    Vertex vertex; 
    unsigned int weigth; 
}Pair;


//Linked List에 저장할 node
typedef struct _node {
    Pair pair;
    struct _node *next; //다음 node를 가리키는 포인터
}Node;

//더미노드가 있는 linked list
typedef struct _linkedlist {
    int numOfNode;
    Node* head;
    Node* cur;
    Node* before;
}List;


/** ADT **/
void Linit(List* list); //list 초기화
void LInsert(List* list, Pair p);   //앞부분에 삽입

//조회 -> 성공하면 true, 실패하면 false 반환
//LFirst : Linked List의 첫번째 노드 조회
//LNext : LFirst 수행 후 다음 노드 조회
bool LFirst(List* list, Pair* p);    
bool LNext(List* list, Pair * p);   

Pair makePair(Vertex ver, int weight); //pair 만듬

#endif
