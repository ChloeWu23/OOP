#include<iostream>
#include<csting>
#include"date.h"
#include"name.h"
#include"person.h"
using namespace std;
x
Person :: Person(Name name, Date dob) :
name(name), dob(dob){} 
//constructor to initialize name and dob for the Person's object
void Person :: print_name(){
		name.print(); //you can include member function of Class Name since we have included it in the Class Person
	}
	void Person :: print_dob(){
		dob.print();
	}
};
