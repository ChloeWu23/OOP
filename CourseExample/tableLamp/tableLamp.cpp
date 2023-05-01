/* class example of table lamp*/
#include<iostream>
using namespace std;
class TableLamp {
private:
enum {ON, OFF} state; //state variable is enum take ON and OFF two values
:
  TableLamp() {state = OFF; } //constructor
  void pressSwitch() {
    state = ( state == ON ? OFF: ON) ; //true return OFF
  }
  void printLampState(){
    cout << "Lamp is " << ( state == ON ? "ON" : "OFF") << endl;
  } 
};
//inheritant class AdjTableLamp
class AdjTableLamp : public TableLamp{
private:
	float brightness;
public:
	AdjTableLamp() { brightness = 1.0; } //constructor
	void dim(){
	if (brightness > 0.1) brightness -= 0.1;
	}
	 void printAdjLampState() {
	 printLampState(); //use parent class function
	 cout << "Brightness is " << brightness << endl;
}

};


int main (){
	TableLamp lamp; //call default constructor
	AdjTableLamp adj_lamp; //call defalut constructor
  lamp.printLampState();
	lamp.pressSwitch();
	lamp.printLampState();
 
  adj_lamp.printAdjLampState();
	adj_lamp.pressSwitch();
	adj_lamp.dim();
	adj_lamp.printAdjLampState();
}
