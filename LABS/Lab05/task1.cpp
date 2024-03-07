//Task01 Lab05 Emman Abrar Ali 23k0051
#include <iostream>
using namespace std;

class Square {
    float sideLength;
    float area;
public:
    static float allareas;

    // Constructors
    Square() : sideLength(0), area(0) {}
    Square(float sl) : sideLength(sl), area(0) {}

    // Function to calculate area
    float calculateArea() {
        area = sideLength * sideLength;
        allareas += area;
        return area;
    }//end function 

    // Accessors 
    float getSideLength() { return sideLength; }
    void setSideLength(float sl) { sideLength = sl; }
    float getArea() { return area; }

    // Static member function to access allareas
    static float getAllAreas() { return allareas; }
};

float Square::allareas = 0; //static variable always initalised outsie the class

int main() {
    Square S1(4);
    Square S2(6);
    Square S3(7);

    S1.calculateArea();
    S2.calculateArea();
    S3.calculateArea();

    cout << "The area of the square 1 is: " << S1.getArea() << endl;
    cout << "The area of the square 2 is: " << S2.getArea() << endl;
    cout << "The area of the square 3 is: " << S3.getArea() << endl;

    // Accessing total area of all squares
    cout << "The total area of all the squares is: " << Square::allareas << endl;

    return 0;
}//end main
