#include <iostream>
#include "LinkedList.h"

void Linit(List* list) {
    Node* DMY = new Node; //���̳�� ����
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

// ù��° ��� Ž��
bool LFirst(List* list, Pair* p) {
    //List�� ����ִ� ��� 
    if (list->head->next == NULL)
        return false;   
    
    list->before = list->head;
    list->cur = list->head->next;

    *p = list->cur->pair;   //check
    return true;
    
}

bool LNext(List* list, Pair * p) {
    //���̻� ��ȸ�� ��尡 ���� ��
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
