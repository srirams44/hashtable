#include "slist.h"
#include <iomanip>

slist::slist() {
  head = nullptr;
  tail = nullptr;
  cout << "Constructor: " << this << endl;
}
slist::~slist() {
  Node* current = head; //Start at the head, while current is not nullptr, save the current node, move to the next node and delete the temp variable
  while (current) {
    Node* temp = current;
    current = current->getNext();
    delete temp;
  }
}

Node* slist::getHead() {
    return head;
}

Node* slist::getTail() {
    return tail;
}

void slist::Add(Student* data) {
    Node* newNode = new Node(data); //Create a new node with the data passed in
    //If the list is empty, make the new node the head and tail
    if (!head) {
      head = tail = newNode;
      return;
    }
    head = AddHelper(head, newNode); //Recursive helper function to sort the nodes
}
Node* slist::AddHelper(Node* current, Node* newNode) {
  //Break case, when we reach an id bigger then current, or reach the end of the list
  if (!current || newNode->getStudent()->getID() < current->getStudent()->getID()) {
    newNode->setNext(current);
    if (!current) tail = newNode;
    return newNode;
  }
  current->setNext (AddHelper(current->getNext(), newNode));
  return current;
}

   void slist::Print() {
  if (!head) { //If there's no head, the list is empty
    cout << "This list is empty." << endl;
    return;
  }
  PrintHelper(head);
}

void slist::PrintHelper(Node* current) {
  if (!current) { //Break case, reached the end of the list
    return;
  }
  Student* student = current->getStudent(); //Print current student's details
  cout << student->getFName() << " " << student->getLName() << ", " << student->getID() << fixed << setprecision(2) << ", " << student->getGPA() << endl;
  PrintHelper(current->getNext());
}

bool slist::checkList() {
  if (!head) { //No head, list is empty
    return false;
  }
  return true;
}

void slist::Delete(int id) {
  if (!head) { //If it's empty, you can't delete anything!
    cout << "This list is empty. Nothing to delete." << endl;
    return;
  }

  head = DeleteHelper(head, id); //Helper function

  //If there's no head after the deletion, update the tail
  if (!head) {
    tail = nullptr;
  }
}

Node* slist::DeleteHelper(Node* current, int id) {
  if (!current) { //Break case, youve reached the end of the list and the id is not found
    cout << "Student with ID: " << id << " not found." << endl;
    return nullptr;
  }
  if (current->getStudent()->getID() == id) { //If you found it, delete
    Node* temp = current->getNext();
    delete current;
    return temp;
  }
  //Update the next pointer of the current node
  current->setNext(DeleteHelper(current->getNext(), id));
  //Update tail if the current node becomes the last one
  if (!current->getNext()) {
    tail = current;
  }
  return current; //Return the current node
}

void slist::Average() {
  if (!head) { //List doesn't exist
    cout << "This list is empty. Nothing to average." << endl;
  }

  float sum = 0.0;
  int count = 0;

  AverageHelper(head, sum, count);

  if (count > 0) { //If there are gpas to be averaged, average them
    float average = sum / count;
    cout << "The average GPA is: " << fixed << setprecision(2) << average << endl;
  }
}

void slist::AverageHelper(Node* current, float& sum, int& count) { //pass by reference
  if (!current) { //Break case, if there are no more nodes, that's it
    return;
  }

  sum += current->getStudent()->getGPA();
  count++;

  AverageHelper(current->getNext(), sum, count);
}