#include "node.h"
#include <iostream>
#include <cstring>

using namespace std; 

//Node Constructor 
Node::Node(Student* newStudent) {
    student = newStudent;  
    next = NULL;        //Node is not pointing to another node 
}


//Node Destructor 
Node::~Node() {
    delete student; //cleans up memory 
     next = NULL;  
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
