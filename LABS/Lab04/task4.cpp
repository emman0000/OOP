//Programmer Emman Abrar Ali 23k0051 Lab04 Task4
#include <string>
#include <iostream>
#include <initializer_list>

using namespace std;

class Office {
    string Location;
    int SeatingCapacity;
    string Furniture[3];

public:
    // Parameterized constructor
    Office(string location = " ", int SeatingCap = 0, initializer_list<string> furniture = {" ", " ", " "})
        : Location(location), SeatingCapacity(SeatingCap) {
        int i = 0;
        for (const auto& item : furniture) {
            Furniture[i++] = item;
            if (i >= 3) break;
        }
    }

    // Function to display office details
    void display() {
        cout << "Location of the Office is: " << Location << endl;
        cout << "The Seating Capacity for the Office is: " << SeatingCapacity << endl;
        cout << "The Furniture: ";
        for (int i = 0; i < 3; i++) {
            cout << Furniture[i] << " ";
        }
        cout << endl;
    }
}; // End of class

int main() {
    Office PandG("Clifton Block 3", 60, {"Chairs", "Tables", "Shelves"});
    Office Unilever("Avari Towers", 90, {"Cubicle", "Desks", "Chairs"});
    Office GSKPharma("Ocean Front Clifton", 70, {"Chairs", "Tables", "Boards"});
    Office CocaCola; // Leave this for the default constructor 

    cout << "P and G: " << endl;
    PandG.display();
    cout << endl;
    cout << "Unilever:" << endl;
    Unilever.display();
    cout << endl;
    cout << "GSKPharma:" << endl;
    GSKPharma.display();
    cout << endl;
    cout << "The Coca Cola Company:" << endl;
    CocaCola.display();
    cout << endl;

    return 0;
} // End main
