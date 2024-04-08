#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Base class Shape
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void displayProperties() const = 0;
    virtual ~Shape() {} 
};

// Circle class derived from Shape
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    void displayProperties() const override {
        cout << "Properties of the Circle:" << endl;
        cout << "- Area: " << area() << endl;
        cout << "- Perimeter: " << perimeter() << endl;
        cout << "- Diameter: " << 2 * radius << endl;
    }
};

// Rectangle class derived from Shape
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double get_width() const { return width; }

    double area() const override {
        return length * width;
    }

    double perimeter() const override {
        return 2 * (length + width);
    }

    void displayProperties() const override {
        cout << "Properties of the Rectangle:" << endl;
        cout << "- Area: " << area() << endl;
        cout << "- Perimeter: " << perimeter() << endl;
        cout << "- Diagonal: " << sqrt(length * length + width * width) << endl;
    }
};

// Square class derived from Rectangle
class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}

    void displayProperties() const override {
        cout << "Properties of the Square:" << endl;
        cout << "- Area: " << area() << endl;
        cout << "- Perimeter: " << perimeter() << endl;
        cout << "- Diagonal: " << sqrt(2) * this->get_width() << endl;
    }
};

// Triangle class derived from Shape
class Triangle : public Shape {
private:
    double side1, side2, side3;
public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    double area() const override {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double perimeter() const override {
        return side1 + side2 + side3;
    }

    void displayProperties() const override {
        cout << "Properties of the Triangle:" << endl;
        cout << "- Area: " << area() << endl;
        cout << "- Perimeter: " << perimeter() << endl;
    }
};

// EquilateralTriangle class derived from Triangle
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side) : Triangle(side, side, side) {}

    void displayProperties() const override {
        cout << "Properties of the Equilateral Triangle:" << endl;
        cout << "- Area: " << area() << endl;
        cout << "- Perimeter: " << perimeter() << endl;
    }
};

int main() {
    string choice;
    Shape* shapePtr = nullptr;
    cout << "Welcome to the Geometry Competition!" << endl;

    do {
        cout << "\nPlease select a shape:" << endl;
        cout << "1. Circle" << endl;
        cout << "2. Rectangle" << endl;
        cout << "3. Square" << endl;
        cout << "4. Triangle" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "1") {
            double radius;
            cout << "Enter the radius of the circle: ";
            cin >> radius;
            shapePtr = new Circle(radius);
        } else if (choice == "2") {
            double length, width;
            cout << "Enter the length of the rectangle: ";
            cin >> length;
            cout << "Enter the width of the rectangle: ";
            cin >> width;
            shapePtr = new Rectangle(length, width);
        } else if (choice == "3") {
            double side;
            cout << "Enter the side length of the square: ";
            cin >> side;
            shapePtr = new Square(side);
        } else if (choice == "4") {
            double side1, side2, side3;
            cout << "Enter the lengths of the three sides of the triangle: ";
            cin >> side1 >> side2 >> side3;
            shapePtr = new Triangle(side1, side2, side3);
        } else {
            cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
            continue;
        }

        shapePtr->displayProperties();

        delete shapePtr;

        cout << "\nDo you want to calculate properties for another shape? (yes/no): ";
        cin >> choice;
    } while (choice == "yes");

    cout << "Thank you for using the Geometry Competition Calculator!" << endl;

    return 0;
}
