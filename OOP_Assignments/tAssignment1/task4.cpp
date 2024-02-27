//Programmer Emman Abrar Ali 23k0051 Assignment Task4
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//class of Roller Coaster WOHOO!
class RollerCoaster { 
    // Member variables
    string name; int height;int speed;int length;int capacity;int numOfRiders;bool rideInProgress;
public: 
    // Default constructor
    RollerCoaster(): name("Mini Bus Express!!"), height(500), speed(0), length(2000), capacity(20), numOfRiders(0), rideInProgress(false) {}

    // Parameterized constructor
    RollerCoaster(string name, int height, int speed, int length, int capacity): name(name), height(height), speed(speed), length(length), capacity(capacity), numOfRiders(0), rideInProgress(false) {
        // Adjusting capacity to be a multiple of 2 till 20
      //basically if the capacity is not divisible by 2 but is divisible by 3 the remainder will be subtracted from the initial capacity so that it is a multiple of 2. Riders in almost all Roller Coasters sit in pairs rather that trios or more. 
        if (capacity <= 3) {
            capacity = 4;
        } else {
            int x = capacity % 2;
            int y = capacity % 3;
            if (x == 0 && y == 0) {
                capacity = capacity - y;
            } else if (x != 0 && y == 0) {
                capacity = capacity - x;
            } else if (x == 0 && y != 0) {
                capacity = capacity + (2 - x);//adding 2 here to make the multiple of 3 divisible by 2 
            }
        }
    }//end of function that sets the capacity to be a multiple of 2 till 20.
//Pretty Basic meethod here loads of getter and setter functions that use this -> pointer to help access the member variables.
    // Getter and setter functions start
    string getName() const { return name; }
    void setName(string name) { this->name = name; }

    int getHeight() const { return height; }
    void setHeight(int height) { this->height = height; }

    int getSpeed() const { return speed; }
    void setSpeed(int speed) { this->speed = speed; }

    int getLength() const { return length; }
    void setLength(int length) { this->length = length; }
//getter and setter for the capacity method repeated here within the setter function
    int getCapacity() const { return capacity; }
    void setCapacity(int capacity) {
        if (capacity <= 3) {
            this->capacity = 4;
        } else {
            int x = capacity % 2;
            int y = capacity % 3;
            if (x == 0 && y == 0) {
                this->capacity = capacity - y;
            } else if (x != 0 && y == 0) {
                this->capacity = capacity - x;
            } else if (x == 0 && y != 0) {
                this->capacity = capacity + (2 - x);
            }
        }//end else condition 
    }//same as riders but for capacity.
//more getter and setter functions for the numOfRiders
    int getNumOfRiders() const { return numOfRiders; }
    void setNumOfRiders(int numOfRiders) { this->numOfRiders = numOfRiders; }

    bool getRideInProgress() const { return rideInProgress; }
    void setRideInProgress(bool rideInProgress) { this->rideInProgress = rideInProgress; }

    // Function to board riders onto roller coaster this function basically will check if the number of riders is exceeding the capacity of the roller coaster and if it is then it will return false and if it is not then it will return true
    int boardRiders(int numofRiders) {
        if (!rideInProgress && numofRiders <= capacity - numOfRiders) {
            numOfRiders += numofRiders; //numofRiders is the number of riders that are boarding onto the roller coaster or want to board onto the roller coaster. Whereas numOfRiders is the total number of riders on the roller coaster present at any given time. 
            return 0;
        } else {
            return (numofRiders - capacity - numOfRiders);
        }
    }//end boarding riders

    // Function to start the ride
    int startRide() {
        if (!rideInProgress) {
            rideInProgress = true;
            return 0;
        } else {
            return -1;
        }
    }

    // Function to stop the ride
    int stopRide() {
        if (rideInProgress) { //self-explanatory but the ride will stop if the ride is in progress.
            rideInProgress = false;
            return 0;
        }
    }

    // Function to unload passengers
    void unloadPassengers(int numofPassengers) {
        if (!rideInProgress) {
            numofPassengers = 0; //just set number of passengres to 0
        }
    }//end function to unload passengers 

    // Function to apply brakes -used help from AI for this I had trouble making logic for this part 
    void applyBrakes() {
        int firstDigit = 0;
        int tempSpeed = speed;
        while (int tempSpeed = 0) {
            firstDigit = tempSpeed % 10;
            tempSpeed /= 10;
        }
        if (firstDigit != 0) {
            speed -= firstDigit;
        }
    }  
};//end class Roller Coaster 

int main() {
  cout<<"Emman Abrar Ali 23k0051"<<endl;
    // Create roller coasters using both constructors 
    RollerCoaster rc1; //details are already added prior to main function
    RollerCoaster rc2("Ride To Hell!", 800, 100, 350, 20);

    // Display the details of the roller coasters
    cout << "Roller Coaster 1: " << endl;
    cout << "Name: " << rc1.getName() << endl;
    cout << "Height: " << rc1.getHeight() << endl;
    cout << "Length: " << rc1.getLength() << endl;
    cout << "Speed: " << rc1.getSpeed() << endl;
    cout << "People allowed at a time: " << rc1.getCapacity() << endl;
    cout << "Number of riders: " << rc1.getNumOfRiders() << endl;
    cout << "Ride in progress: " << rc1.getRideInProgress() << endl;

    cout << "\nRoller Coaster 2: " << endl;
    cout << "Name: " << rc2.getName() << endl;
    cout << "Height: " << rc2.getHeight() << endl;
    cout << "Length: " << rc2.getLength() << endl;
    cout << "Speed: " << rc2.getSpeed() << endl;
    cout << "People allowed at a time: " << rc2.getCapacity() << endl;
    cout << "Number of riders: " << rc2.getNumOfRiders() << endl;
    cout << "Ride in progress: " << rc2.getRideInProgress() << endl;

    return 0;
}//end main function 

