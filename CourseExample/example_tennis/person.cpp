#include <string>
#include "date.h"
#include <iostream>
#include "name.h"
#include "person.h"

using namespace std;

Person::Person(const Name &n, const Date &d) : name(n), dob(d)//here call the copy constructor of the Name
{
  cout << "Person(" << this << ") constructor called!" << endl;
}

void Person::print_name() {
  name.print();
}

void Person::print_dob() {
  dob.print();
}

