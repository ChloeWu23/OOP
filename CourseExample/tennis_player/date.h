/**
Class Declaration of Class Date
**/
class Date{
private:
	int year;
	int month;
	int day;
public:
	Date( ); //default constructor
 	Date(int year, int month, int day); //only give declare of contract Date
  Date(const Date &source); //copy constructor
	void print();
};
