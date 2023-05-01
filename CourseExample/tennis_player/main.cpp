#include<iostream>
#include"date.h"
#include"name.h"

using namespace std;

int main(){
/**
	Date then;//call default constructor
	then.print(); //call function in Date and then is the receiver so flow of control goes to Date::print() and then. give the address/pointer of Class Object then, so the address of then should be same with address of stack frame of the default constractor.
 cout << " &then = " << &then;
  Date now(2022, 10, 28); //call constructor
  Date now = Date(2022, 10,28); //here another way of involking constructor
  
  Date today(now); //call copy constructor
	now.print();
  cout << " &now = " << &now;
	Date tomorrow = Date(2022, 10, 29);
**/
  Person player = Person(Name("Lisa", "Bowls"), Date(1985,1,7)};
	Person umpire = Person(Name("Dave","Pink"), Date(1985,1,7));

	player.print_name();
	player.print_dob();
	
	umpire.print_name();
	umpire.print_dob();
/** Note That:
* player.name.print(); //Illegal 
*since we get private attributes of Class Person, which is an object name, Hovewer since Class Name is private in Person CLass, we can only use it member function inside of defination of decalaration of Class Person, can not use it in the main function.
**/
  return 0;
}
