// Degree: MSc Computing
// Module: 70036 Object Oriented Design and Programming
//
// Add all of your code that pertains to question 2 to this file.

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
// Some declarations of the class template 'vector' are below.

/*
template <typename T> class vector {
	public:
		vector(); // constructor that creates an empty vector
		void push_back(T&& item); // adds an item to the end
		void pop_back(); // removes the last item
		T& back(); // returns a reference to the last item
		vector<T>::constant_iterator cbegin(); // returns constant iterator
		vector<T>::constant_iterator cend(); // returns constant iterator
		bool empty(); // returns true if vector is empty
};
*/

/* Add your code below this line. */
class Vaccine{
    private:
    string name;
    double dose;
    double amoutInVial;

    public:
    Vaccine(string name1,double dose1,double c):name(name1),dose(dose1),amoutInVial(c){}
    ~Vaccine(){}
    double amountAddedToVials(){
        return dose;
    }

    double getamountInVial(){
        return amoutInVial;
    }
    virtual bool isSafeForAdministration(double num){
    }

    virtual string getInformation(){
    }

};

class TypeA:public Vaccine{
    private:
    double dilution;
    bool diluted=false;
    public:
    TypeA(string name1,double dose1,double c,double dilution1)
    :Vaccine(name1,dose1,c),dilution(dilution1){}
    ~TypeA(){}

    bool isSafeForAdministration(double num){
        diluted= true;
         dose = dose + num;
        if(num==dilution){
            return true;
        } else{
            return false;
        }
        
    }

    string getInformation(){
        string content = "Name:" + name + "Dose: " + to_string(dose) + "Amount: "+ to_string(amoutInVial);
        content += "Dilution amount" + to_string(dilution);
        return content;
    }
    
};

class TypeB:public Vaccine{
    private:
    int temperature =20;
    public:
    TypeB(string name1,double dose1,double c,int t)
    :Vaccine(name1,dose1,c),temperature(t){}
    ~TypeB(){}
    bool isSafeForAdministration(double num=0){
        if (temperature<20){
            return true;
        }
        return false;
    }

    string getInformation(){
        string content = "Name:" + name + "Dose: " + to_string(dose) + "Amount: "+ to_string(amoutInVial);
        content += to_string(temperature);
        return content;
    }

    
};

class Vials{
    private:
    double storage;
    Vaccine* vaccine;
    
    public:
    Vials(double s,Vaccine* v):storage(s),vaccine(v){}
    ~Vials(){}
    double amountLeft(){
        if(vaccine->isSafeForAdministration()){
        double num = this->vaccine->getamountInVial();
        double m =vaccine->amountAddedToVials()
        return num-m;
        }
        return vaccine->getamountInVial();
        
    }
    Vaccine* getVaccine(){
        return vaccine;
    }

    string print(){
        string content = vaccine.
    }
};

template<typename T, int SIZE>
class Tray{
    private:
    vector<T*> items; //note here, type has tp be T

    public:
    Tray(){}
    ~Tray(){
        for (auto it=items.begin(); it != items.end();it++){
            if (*it != nullptr){
                delete (*it);
            }
        }
    }

    void addItem(T* newItem){
        if(items.size()<SIZE){
            items.push_back(newItem);
        }
        throw runtime_error("can not add more items");
    }

    T* removeItem(){
        if(!items.empty()){
            T* t=items.push_back();
            return t;
        }
        throw runtime_error("no one left for removing");
    }

    int getSize(){
        return items.size();
    }
    void printTray(){
        for (T* item:items){
            if(item != nullptr){
                string content=item->print();
                cout << content << endl;
            }
        }
    }
};


int main(){
    Vaccine* vaccine1 = new TypeA("Covud-Protect",0.3,0.45,1.8);
    Vaccine* vaccine2 = new TypeB("Covud-Begone",0.5,5,15);
    
    Vials vials1(3,vaccine1);
    Vials vials2(6,vaccine2);
    //debug here: for putting in the tray, all elements should be parent type
    vaccine1->isSafeForAdministration(1.1);

    //create tray
    Tray<Vials,10> tray;
    tray.addItem(vials1);
    tray.addItem(vials2);

    while(tray.getSize()>0){
        Vials* item=tray.removeItem();
        if(item->getVaccine()->isSafeForAdministration()){
            cout << item->amountLeft();
        }
        
    }
}
