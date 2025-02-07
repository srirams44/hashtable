#include <iostream>
#include "node.h"
#include "slist.h"
using namespace std;
//Quick Comment for commit
int main() {

    char answer[100];
    slist mylist; //creating a list to use
    char trash[100];
    while (true) {
	    cout << "What would you like to do? (ADD/PRINT/DELETE/QUIT/AVERAGE): ";
	    cin.getline(answer, 100);
	    if (strcasecmp(answer, "ADD") == 0) {
	        cout << "Please enter: (firstname) (lastname) studentid) (GPA)" << endl;
	        char fname[100], lname[100]; int id; float gpa;
	        cin >> fname >> lname >> id >> gpa;
	        cin.getline(trash, 100); //To remove any lingering input
	        Student* myStudent = new Student(fname, lname, id, gpa); //constructors a new student with the information
	        mylist.Add(myStudent); //Uses the add function
	    }
	    else if (strcasecmp(answer, "PRINT") == 0) {
	        mylist.Print(); //Use the print function
	    }
	    else if (strcasecmp(answer, "DELETE") == 0) {
	        int id;
	    	if (mylist.checkList() == false) { //If there's nothing in the list, use the checklist function
	    		cout << "This list is empty." << endl; //If the checklist returns false, it means the list is empty, so no point in getting an input
	    	}
	    	else {
	    		cout << "Please enter a student id to delete: ";
	    		cin >> id;
	    		cin.getline(trash, 100);
	    		mylist.Delete(id); //Run the delete function
	    	}
	    }
	    else if (strcasecmp(answer, "AVERAGE") == 0) {
	    	mylist.Average(); //Run the average function
	    }
	    else if (strcasecmp(answer, "QUIT") == 0) {
	        cout << "Thank you." << endl;
	        return 0;
	    }
	    else {
	        cout << "This is invalid." << endl;
	    }
        }
}
