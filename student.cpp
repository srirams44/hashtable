#include <iostream>
#include "student.h"
#include <cstring>
//Comment for second commit
using namespace std;

Student::Student(const char* argfname, const char* arglname, int argid, float arggpa) {
  fname = new char[strlen(argfname) + 1];
  lname = new char[strlen(arglname) + 1];
    strcpy(fname, argfname);
    strcpy(lname, arglname);
    id = argid;
    gpa = arggpa;
}

const char* Student::getFName() const {
  return fname;
}

const char* Student::getLName() const {
  return lname;
}

int Student::getID() const {
  return id;
}

float Student::getGPA() const {
  return gpa;
}


Student::~Student() {
  delete[] fname;
  delete[] lname;
  fname = lname = nullptr;
}
