#include<iostream>
#include<cstdio>
#include"date.h"

using namespace std;

/**
Giving definition of member functions in Class Date
**/
//default constructor definition
Date::Date() :year(1970),month(1), day(1){
cout << "Date (" << this << ") default constructor activated" << endl;
/**
*note:cout<< this gives the address of the current stack frame
*"this" is a special key words(like int) in C++ which gives current adress 
**/

}

//constructor definition
Date::Date(int year, int month, int day):
		year(year), month(month), day(day){
	cout << "Date (" << this << ") constructor activated" << endl;
} 
/*Note that it comes with Class name + double colon + Constructor Name+ parameter list (+Initialize colon) {...}
*/

/**
copy constructor definition
**/
Date::Date(const Date &source) :year(source.year), month(source.month), day(source.day){
		cout << "Date (" << this << ") copy constructor activated" << endl;
}
		
//print function definition:
void Date::print(){
/**
	cout << ((day<10)? "0": "") << day << "/"
			 << ((month<10)? "0": "")
			 << year << endl;
**/
/**
*This is a more concise way
**/
char buffer[512];
sprintf(buffer, "%02d/%02d/%04d", day, month, year); //structured printing to buffer 
/** use "this" 
sprintf(buffer, "%02d/%02d/%04d", this -> day, this -> month, this ->year);
**/
//sprintf is in <cstdio>

	}