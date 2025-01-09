#include <iostream>
#include "node.h"
#include "slist.h"
using namespace std;

int main() {

    char answer[100];
    slist mylist;
    char trash[100];
    while (true) {
	    cout << "What would you like to do? (ADD/PRINT/DELETE/QUIT/AVERAGE): " << endl;
	    cout << "Hint: Average requires you to have existing student data!" << endl;
	    cin.getline(answer, 100);
	    if (strcasecmp(answer, "ADD") == 0) {
	        cout << "Please enter: (firstname) (lastname) studentid) (GPA)" << endl;
	        char fname[100], lname[100]; int id; float gpa;
	        cin >> fname >> lname >> id >> gpa;
	        cin.getline(trash, 100); //To remove any lingering input
	        cout << "Name: " << fname << " " << lname << endl << "ID: " << id << " GPA: " << gpa << endl;
	        Student* myStudent = new Student(fname, lname, id, gpa);
	        mylist.Add(myStudent);
	    }
	    else if (strcasecmp(answer, "PRINT") == 0) {
	        //mylist.Print();
	        //Use PRINT function from llist.h to print all stored data
	        //If there is no data, tell the user this
	    }
	    else if (strcasecmp(answer, "DELETE") == 0) {
	        cout << "Please enter a student id to delete: ";
	        int id;
	        cin >> id;
	        cin.getline(trash, 100);
	        //mylist.Delete(id);
	        //Prompt user for student id and remove that specific node from the list, make sure the links are still the same
	        //Make sure you have a destructor to remove unused memory if "new" is used
	    }
	    else if (strcasecmp(answer, "AVERAGE") == 0) {

	        //Average the GPA for all stored users, print up to 2 decimal places
	    }
	    else if (strcasecmp(answer, "QUIT") == 0) {
	        //Delete anything that had allocated memory
	        return 0;
	    }
	    else {
	        cout << "This is invalid." << endl;
	    }
        }

    return 0;
}
