#include <iostream>
#include "student.h"
#include <cstring>

using namespace std;

Student::Student(const char* argfname, const char* arglname, int argid, float arggpa) {
  fname = new char[strlen(argfname) + 1];
  lname = new char[strlen(arglname) + 1];
    strcpy(fname, argfname);
    strcpy(lname, arglname);
    id = argid;
    gpa = arggpa;
}

Student::~Student() {
  delete[] fname;
  delete[] lname;
  fname = lname = NULL;
}
