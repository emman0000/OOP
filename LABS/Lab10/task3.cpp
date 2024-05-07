//Programmer Emman Abrar Ali 23k0051 task 3
#include <iostream>
#include <string>
using namespace std;

// Abstract class
class Vehicle {
protected:
    string make;  string model;  int speed;
public:
    Vehicle(string make, string model, int speed) : make(make), model(model), speed(speed) {}

    // Getters
    string getMake() { return make; }
    string getModel() { return model; }
    int getSpeed() { return speed; }

    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual double calculateFuelEfficiency(double miles, double gallons) = 0;
};

// Derived class
class Car : public Vehicle {
    double fuelCap;

public:
    Car(string make, string model, int speed, double fuelCap) : Vehicle(make, model, speed), fuelCap(fuelCap) {}

    void accelerate() override {
        speed += 50;
    }

    void brake() override {
        speed -= 50;
    }

    double calculateFuelEfficiency(double miles, double gallons) override {
        return miles / gallons;
    }
};

// Another derived class
class Truck : public Vehicle {
    double loadCapacity;

public:
    Truck(string make, string model, int speed, double loadCapacity) : Vehicle(make, model, speed), loadCapacity(loadCapacity) {}

    void accelerate() override {
        speed += 30; 
    }

    void brake() override {
        speed -= 30; 
    }

    double calculateFuelEfficiency(double miles, double gallons) override {
        return miles / gallons; 
    }
};

int main() {
    // Create instances of Car
    Car car1("Porsche", "911", 320, 15.5);
    Car car2("Mercedes", "i7", 3000, 14.2);

    // Create an instance of Truck
    Truck truck("Mercedes", "G-Wagon", 290, 5000);

    cout << "Car 1: " << car1.getMake() << " " << car1.getModel() << endl;
    cout << "Initial Speed: " << car1.getSpeed() << " mph" << endl;
    car1.accelerate();
    cout << "Speed after accelerating: " << car1.getSpeed() << " mph" << endl;
    car1.brake();
    cout << "Speed after braking: " << car1.getSpeed() << " mph" << endl;
    cout << "Fuel Efficiency of Car 1: " << car1.calculateFuelEfficiency(100, 5) << " miles per gallon" << endl;
    cout << endl;

        cout << "Car 2: " << car2.getMake() << " " << car2.getModel() << endl;
    cout << "Initial Speed: " << car2.getSpeed() << " mph" << endl;
    car2.accelerate();
    cout << "Speed after accelerating: " << car2.getSpeed() << " mph" << endl;
    car2.brake();
    cout << "Speed after braking: " << car2.getSpeed() << " mph" << endl;
    cout << "Fuel Efficiency of Car 1: " << car2.calculateFuelEfficiency(100, 5) << " miles per gallon" << endl;
    cout << endl;

    cout << "Truck: " << truck.getMake() << " " << truck.getModel() << endl;
    cout << "Initial Speed: " << truck.getSpeed() << " mph" << endl;
    truck.accelerate();
    cout << "Speed after accelerating: " << truck.getSpeed() << " mph" << endl;
    truck.brake();
    cout << "Speed after braking: " << truck.getSpeed() << " mph" << endl;
    cout << "Fuel Efficiency of Truck: " << truck.calculateFuelEfficiency(80, 4) << " miles per gallon" << endl;

    return 0;
}//end main
