#ifndef SLIST_H
#define SLIST_H
#include "node.h"


class slist {

public:
    slist();
    Node* getHead();
    Node* getTail();
    void Add(Student* data);
    Node* AddRecursive(Node* current, Node* newNode);
    void Print();
    void Delete(int id);


private:
    Node* head;
    Node* tail;

};

#endif
