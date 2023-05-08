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
    int beforedate;
    string variety;
    //bool premium = false;

    public:
    Fruit(int w, int b, string v):weight(w),beforedate(b),variety(v){}
    virtual ~Fruit()=0;

    bool fitForSell(){
        if(beforedate < 3){
            return false;
        }
        return true;
    }

    string print(){
        string content = variety + to_string(weight)+ to_string(beforedate);
        return content;
    }

    virtual bool isPremium()=0;
 

};

class Apple:public Fruit{
    protected:
    double redpercentage;
    public:
    Apple(int w, int b, string v,double red):Fruit(w,b,v),
    redpercentage(red){}
    virtual ~Apple()=0;
    
};

class RedApple: public Apple{
   
    public:
    RedApple(int w, int b, string v,double red):Apple(w,b,v,red){}
    ~RedApple(){}

    bool isPremium(){
        bool flag = false;
        if(this->weight> 90 && redpercentage >= 0.75){
            flag = true;
        }
        return flag;
    }

};

class MixedApple:public Apple{
 
    public:
    MixedApple(int w, int b, string v,double red):Apple(w,b,v,red){}
    ~MixedApple(){}

    bool isPremium(){
        bool flag = false;
        if(this->weight> 90 && redpercentage >= 0.5){
            flag = true;
        }

        
        return flag;
    }

};


class Pear: public Fruit{
    private:
    bool stalk;

    public:
    Pear(int w, int b, string v,bool s):Fruit(w,b,v),
    stalk(s){}

    ~Pear(){}

    bool isPremium(){
        bool flag = false;
        if(this->weight> 130 && stalk==false){
            flag = true;
        }

        return flag;
    }

};


template<typename T, int CAPACITY>
class Basket{
    private:
    set<T*> items; //have to use set container
    public:
    Basket(){}

    ~Basket(){
        for(auto item:items){
            if(!item){
                delete item;
            }
        }
    }

    void addOne(T* newitem){
        if(items.size() < CAPACITY){
            items.insert(newitem);
        }
        throw runtime_error("can not add more fruits");
    }

    T* removeOne(){
        for(auto item:items){
            if(!item){
                T* temp = item;
                item = nullptr;
                return temp;
            }
        }
        throw runtime_error("no more can remove");
    }

    bool isEmpty(){
        if (items.size()==0){
            return true;
        }
        return false;
    }

    void print(){
        string content;
        for(auto item:items){
            content = item->print();
            cout << content<< endl;
        }
    }

};

int main(){
    //create a basket
    Basket<Fruit,30> largeBasket;
    Basket<Fruit,10> smallBasket;
    largeBasket.addOne(new RedApple(95,7,"Gala",0.8));
    largeBasket.addOne(new MixedApple(80,8,"Cox",0.6));
    largeBasket.addOne(new Pear(140,2,"Ambrosia",true));
    while(!largeBasket.isEmpty()){
        Fruit* item =largeBasket.removeOne();
        if(item->fitForSell() && item->isPremium()){
            smallBasket.addOne(item);
        }

    }
    largeBasket.print();
    smallBasket.print();
    
}