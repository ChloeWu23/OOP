/* class example:
   Employees are given a desk, and share offices. Bosses are employees, but they are also given PCs. On their first day at work, Bosses turn their PCs on; when they are fired they switch their PC off.
 */

#include <iostream>
using namespace std;
class Desk{
public:
  Desk() { cout << "Desk constructor \n"; }
  ~Desk() { cout << "Desk destrucotr \n";}
};

class Office{
public:
  Office() { cout << "Office constructor \n"; }
  ~Office() { cout << "Office destrucotr \n";}
};

class PC{
public:
  PC() { cout << "PC constructor \n"; }
  ~PC() { cout << "PC destrucotr \n";}
  void turn_on() { cout << "PC turned on \n";}
  void turn_off() { cout << "PC turned off\n ";}
};

class Employee{
private:
  Desk mydesk;
  Office *my_office; //office is shared aggregation
public:
  Employee(Office* o) : my_office(o) {
    cout << " Employee constructor \n"; }
  ~Employee() { cout << "Employee destructor\n"; }
};

class Boss : public Employee {
  PC my_PC;
public: 
  Boss(Office *o) : Employee(o) {
    my_PC.turn_on();
    cout << " Boss constructor\n";}
  //NOte that when Boss constructor called it has to call its parent constructor first which asks for one argument of Office* o
  ~Boss(){
    my_PC.turn_off();
    cout << "Boss destructor\n ";
}
};

int main () {
Office* office;
 office = new Office();
 Employee* employee = new Employee(office);
delete employee;
 Boss* boss = new Boss(office);
 delete boss;
delete office;
 return 0;
 
}
