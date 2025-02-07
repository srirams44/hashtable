#include "node.h"
#include <iostream>
//Comment for second commit
using namespace std; 

//Node Constructor 
Node::Node(Student* newStudent) {
    student = newStudent;  
    next = nullptr; //Node is not pointing to another node
}


//Node Destructor 
Node::~Node() {
    delete student; //cleans up memory 
    next = nullptr;
}

//updates student stored in node. Assigns newstudent to student
void Node::setStudent(Student* newStudent) {
    student = newStudent;
}

//get Student stored in Node
Student* Node::getStudent() {
    return student;  
}

//Allows you to update node
void Node::setNext(Node* newNext) {
    next = newNext;  
}
//Allows you to see the next Node 
Node* Node::getNext() {
    return next;  
}
