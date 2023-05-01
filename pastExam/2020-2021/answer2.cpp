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
float getTemp(){
    //funciton to return the current temprature
    return 10.00;
}

//Question a

class Vaccine{
    public:
    bool diluted; //debug: design here,it if is true means it can be diluted
    double amount; //a dose of vaccine which stored in Vials
    double dose; //one injection vaccine
    string name;
    Vaccine(string n,double d,double a,bool dilu):name(n),dose(d),amount(a),diluted(dilu){}
    ~Vaccine(){}
    virtual bool safetoAdministration() = 0;

    virtual string print(){
        string content = "Vaccine Name: "+ name + "Vaccine Dose: " + to_string(dose)+"\n";
        return content;
    }
};

class VaccineA: public Vaccine{
    public:
    double dilution;
    VaccineA(double dilution1,double a,double d, string n,bool diluted1):Vaccine(n,d,a,diluted1),dilution(dilution1){}
    ~VaccineA(){}

    void addDilution(int n){ //debug: note design here
        if(!diluted && n ==dilution ){
           diluted = true;
        }else{
            cout << "Incorrect dilution amount being added";
        }
        dose = dose+dilution;
    }

    bool safetoAdministration()override{
        if(diluted){
            return true;
        }
        return false;
    }

    string print() override{
        string content = Vaccine::print();
        if(safetoAdministration()){
            content += std::string("It is safe toAdministration")+"The amount has to be diluted is" + to_string(dilution)+"\n";
        } else{
            content += "It is not safe for Administration";
        }
        return content;
    }
   
};

class VaccineB: public Vaccine{
    public:
    float tempurature=20;
    VaccineB(float t,int a,int d, string n,bool diluted):Vaccine(n,d,a,diluted),tempurature(t){}
    ~VaccineB(){}

    bool safetoAdministration() override{
        if(tempurature>getTemp()){
            return true;
        }
        return false;
    }

    string print() override{
        string content = Vaccine::print();
        if(safetoAdministration()){
            content += std::string("Safe temerature") + to_string(tempurature)+"\n";
        } else{
            content += "It is not safe for Administration";
        }
        return content;
    }
};

class Vials{
    public:
    double amount;//storage amount
    Vaccine& vaccine;

    Vials(double a, Vaccine& v):amount(a),vaccine(v){}
    ~Vials(){}

    int amountLeft(){
        //if a patient need gets vaccined   
        return amount-vaccine.dose; //dose changed according to safe or not

        //throw runtime_error("Vaccine amount is larger than Vials's storage size")
    }

    string print(){
        string content;
        content = "Vaccine in Vials " +vaccine.print();
        content += "Amount of Liquit left in bottle"+ to_string(this->amountLeft())+"\n"; 
        return content;
    }

};

template<int SIZE > class Trays{
    public:
    vector<Vials*> items;

    void addItem(Vials* item){
        items.push_back(item);
    }

    

    void printItems(){
        vector<Vials*>::iterator it;
        for (it = items.begin(); it != items.end(); it++){
            string content= (*it)->print(); //debug here: (*it)
            cout << content << endl;
        }
    }

    Vials* get() {
        Vials* item = items.back();
        items.pop_back();
        return item;
    }

    //debug: Dont forget destructor
    ~Trays(){
        for(auto it=items.begin(); it != items.end(); it++){
            delete *it;
        }
    }  
    
};

//Question b
int main(){
    cout << "Start of the program";
    //create vaccine:
    VaccineA v1 = VaccineA(1.8,0.45,0.4,"COvid-Protect",false);
    VaccineB v2 = VaccineB(15,5,0.5,"Covid-Begone",false);
    //create two vials:
    Vials vials1 = Vials(3.0,v1);
    Vials vials2 = Vials(6.0,v2);

    //Incorrectly dilute first vaccine:
    v1.addDilution(1.1);

    //create tray:
    Trays<10> tray1;
    tray1.addItem(&vials1);
    tray1.addItem(&vials2);
    while(tray1.items.size()>0){
        Vials* item =tray1.get(); //take one
    if(item->vaccine.safetoAdministration()){
        cout << "its safe for administration";
    } else{
        cout <<"Discard this one";
    }
    }
    
}