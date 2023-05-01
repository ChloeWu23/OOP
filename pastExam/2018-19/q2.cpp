/* Add ALL of your code to this file. */
/* The declarations of the class template ’set’ are below. Do NOT uncomment them.
template <typename T> class set {
public:
set(); // constructor that creates an empty set
void insert(const T& item); // adds item to the set
set<T>::constant_iterator begin(); // returns constant iterator
set<T>::constant_iterator end(); // returns constant iterator
void erase(set<T>::const_iterator); // removes specified item
bool empty(); // returns true if the set is empty
};
*/
/* Do NOT add any other header files. */
#include<iostream>
#include<string>
#include<set>
/* Add your code below this line. */
using namespace std; // Save time
// Question b

class Fruit{
    protected:
    int weight;
    int date;
    string variety;
    string type;
    public:
    Fruit(string t,int w,int d,string v):weight(w),date(d),variety(v),type(t){}
    virtual bool isPremium()=0;
    virtual ~Fruit(){}
    bool fitForSale(){
        if (date>=3) return true;
          return false;
    }
    //note parent print general content and child's overriding function call parents method 
    virtual string printContent(){
       string result;
       result = "Type: " + type + "; Variety: "+variety
        +"; Before Date: "+ to_string(date)+"; Weight: "+ to_string(weight);
        return result;
    }
};

class Pear:public Fruit{
    private:
    bool stalkIntact;
    public:
    Pear(int w,int d,string v,bool s):Fruit("Pear",w,d,v),stalkIntact(s){
        //this->type=="Pear";
    }
    ~Pear(){}

    bool isPremium() override final{
        return stalkIntact && (this->weight==130);
    }

    string printContent(){
        string content=this->printContent() +";StackIntact:" ;
        //content+=";StackIntact:" + (this->stalkIntact)? "True" : "false" ;
        if(this->stalkIntact){
            content += "True";
        }else{
            content+="False";
        }
        return content;
    }     
};

//debug for Apple constructor
class Apple:public Fruit{
    protected:
    double redPercentage;
    public:
    Apple(string t,int w,int d,string v,double percentage):Fruit(t,w,d,v),redPercentage(percentage){
        //this->type == "Apple";
    }
    ~Apple(){}   

    string printContent() override {
        string contents = Fruit::printContent();//debug here, how to use parent's virtual function
        contents = contents + "RedPercentage: " + to_string(redPercentage);
        return contents;
    }
        
};
//debug:constructor
class RedApple:public Apple{
    public:
    RedApple(int w, int d, string v, double percentage):Apple("RedApple",w,d,v,percentage){}
    bool isPremium() override final{
        if(this->redPercentage >=0.75 && this->weight>=90) return true;
        return false;
    }

    
};


class MixedApple:public Apple{
    public:
    MixedApple(int w,int d, string v, double p):Apple("Mixed Apple",w,d,v,p){}
    bool isPremium() override final{
        if(this->redPercentage >=0.5 && this->weight>=90) return true;
        return false;
    }
};

//This is a template class with abstract type T and another int to be a template parameter
template<typename T,int Capacity> class Basket{
    private:
    T* items[Capacity];
    public:
    //constructor,debug here: since its pointer, no need to add intialization
    Basket(){}
    ~Basket(){
        for (int i = 0; i <= Capacity;i++){
           delete items[i];
        }
    }

    void addItems(T* newItem){
        for(int i = 0; i < Capacity; i++){
            if(items[i]==nullptr){
                items[i]= newItem;
            }
        }
    }
    //remove from the start
    T* removeItems(){
        for (int i = 0; i <= Capacity;i++){
            if(!items[i]){
                T* temp=items[i];
                items[i]=nullptr;
                return temp;
            }
        }
        return nullptr;
    }
    
    void printBasket(){
        for(int i = 0; i< Capacity;i++){
            if(!items[i]){
                cout << items[i]->printContent();
                cout << "check";
            }
        }
    }


};

int main(){
//create a basket with max of 30 fruits
Basket<Fruit,30> basket;
basket.addItems(new RedApple(95,7,"Gala",0.8));
basket.addItems(new MixedApple(80,8,"Cox",0.6));
basket.addItems(new Pear(140,2,"Ambrosia",true));
basket.printBasket();
Basket<Fruit,10> smallbasket;
//take out one from bigger basktet one time
for(int i = 0; i < 30; i++){
    Fruit* item=basket.removeItems();
    if(item==nullptr) continue;
    if(item->fitForSale() && item->isPremium()){
        smallbasket.addItems(item);
}
   basket.printBasket();
    smallbasket.printBasket();
}

if(item->fitForSale() && item->isPremium()){
    cout << "enter";
    smallbasket.addItems(item);
}

}
    


