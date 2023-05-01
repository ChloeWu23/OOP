/**
*class declaration of Person Class
**/
class Person{
private:
	Name name;
	Date dob; //here we include two class objects as private member objects (class attributes) in the Person Class.

public:
	Person(Name name,  Date dob); //constructor
  void print_name();
	void print_dob();
};
