#include "hashtable.h"
using namespace std;


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

//Hash function
int hashTable::hashFunction(int id) {
    return id % tableSize;
}

//Add function
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

//Print function
void hashTable::Print(){
    if (studentCount == 0) {
        cout << "There are no students to print!" << endl;
        return;
    }
    for (int i = 0; i < tableSize; ++i) {
        Node* current = table[i];

        while (current != nullptr) { //While running through the hashtable, if the current node is not a nullptr, do this code
            Student* s = current->getStudent(); //Get the details associated with the student
            cout << "ID: " << s->getID() << ", First Name: " << s->getFName() << ", Last Name: "
            << s->getLName() << ", GPA: " << s->getGPA() << endl;
            current = current->getNext();
        }
    }
}

//Delete function
void hashTable::Delete(int id) {
    int index = hashFunction(id);
    Node* current = table[index];
    Node* prev = nullptr;

    while (current) {
        if (current->getStudent()->getID() == id) {
            if (prev) { //If not the first node, bypass this current node
                prev->setNext(current->getNext());
            }
            else { //If this is the first node in the chain, update the table index
                table[index] = current->getNext();
            }

            delete current; //Free the memory as well
            cout << "ID: " << id << " has been deleted." << endl;
            return;
        }

        prev = current; //Move previous forward
        current = current->getNext(); //Move current forward
    }
    //If you finish the loop without finding the student with given ID
    cout << "Student with ID: " << id << " not found." << endl;
}


//Rehash/Resize function
void hashTable::Resize() {
    int newSize = tableSize * 2; //Double the size
    Node** newTable = new Node*[newSize]; //Allocate a new table

    for (int i = 0; i < tableSize; ++i) {
        Node* current = table[i];
        while (current) {
            Student* student = current->getStudent();
            int newIndex = hashFunction(student->getID()) % newSize; // New hash index

            // Insert into new table
            Node* newNode = new Node(student);
            newNode->setNext(newTable[newIndex]);
            newTable[newIndex] = newNode;

            //Move into the next node
            Node* temp = current;
            current = current->getNext();
            delete temp; //Free up the memory
        }
    }

    //Delete the old table and re assign values
    delete[] table;
    table = newTable;
    tableSize = newSize;

    //Debugging line to check if it worked
    cout << "Resized hash table to " << tableSize << " slots." << endl;

    /* PSUEDOCODE:
     * 1. Allocate new table twice the size
     * 2. Initialize all slots in new table to nullptr
     * 3. Get each student from old table, recalculate hash index and stuff them into new table
     * 4. Cleanup - delete old notes, free memory for old table, and reassign table and tablesize
 */
}