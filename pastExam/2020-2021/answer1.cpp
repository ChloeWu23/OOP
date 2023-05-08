// Degree: MSc Computing
// Module: 70036 Object Oriented Design and Programming
//
// Add all of your code that pertains to question 1 to this file.
//
#include <iostream>
#include <string>
#include <list>
using namespace std;

// namespace std {
// template <typename T> class list {
// /**
// * Appends the given element value to the end of the container.
// */
// void push_back(T&& value);
// /**
// * Returns a reference to the last element in the container.
// */
// T& back();
// };
// } // namespace std

int now() { return 0; }

class Client;
class Agent;
class Property;
class Appointment;


class DB {
	list<Appointment> db;
	list<Agent> agents;
	list<Property> properties;
	list<Client> clients;

public:
	Appointment& makeAppointment(Agent& a, Property& p, Client& v, int time);
	Property& getProperty(int latitude, int longitude);
	Agent& getAgent(int phoneNumber, string name);
	Client& getClient(int phoneNumber);
    bool clientIsAvailable(Client& p, int time);
	bool agentIsAvailable(Agent& p, int time);
	bool propertyIsAvailable(Property& p, int time);
};


//////////////////// Do not change anything above this line! ///////////////////
// Your code goes here
//Qa:
class Property{
    public:
    int latitude;
    int longitude;

    Property(int m, int n):latitude(m), longitude(n){}
    ~Property(){}
   

};

class Agent{
    public:
    int phoneNum;
    string name;
    Agent(int p):phoneNum(p){}
    ~Agent(){}
    

};

class Client{
    public:
    int phoneNum;
    Client(int p, string n):phoneNum(p),name(n){}
    ~Client(){}
    
    
}

class Appointment{
    public:
    Agent* agent;
    Property* property;
    Client* client;
    int time;
    DB* database;

    Appointment(Agent* a,Property* p, Client* c, int time1):
    agent(a),property(p),client(c),time(time1){}
    cancel();
    ~Appointment(){}

};

//note that p has to be reference in the for loop
Property& DB::getProperty(int latitude, int longitude){
    for (Property& p:properties){
        if(p.latitude == latitude && p.longitude == longitude){
            return p;
        }
    }
     throw runtime_error("cant find");
}

Agent& DB::getAgent(int phoneNumber, string name){
    for(Agent& agent:agents){
        if(agent.phoneNum == phoneNumber && agent.name){
            return agent;
        }
    }
     throw runtime_error("cant find");

}
Client& DB::getClient(int phoneNumber){
    for (Client& client:clients){
        if(client.phoneNum == phoneNumber){
            return client;
        }
    }
    throw runtime_error("cant find");
}


Appointment& DB::makeAppointment(Agent& a, Property& p, Client& v, int time){
    
        Appointment* newAppointment = new Appointment(&a,&p,&c,time);
        db.push_back(*newAppointment);
        return *newAppointment;

}

bool DB::clientIsAvailable(Client& p, int time){
    for(auto item:db){
            if (item.client == p && item.time == time){
                return false;
            }
        }
        return true;
}
bool DB::agentIsAvailable(Agent& p, int time){
     for(auto item:db){
            if (item.agent == p && item.time == time){
                return false;
            }
        }
        return true;
}


bool DB::propertyIsAvailable(Property& p, int time){
     for(auto item:db){
            if (item.property == p && item.time == time){
                return false;
            }
        }
        return true;
}


bool DB::isAvaible(int time){
        for(auto item:database->db){
            if (item.client == this && item.time == time){
                return false;
            }
        }
        return true;
    }

Appointment& Appointment::cancel(){
    //cancel this appointment
    for(Appointment& item:database->db){
        if(item == *this){
            &item = nullptr;
        }
    }
    //find the next availble time
    for (int i= now(); i < 1000; i++){
        if (database->agentIsAvailable(this->agent,i)&&database->clientIsAvailable(this->client,i)
    && database->propertyIsAvailable(this->property,i)){
        return *(new Appointment(agent,property,client,i));
    }
    }
    
    throw runtime_error("can not find apppointment");
}