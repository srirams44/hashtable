#include "slist.h"

slist::slist() {
  head = NULL;
  tail = NULL;
  }

  void slist::Add(Student* data) {
    Node* newNode = new Node(data); //Create a new node with the data passed in 

    if (!head) {
      head = tail = newNode;
      return;
    }

    head = AddRecursive(head, newNode);
    //Create a new entry for each student, will prompt for a first name, last name, student id and GPA.
    //All data should be thrown into a node and put into the linked list. 
    //Sort by student id, this is most easily done by looking for a student id bigger then the id passed in, then placing it there.
}

Node* slist::AddRecursive(Node* current, Node* newNode) { 
  //Base case, when we reach an id bigger then current, or reach the end of the list
  if (!current || newNode->getStudent()->getID() < current->getStudent()->getID()) {
    newNode->setNext(current);
    if (!current) tail = newNode;
    return newNode;
  }
  current->setNext (AddRecursive(current->getNext(), newNode));
  return current;

} 


/*

   void slist::Print() {
    if (head == NULL) {
        cout << "The list is empty\n";
        return;
        }
        } 


   void slist::Delete(int id) {
     //Delete the node, but also set the previous nodes link to the next nodes link.
     } */

Node* slist::getHead() {
    return head;
}

Node* slist::getTail() {
    return tail;
}



