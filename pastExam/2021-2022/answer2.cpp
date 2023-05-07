//Question a:
#include<iostream>
#include<string>
#include<list>
#include<algorithm>
using namespace std;

//Question a
class Test{
    protected:
    double cost;
    //bool result;
    
    public:
    Test(double c):cost(c){}
    virtual ~Test(){} //debug here: add virtual since you have different Test type
    virtual double getCost(){
        return cost;
    }
    //debug here
    virtual void setoption(bool result){
    }

};

class Serology:public Test{
    private:
    public:
    /* debug:
    Serology(){
        Test(50);
    }
    */
   Serology():Test(50){}


    ~Serology(){}

};

class PCR:public Test{
    private:
    bool option=false;
    public:
    PCR(double cost):Test(cost){}
    ~PCR(){}
    void setoption(bool option1){
        option = option1;
    }

    double getCost(){
        if(this->option){
            return cost*2;
        }
        return cost;
    }
};

class Professonal{
    protected:
    string name;
    int years;
    double basesalary;
    double salary;
    list<Test*> alltest;

    public:
    Professonal(string name1,int years1,double base):
    name(name1),years(years1),basesalary(base){}
    ~Professonal(){  
        for (auto it = alltest.begin(); it != alltest.end(); it++ ){
            if(*it != nullptr){
                delete *it; //not sure whether it's right or not
            }
           
        }
    }

    void addTest(Test* newTest){
        alltest.push_back(newTest);
    }

    double totalTestcost(){
        double total = 0;
        for(auto it = alltest.begin(); it!= alltest.end();it++){
            if(*it != nullptr){
                total += (*it)->getCost();
            }
        }
        return total;
    }

    virtual double getsalary()=0;

};

class Nurse:public Professonal{
    public:
    Nurse(string name1,int years1,double base):Professonal(name1,years1,base){}
    ~Nurse(){}
    double getsalary(){
        double total = this->basesalary+100 * this->years;
        total += this->totalTestcost()*0.2;
        return total;
    }
};

class Pharmacist:public Professonal{
    public:
    Pharmacist(string name1,int years1,double base):Professonal(name1,years1,base){}
    ~Pharmacist(){}
    double getsalary(){
        double total = this->basesalary+100 * this->years;
        total += this->totalTestcost()*0.1;
        return total;
    }
};

int main(){
    //cout << "Enter"<< endl;

    //two professionals
    Nurse p1("Paula",5,20000);
    Pharmacist p2("Sara",10,25000);
    //create 3 tests
    /*
    PCR t1(90);
    PCR t2(150);
    Serology t3; //debug here
    */
    //must create with type Test
    Test* t1 = new PCR(90);
    Test* t2 = new PCR(150);
    Test* t3 = new Serology();

    //add test to professions
    p1.addTest(t1);
    p1.addTest(t3);

    t2->setoption(true);
    p2.addTest(t2);

    cout << "Nurse Salary: "<<p1.getsalary() << endl;
    cout << "Pharmacist salary: " << p2.getsalary() << endl;

}