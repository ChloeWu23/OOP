#include <functional>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define maxSensorsPerRegion 32
void ingestEvent(double value, double latitude, double longitude, int timestamp); 
void addObserverToSensorAtPosition(std::function<void()> observer, double latitude,
                                   double longitude);
/*
Note that:the key of this program is to design a data structure used for measurememnt management
*/
int main() {
    cout << "enter"<<endl;
    // Example for event ingestions 
ingestEvent(1709.88, 988.456, 3470.3, 1); 
ingestEvent(4856.02, 4687.31, 216.378, 2); 
ingestEvent(183.283, 780.31, 1854.87, 3); 
ingestEvent(1046.07, 3325.91, 2326.46, 4); 
ingestEvent(3768.23, 106.577, 978.304, 5); 
ingestEvent(2834.78, 40.3523, 3343.87, 6); 
ingestEvent(3690.92, 578.758, 2952.94, 7); 
ingestEvent(4051.8, 1484.58, 2824.1, 8);
  ///////////////////////////////////////////////
  // Q1 b): Your code to add observers goes here: //

return 0; }
//////////////////////////////////////////



// Your implementation for Q1 a) goes here //


//one position 64+64=128 bits
class Position{
    private:
    double latitude;
    double longtitude;
    int size = 128;

    public:
    Position(double la,double lo):latitude(la),longtitude(lo){}
    ~Position(){}

    bool isEqual(Position& p){
        if (abs(p.getLatitude() -latitude) <= 0.001 && abs(p.getLongtitude()-longtitude)<= 0.01){
            return true;
        }
        return false;
    }

    double getLatitude(){
        return latitude;
    }

    double getLongtitude(){
        return longtitude;
    }


};

//one measurement: 64+64=128 bit
class Measurement{
    private:
    double measureValue;
    int timestamp;
    int size=128;

    public:
    Measurement(double m,int t):measureValue(m),timestamp(t){}
    ~Measurement(){};
    double getValue(){
        return measureValue;
    }

};

//need to declare an like Vactor class type
template<typename T,int MAXITEM>
class myVector{
    private:
    T* items[MAXITEM];
    public:
    myVector(){}
    ~myVector(){
        for (int i = 0; i < MAXITEM; i++){
            if(items[i]!=nullptr){
                delete items[i];
            }
        }
    }

    //need overwrite operator[]
    T* operator[](int i){
        if(i > 0 && i < MAXITEM){
            return *(&items[0]+i);
        }
    }

    void add(T* item){
        for (int i = 0; i < MAXITEM; i++){
            if(items[i]!=nullptr){
                items[i]=item;
                return;
            }
        }
        throw runtime_error("No space");

    }
    void remove(T* item){
        for (int i = 0; i < MAXITEM; i++){
            if(items[i]==item){
                item[i]=nullptr;
                return;
            }
        }
        throw runtime_error("No such item");
    }

};

 class Sensor{
        private:
        Position position;
        //sensor can hold only the last 1000 measurements
        myVector<Measurement,1000> measurements;
        int size = 128;
        int count = 0;
        std::function<void()> observer; //design here,one sensor has one observer
        
        
        public:
        Sensor(Position& p, myVector<Measurement,1000>m):position(p),measurements(m){}
        ~Sensor(){}
        Position& getPosition(){
            return position;
        }
        double getAverage(){
            double temp=0;
            for(int i = 0; i <count; i++){
               temp += measurements[i]->getValue();
            }
            return temp/count;
        }
        void addMeasurement(double value,int timestamp){
            if(count < 1000){
                Measurement* m = new Measurement(value,timestamp);
                measurements.add(m);
                count++;
                return;
            }
                /*
                if (measurements[i]==nullptr){
                    measurements[i]=new Measurement(value,timestamp);
                    return;
                } debug here: No measurements[i] is defined
                */
                     
            }

            void setobserver(std::function<void()> newobserver){
                observer = newobserver;
            }
            
        
    };

class Region{
    private:
    Position left;
    Position right;
    //List<Sensor*> sensors = nullptr;
    //static int max_sensors = 32; //debug here: need to be static otherwise can't use it non-instance
    //another way is better: define to create const value, global varaible not working its not real constant
    
    //make sensors to be array
    Sensor* sensors[maxSensorsPerRegion];
    int count = 0;
    int size = 128;
   
    public:
    //debug here: Position has to be reference
    //debug here: need to add const for reference Position,thus left can accept temporary object of type Position
    Region(const Position& p1,const Position& p2):left(p1),right(p2){}
    ~Region(){
        for(int i = 1;i <= maxSensorsPerRegion;i++){
            if (sensors[i] != nullptr){
                 delete sensors[i];
            }
            
        }
        //delete[] sensors; //not work here: didnt use new
    }
    int getCount(){
        return count;
    }
    Sensor* getSensors(int j){
        if(j < count){
            return sensors[j];
        }
        throw runtime_error("out of index"); //start addr of array sensors
    }

    double getMeanRegion(){
        double temp;
        for(int i = 0; i < count; i++){
            //temp +=sensors[i]->getAverage();
            temp = temp+sensors[i]->getAverage();
        }
        return temp/count;
    }

    bool contains(double latitude,double longtitude){
        if(left.getLatitude() <latitude && left.getLongtitude() <longtitude
        && right.getLatitude() > latitude && right.getLongtitude() > longtitude){
            return true;
        }
        return false;
    }
    void addSensors(Sensor* s){
        for (int i = 0; i < maxSensorsPerRegion; i++){
            if(sensors[i]==nullptr){
                sensors[i]=s;
                count++;
                size=size+8;//add one pointer to the array sensors
                return;
            }
        }
        throw runtime_error("can not add more sensors to the region");
    }

    void deleteSensors(Sensor* s){
        for(int i = 0; i < maxSensorsPerRegion; i++){
            if(sensors[i]==s){
                sensors[i]=nullptr;
                count--;
                size=size-8;
                return;
            }
        }
        throw runtime_error("no such sensor in the region");
    }

    

};


   

    class Program{
        private:
        Region* items[32];
        int size = 0;
        int count = 0; //region count
        int extraordinaryNum = 0;
        Sensor* observed = nullptr;
    


        public:
        Program(){}
        ~Program(){}
        bool isExpensive(){
            if(size>64){
                return true;
            }
            return false;
        }

        void addRegion(Region* item){
           for (int i = 0; i < 32; i++){
            if(items[i]==nullptr){
                items[i]=item;
                count++;
                return;
            }
           }
           throw runtime_error("can not add region");
        }

        void addEvent(double value, double latitude, double longitude, int timestamp){
            //Position p=Position(latitude,longitude); //copy constructor
            Position p(latitude,longitude);
            
            //find region with this sensor，then for this sensor add measurements to it
            for(int i = 0; i < 32; i++){
                if(items[i]->contains(latitude,longitude)){
                    for (int j = 0; j < maxSensorsPerRegion; j++){
                        Sensor* temp=items[i]->getSensors(j);
                       if(p.isEqual(temp->getPosition())){
                        temp->addMeasurement(value,timestamp);
                        return;
                       }
                    }
                }

                }
            }

    //std::function<void()> observer:this param means a function with no param 
    //and return type is void    
    void addObserverToSensorAtPosition(std::function<void()> observer, 
        double latitude, double longitude){
            Position p(latitude,longitude);
            for (int i = 0; i < count; i++){
                if(items[i]->contains(latitude,longitude)){
                    double temp=items[i]->getMeanRegion();
                //calculate sensor in this region whether has extraordinary behaviour
                for(int j = 0; j < items[i]->getCount();i++){
                    Sensor* s =items[i]->getSensors(j);
                    if(p.isEqual(s->getPosition())){
                        double temp1 = s->getAverage();
                        double result = abs(temp1-temp)/temp;
                        if(result >0.2){
                            //need to add observer to sensor at this position
                            //check previous observer sensor active or not
                            if(observed!=nullptr){
                                //remove and replace with new one
                                observed=nullptr;
                            }
                            //add new sensor
                            s->setobserver(observer);
                            observed = s;
                            cout << "an extraordinary event occurs";
                            extraordinaryNum++;
                            exit(1);
                        }
                    }   
                }
            }
        }
    }
    };

     Program* program = new Program();

    //set up program
    void setup(){
        program->addRegion(new Region(Position(5000, 0), Position(0, 5000)));
        //add sensors...

    }

    //debug:the given function should be a global function and call functions in other class
    void ingestEvent(double value, double latitude, double longitude, int timestamp){
        program->addEvent(value,latitude,longitude,timestamp);
        return;

}

