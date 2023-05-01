class Date {
 private:
  int year, month, day;

 public:
  Date(); // default constructor
  Date(int y, int m, int d);
  Date(const Date &source); //copy constructor

  void print();
};
