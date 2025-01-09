#ifndef STUDENT_H
#define STUDENT_H
#include <cstring>

class Student {
    public:
        Student(const char* fname, const char* lname,  int id, float gpa); //Student Constructor
        ~Student(); //Student destructor
    private: //Everything a student might have, name, id, gpa.
        char* fname;
	    char* lname;
        int id;
        float gpa;

};



#endif
