//Programmer Emman Ali-23k0051 Lab03-Task2
#include <iostream>
#include <string>
using namespace std;

class WaterBottle {
private:
    string company;
    string color;
    int capacityLiters;
    int capacityMilliliters;

public:
    // Constructor
    WaterBottle(string comp, string col, int liters, int milliliters) {
        company = comp;
        color = col;
        capacityLiters = liters;
        capacityMilliliters = milliliters;
    }//end of public
    void setCompany(string comp) {
        company = comp;
    }
    string getCompany() {
        return company;
    }
    void setColor(string col) {
        color = col;
    }
    string getColor() {
        return color;
    }
    void setCapacityLiters(int liters) {
        capacityLiters = liters;
    }
    int getCapacityLiters() {
        return capacityLiters;
    }

    void setCapacityMilliliters(int milliliters) {
        capacityMilliliters = milliliters;
    }

    int getCapacityMilliliters() {
        return capacityMilliliters;
    }

    // Method to update water capacity after consumption
    void consumedWater(int millilitersConsumed) { //conversion 
        int totalMilliliters = (capacityLiters * 1000)  + capacityMilliliters;
        totalMilliliters -= millilitersConsumed;

        if (totalMilliliters < 0) {
            cout << "You consumed more water than the capacity of the bottle." << endl;
            capacityLiters = 0;
            capacityMilliliters = 0;
        } else {
            capacityLiters = totalMilliliters / 1000;
            capacityMilliliters = totalMilliliters % 1000;
        }
    }
};

int main() {
//object water bottle 
    WaterBottle bottle("Contigo", "Blue", 2, 500);;
  

    //  capacity before consumption
    cout << "Initial Water Capacity in Liters is :  " << bottle.getCapacityLiters() << " \n Initial Water Capacity in Millileters is: "<< bottle.getCapacityMilliliters() << endl;

    //Take input from user for water consumption
    int millilitersConsumed;
    cout << "Enter the amount of water consumed in milliliters: ";
    cin >> millilitersConsumed;

    // Update capacity after consumption
    bottle.consumedWater(millilitersConsumed);

    // Display updated capacity
    cout << "Updated Water Capacity: " << bottle.getCapacityLiters() << " liters and " 
         << bottle.getCapacityMilliliters() << " milliliters." << endl;

    return 0;
}//end main
