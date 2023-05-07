#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Vehicle{
    public:
    int speed;
    int distance;
    Vehicle(int s, int d):speed(s),distance(d){}
    ~Vehicle(){}
    

};

class Road;

class Intersection{
    public:
    Road* roads[4]; //0,1,2,3 stands for left,right,top,bottom direction
    Intersection(){}
    ~Intersection(){}
    
};

class Road{
    public:
    int length;
    int maxspeed;
    Intersection* endIntersection;
    vector<Vehicle*> vehicles;

    Road(int l, int m,Intersection* end):length(l),maxspeed(m),endIntersection(end){}
    ~Road(){
        for (auto it = vehicles.begin(); it != vehicles.end(); it++){
            if (*it != nullptr){
                delete *it;
            }
        }
    }

    void addVehicles(int speed, int distance){
        Vehicle* newVehicle = new Vehicle(speed,distance);
        vehicles.push_back(newVehicle);
    }

    void removeVehicles(Vehicle* v){
        for (auto it = vehicles.begin(); it != vehicles.end(); it++){
            if (*it == v){
                delete *it;
            }
        }
    }

    Vehicle* anyVehicleAtEnd(){
        for(auto it = vehicles.begin(); it != vehicles.end(); it++){
            if (*it != nullptr && (*it)->distance == length){
                return (*it);
            }
        }
        return nullptr;
    }

    int vehiclesinbetween(int m, int n){
        for(auto it = vehicles.begin(); it != vehicles.end(); it++){
            if ((*it)->distance <n && (*it)->distance > m){
                return (*it)->distance;
            }
        }
            return 0; //no block
     }
    void moveTImeForward(){
        //check whether is there a car at the end of the road
        Vehicle* endVehicle = anyVehicleAtEnd();
        if(endVehicle != nullptr){
             for (int j = 0; j < 4; j++){
                    Road* temp = *(endIntersection->roads+j);
                    if (temp != this && temp->anyVehicleAtEnd() == nullptr){ 
                        //turn on this road
                        //remove this vehicle on this road and add it on temp road
                        this->removeVehicles(endVehicle);
                        temp->addVehicles(endVehicle->speed,temp->length);
                        break;
                    }
                }
                //otherwise can't find intersection to turn, has to stay at this position
                //do nothing
        }

        //change distance of each vehicle
           for(auto it = vehicles.begin(); it != vehicles.end(); it++){
            if (*it != nullptr && (*it) != endVehicle){
                int movedistance = min((*it)->speed,this->maxspeed);
                int m = (*it)->distance;
                int n = m+ movedistance;
                if(this->vehiclesinbetween(m,n) == 0){
                    (*it)->distance += movedistance;
                } else{ //here are vehicle between m,n
                    (*it)->distance = vehiclesinbetween(m,n);
                }
                    
                } 
                
           }   
               return;
        }
    
};



int main(){
    cout << "enter" << endl;
}