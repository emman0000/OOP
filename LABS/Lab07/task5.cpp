//vehicles task 5
//Programmer Emman Abrar Ali 23k0051

#include<iostream>
#include<string>
using namespace std;

class Vehicle{
string make; string Model; int year;
public:
Vehicle(string m, string mo, int y): make(m), Model(mo), year(y){}//end 

//getters
string getmake()const{return make;}
string getmodel()const {return Model;}
int getyear()const{return year;}

};//end class

class Car: public Vehicle{
int numberofdoors; float fuelefficiency;
public:
Car(string m, string mo, int y, int nd, float fe): Vehicle(m,mo,y),
numberofdoors(nd), fuelefficiency(fe){}//end constructor
int getnumberofdoors()const{return numberofdoors;}
float getfuelefficiency()const{return fuelefficiency;}
};//end class car

class ElectricCar : public Car{
int batterylife;
public:
ElectricCar(string m , string mo , int y, int nd, float fe, int bl):
Car(m,mo,y,nd,fe), batterylife(bl){}//end constructor)


int getbatterylife()const{return batterylife;}
};//end class Electric Car

int main(){
ElectricCar e1("Toyota", "Camry", 2023, 4, 50.0, 100);
cout<< "Make: "<<e1.getmake()<<endl;
cout<< "Model: "<<e1.getmodel()<<endl;
cout<< "Year: "<<e1.getyear()<<endl;
cout<< "Number of Doors:  "<<e1.getnumberofdoors()<<endl;
cout<<"Fuel Efficiency: "<<e1.getfuelefficiency()<<endl;
cout<< "Battery Life: "<<e1.getbatterylife()<<endl;

return 0;  
}//end main
