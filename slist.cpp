#include "slist.h"

slist::slist() {
  head = NULL;
  tail = NULL;
  }

  void slist::Add(Student* data) {
}




  void slist::Print() {
    if (head == NULL) {
        cout << "The list is empty\n";
        return;
        }
        }


   void slist::Delete(int id) {
     //Delete the node, but also set the previous nodes link to the next nodes link.
     }

Node* slist::getHead() {
    return head;
}

Node* slist::getTail() {
    return tail;
}



