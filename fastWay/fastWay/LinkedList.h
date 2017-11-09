#ifndef _LINKED_LIST_H__
#define _LINKED_LIST_H__

#include <string>

//���� ���� 
typedef struct _vertex {
    int vertex_num;
    std::string location_name; //const?
    std::string address;
}Vertex;

//linked list�� ������ pair struct
typedef struct _pair {
    Vertex vertex; 
    unsigned int weigth; 
}Pair;


//Linked List�� ������ node
typedef struct _node {
    Pair pair;
    struct _node *next; //���� node�� ����Ű�� ������
}Node;

//���̳�尡 �ִ� linked list
typedef struct _linkedlist {
    int numOfNode;
    Node* head;
    Node* cur;
    Node* before;
}List;


/** ADT **/
void Linit(List* list); //list �ʱ�ȭ
void LInsert(List* list, Pair p);   //�պκп� ����

//��ȸ -> �����ϸ� true, �����ϸ� false ��ȯ
//LFirst : Linked List�� ù��° ��� ��ȸ
//LNext : LFirst ���� �� ���� ��� ��ȸ
bool LFirst(List* list, Pair* p);    
bool LNext(List* list, Pair * p);   

Pair makePair(Vertex ver, int weight); //pair ����

#endif
