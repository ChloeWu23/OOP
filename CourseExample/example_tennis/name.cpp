#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include "name.h"

using namespace std;


Name::Name(const char *first, const char *second) {
  cout << "Name(" << this << ") being constructed! (" << first << ", " << second << ")" << endl;
  fname = new char[strlen(first) + 1];
  assert(fname);
  strcpy(fname, first);
  lname = new char[strlen(second) + 1];
  assert(lname);
  strcpy(lname, second);
}

Name::Name(const Name &source) {
  cout << "Name(" << this << ") copy constructor called!" << endl;
  fname = new char[strlen(source.fname) + 1];
  assert(fname);
  strcpy(fname, source.fname);
  lname = new char[strlen(source.lname) + 1];
  assert(lname);
  strcpy(lname, source.lname);
}

Name::~Name() {
  cout << "Name(" << this << ") being destroyed!" << endl;
      delete [] fname;
      delete [] lname;
}

void Name::print() {
  cout << fname << " " << lname << endl;
}
