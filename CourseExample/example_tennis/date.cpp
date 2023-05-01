#include <iostream>
#include <cstdio>
#include "date.h"

using namespace std;

Date::Date() :year(1970), month(1), day(1) {
  cout << "Date(" << this << ") default constructor activated" << endl;
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {
  cout << "Date(" << this << ") constructor activated" << endl;
}

Date::Date(const Date &source) : year(source.year), month(source.month), day (source.day) {
  cout << "Date(" << this << ") copy constructor activated" << endl;
}

void Date::print() {
  cout << "Date(" << this << ") print operation activated" << endl;
  char buffer[512];
  sprintf(buffer, "%02d/%02d/%04d", this->day, this->month, this->year);
  cout << buffer << endl;
}
