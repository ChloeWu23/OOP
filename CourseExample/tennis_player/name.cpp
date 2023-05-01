#include<iostream>
#include<csting>
#include"name.h"
using namespace std;

Name::Name(const char* fname, const char* lname){
	//more robust way
fname = new char[strlen(fname)+1];
strcpy(first,fname);
lname  = new char[strlen(lname)+1];
strcpy(second,lname);
	
}

void Name::print(){
cout << fname << " " << lname << endl;
}
