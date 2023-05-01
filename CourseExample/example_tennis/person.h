class Person {
private:
  Name name;
  Date dob;  

public:
  Person(const Name &n, const Date &d);

  void print_name();

  void print_dob();
};
