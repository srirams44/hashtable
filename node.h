#ifndef NODE_H //header guard 
#define NODE_H
#include "student.h"
#include <iostream>
//Comment for second commit
using namespace std;

class Node {
public:
    Node(Student* newStudent); //constructors
    ~Node(); //destructor
    void setStudent(Student* newStudent); 
    Student* getStudent();
    void setNext(Node* newNext);
    Node* getNext();
private:
    Student* student;   //pointer to student object
    Node* next;     //pointer to next node in list
};

#endif
