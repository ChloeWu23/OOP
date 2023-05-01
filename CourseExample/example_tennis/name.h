class Name {
 private:
  char *fname;
  char *lname;

  // if doing this in a modern c++ style we could also just have  
  // std::string fname, lname;

 public:
  Name(const char *first, const char *second); // : fname(first), lname(second){
  //  }

  Name(const Name &source);
  
  ~Name();

  void print();
};
