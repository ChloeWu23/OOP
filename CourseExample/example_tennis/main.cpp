#include<iostream>
#include "date.h"
#include "name.h"
#include "person.h"

using namespace std;

int main() {

  Name lisa("Lisa", "Bowls");
  Date lisabday(1985,1,7);
  
  Person player(lisa, lisabday); 
  Person umpire(Name("Dave", "Pink"), Date(1975, 5, 8));

  player.print_name();
  player.print_dob();

  umpire.print_name();
  umpire.print_dob();

  return 0;
}
