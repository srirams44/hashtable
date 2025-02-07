#include "hashtable.h"

//Constructor
hashTable::hashTable(int size) {
    tableSize = size;
    studentCount = 0;
    table = new Node*[tableSize];

    for (int i = 0; i < tableSize; ++i) {
        table[i] = nullptr;
    }
}

//Destructor
hashTable::~hashTable() {
    //Delete all the nodes in each linked list
    for (int i = 0; i < tableSize; ++i) {
        Node* current = table[i];
        while (current) {
            Node* next = current->getNext();
            delete current;
            current = next;
        }
    }
    delete[] table; //Free up the space for the table
}

int hashTable::hashFunction(int id) { //Hash function
    return id % tableSize;
}

void hashTable::Add(Student* student) {
    int index = hashFunction(student->getID());

    Node* newNode = new Node(student);
    newNode->setNext(table[index]); //Points to the head of the list
    table[index] = newNode; //New node is now the head

    studentCount++;

    Node* current = table[index]; //Checks if resizing is necessary
    int chainLength = 0;
    while (current) {
        chainLength++;
        current = current->getNext();
    }

    if (chainLength > 3) {
        Resize();
    }
}

