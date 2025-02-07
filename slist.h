#ifndef SLIST_H
#define SLIST_H
#include "node.h"
//Quick Comment for commit

class slist {
public:
    slist();
    ~slist();
    Node* getHead();
    Node* getTail();
    void Add(Student* data);
    Node* AddHelper(Node* current, Node* newNode);
    void Print();
    void PrintHelper(Node* current);
    void Delete(int id);
    Node* DeleteHelper(Node* current, int id);
    bool checkList();
    void Average();
    void AverageHelper(Node* current, float& sum, int& count);
private:
    Node* head;
    Node* tail;
};

#endif
