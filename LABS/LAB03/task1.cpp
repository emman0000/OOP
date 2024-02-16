//Programmer Emman Ali-23k0051 Lab03-task1
#include <string>
#include <iostream>
using namespace std;

class BoardMarker {
private:
    string brand;
    string shade;
    bool refillable;
    bool inkStatus;

public:
    void setBrand(string b) {
        brand = b;
    }
    string getBrand() {
        return brand;
    }
    void setShade(string s) {
        shade = s;
    }
    string getShade() {
        return shade;
    }
    void setRefillable(bool r) {
        refillable = r;
    }
    bool getRefillable() {
        return refillable;
    }
   void setInkStatus(bool i) {
        inkStatus = i;
    }
    bool getInkStatus() {
        return inkStatus;
    }
    void write() {
        if (inkStatus) {
            cout << "Writing with " << brand << " marker in " << shade << " shade." << endl;
        } else {
            cout << "Cannot write. Ink is depleted." << endl;
        }
    }

    void refill() {
        if (refillable) {
            cout << "Refilling " << brand << " marker." << endl;
            inkStatus = true;
        } else {
            cout << "Cannot refill. Marker is not refillable." << endl;
        }
    }
};

int main() {
    BoardMarker BM;
    BM.setBrand("Example Brand");
    BM.setShade("Black");
    BM.setRefillable(true);
    BM.setInkStatus(true);

    BM.write();
    BM.refill();

    return 0;
}//
