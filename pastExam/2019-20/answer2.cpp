    // CID:
// Degree: MSc Computing Science
// Module: 517 Object Oriented Design and Programming
//
// Add all of your code that pertains to question 2 to this file.
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
// The declarations of the class template ’vector’ are below.
/*
template <typename T> class vector {
  public:
    vector(); // constructor that creates an empty vector
    void push_back(const T& item); // adds item to the vector
    vector<T>::constant_iterator cbegin(); // returns constant iterator
    vector<T>::constant_iterator cend(); // returns constant iterator
    unsigned int size(); // returns the number of items
};
// Available helper functions that can be used
/* Returns a std::string that is comprised of the given symbol with the given
 * length. E.g. makeErrorString(’#’, 3) returns the string: "###" */
std::string makeErrorString(char symbol, unsigned int length);

/* Returns a std::string of the given number with the given decimal places. It
 * also rounds numbers up or down as appropriate. E.g. numberToString(10.9, 0)
 * returns the string: "11" */
std::string numberToString(float number, unsigned int decimal_places);

/* Add your code below this line. */
// Question a
class Type{
    protected:
    int prefix;
    public:
    Type(int n):prefix(n){}
    virtual~Type =0;
     virtual string print()=0;
     string withPrefix(){
        if(prefix>0){
            string content;
            for(int i = 0; i < prefix; i++){
                content += " ";
            }
            return content;
        }
        throw runtime_error("no need prefix space");
     }


};

class Text:public Type{
    private:
    string data;
    public:
    Text(string d,int n):data(d),Type(n){}
    ~Text(){}
    string print(){
        string contents;
        if(this->prefix>0){
            contents += this->withPrefix();
        }
        contents += data;
        return contents;
   }

};

class Currency:public Type{
    private:
    int number;
    string postfix;
    int decimal;

    public:
    Currency(int n,string p, int d,int nn):number(n),postfix(p),decimal(d),Type(nn){}
    ~Currency(){}
    string print(){
        string contents;
        if(this->prefix>0){
            contents += this->withPrefix();
        }
         contents = numberToString(number,decimal)+ " "+postfix; 
          return contents;
    }

};

class Duration:public Type{
    private:
    int minutes;

    public:
    Duration(int m,int n):minutes(m),Type(n){}
    ~Duration(){}
    string print(){
        string contents;
        if(this->prefix>0){
            contents += this->withPrefix();
        }
        int hour = minutes/60;
        int minute = minutes%60;
        contents += numberToString(hour,0)+":"+numberToString(minute,0);
        return contents;      
    }
};


template<char ERROR>
class Table{
    private:
    int row;
    int col;
    vector<Type*> cells;
    int characterNum;
    public:
    Table(int r, int c, int cha):row(r),col(c),characterNum(cha){}
    ~Table(){
        auto it = cells.begin();
        for(;it!=cells.end();it++){
            delete *it;
        }
    }

    void addOneCell(Type* newCell){
        cells.push_back(newCell);

    }
    void printTable(){
        for(auto i = 0; i< cells.size(); i++){
            string contents;
            int total = cells[i]->print().length();
            if(characterNum< total){
                contents = makeErrorString(ERROR,characterNum);
            }
            int extra = characterNum-total;
            contents = cells[i]->print();
            for (auto j = 0; j < extra; j++){
                contents += " ";
            }
            cout << contents << "|";
            if(i%2==1){
                cout << endl;
            }
        }
    }


};

// Question b
int main() {
    //create Cell
    Type* cell1 = new Text("Karting Time:",0);
    Type* cell2 = new Text("Price:",0);
    Type* cell3 = new Duration(85,0);
    Type* cell4 = new Currency(60.5,"GBP",2,0);

    //create the table and add cells
    Table<'#'> table(3,2,15);
    table.addOneCell(cell1);
    table.addOneCell(cell2);
    table.addOneCell(cell3);
    table.addOneCell(cell4);
    table.addOneCell(new Duration(25,0));
    table.addOneCell(new Currency(25.4,"USD",0,0));

    //print table
    table.printTable();
    
 }