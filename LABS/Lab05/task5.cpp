// Task 5 lab05 Emman Abrar Ali 23k0051
#include<iostream>
#include<string>
using namespace std;

class Engine{
    int horsepower; 
    string type;
public:
    Engine(int hp, string type): horsepower(hp), type(type){}
    int getHorsepower() const { return horsepower; }
    string getType() const { return type; }
};//end class Engine 

class Wheels{
    int numberOfWheels; 
    string brand;
public:
    Wheels(int numberOfWheels, string brand): numberOfWheels(numberOfWheels), brand(brand){}
    int getNumberOfWheels() const { return numberOfWheels; }
    string getBrand() const { return brand; }
};//end class wheels

class Headlights{
    string typeoflights;
public:
    Headlights(string lights): typeoflights(lights){}
    string getTypeOfLights() const { return typeoflights; }
};
//end class headlights
class Steering{
    string steeringmode;
public:
    Steering(string mode): steeringmode(mode){}
    string getMode() const { return steeringmode; }
};//end class steering 

class Car{
    Engine* engine; 
    Wheels* wheels; 
    Headlights* headlights[4]; // Array of Headlights pointers
    Steering* steering;
public:
    Car(Engine* eng, Wheels* w, Headlights* h[], Steering* st)
        : engine(eng), wheels(w), steering(st) {
        for(int i = 0; i < 4; i++) {
            headlights[i] = h[i];
        }
    }//end constructor 

    ~Car(){
        delete engine;
        delete wheels;
        for(int i = 0; i < 4; i++) {
            delete headlights[i];
        }
        delete steering;
    }//end destructor 

    void detailsOfCar(){
        cout << "Engine: " << engine->getHorsepower() << " " << engine->getType() << endl;
        cout << "Wheels: " << wheels->getNumberOfWheels() << " " << wheels->getBrand() << endl;
        for(int i = 0; i < 4; i++) {
            cout << "Headlight " << i+1 << ": " << headlights[i]->getTypeOfLights() << endl;
        }//end for loop
        cout << "Steering: " << steering->getMode() << endl;
    }//end function 
};//end class car 

int main(){
  cout<<"Emman Abrar Ali 23k0051"<<endl;
    Engine* e1 = new Engine(1200, "V8");
    Wheels* w1 = new Wheels(4, "Michelin");
    Headlights* h1[4];
    h1[0] = new Headlights("LED");
    h1[1] = new Headlights("LED");
    h1[2] = new Headlights("LED");
    h1[3] = new Headlights("LED");
    Steering* s1 = new Steering("Power");

    Car car1(e1, w1, h1, s1);
    car1.detailsOfCar();
    return 0;
}//end main 


