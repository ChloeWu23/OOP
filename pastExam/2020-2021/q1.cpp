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
	bool clientIsAvailable(Client& p, int time);
	bool agentIsAvailable(Agent& p, int time);
	bool propertyIsAvailable(Property& p, int time);
	Property& getProperty(int latitude, int longitude);
	Agent& getAgent(int phoneNumber, string name);
	Client& getClient(int phoneNumber);
};


//////////////////// Do not change anything above this line! ///////////////////
// Your code goes here
//Qa:

class Client{
	public:
	int phonenum;	
	Client(int n):phonenum(n){}
	~Client(){}
};

class Agent{
	public:
	int phonenum;
	string name;
	Agent(int n,string name1):phonenum(n),name(name1){}
	~Agent(){}
};

class Property{
	public:
	int latitude;
	int longitude;
	Property(int la,int lo):latitude(la),longitude(lo){}
	~Property(){}

};

class Appointment{
	public:
	Agent& agent;
	Property& property;
	Client& client;
	int time;
	DB& database;//debug here,design for cancel function

	Appointment(Agent& a, Property& p, Client& c,int t,DB& d):agent(a),property(p),client(c),time(t),database(d){}

	~Appointment(){}
	Appointment& cancel();


};



//questionb:implement function in DB class
Appointment& DB::makeAppointment(Agent& a, Property& p, Client& v, int time){
	Appointment newAppointment(a, p, v, time,*this); //debug here: syntax for creating an instance of class with constructor
	db.push_back(newAppointment); //put it on the back of the appointment list
	return(db.back()); //return reference to last element
}

//ALgo: to check client is availble or not, its to check the whole data base to see whether there is a appointment with this time and this client
bool DB::clientIsAvailable(Client& p, int time){
	for (Appointment appointment:db){
		if(appointment.client.phonenum == p.phonenum && appointment.time==time){
			return false;
		}
	}
	return true;
}

bool DB::agentIsAvailable(Agent& p, int time){
	for(Appointment& appointment:db){ //think about: whether you can not using reference,works I think
		if(appointment.agent.phonenum == p.phonenum && appointment.time == time){
			return false;
		}
	}
	return true;
}

bool DB::propertyIsAvailable(Property& p, int time){
	for(Appointment& appointment:db){
		if(appointment.property.latitude == p.latitude && appointment.property.longitude == p.longitude
				&& appointment.time==time){
			return false;
		}
	}
	return true;
}

Property& DB::getProperty(int latitude, int longitude){
	for(Property& p:properties){ //debug here: using reference of Property for tranverse, since we need to return &Property and if its value destroyed after call
		if(p.latitude==latitude && p.longitude == longitude){
			return p;  
		}
	}
	//ask to create a new one if not exsit
	Property p(latitude,longitude);
	this->properties.push_back(p);
	return(this->properties.back());
}

Agent& DB::getAgent(int phoneNumber, string name){
	for(Agent& agent:agents){
		if (agent.phonenum == phoneNumber && agent.name == name){
			return agent;
		}
	}
	Agent a(phoneNumber,name);
	this->agents.push_back(a);
	return(agents.back());
}

Client& DB::getClient(int phoneNumber){
	for (Client& client:clients){
		if(client.phonenum == phoneNumber){
			return client;
		}	
	}
	//throw runtime_error("can't find client");
	Client c(phoneNumber);
	clients.push_back(c);
	return (clients.back());
	/*
	another way:
	Client c(phoneNumber);
	Client& c2 = c;
	clients.push_back(c);
	return c2;
	*/
}


//Question c:
 Appointment& Appointment::cancel(){
	//debug: algo:check DB first allow new time of the appointment
	for(int i = 0; i < 1000; i++){
		int newtime = now()+i; //debug here: don't use time. since its an attribute
		if (database.clientIsAvailable(client,newtime) && database.agentIsAvailable(agent,newtime)
		&& database.propertyIsAvailable(property,newtime)){
			this->time = newtime;
			return *this;		
		}

	}
	throw runtime_error("Cant fint a new appointment time");

 }
 



//////////////////// Do not change anything below this line! ///////////////////
int main(int /*argc*/ , char* /*argv*/ []) {
	cout <<"start of the program" << endl;
	DB db;
	auto p1 = db.getProperty(0, 0);
	auto a1 = db.getAgent(12345, "Jules");
	auto c1 = db.getClient(54321);
	auto app = db.makeAppointment(a1, p1, c1, now() + 8);
	auto newAppointment = app.cancel();
	std::cout << newAppointment.time << std::endl;
	return 0;

}




