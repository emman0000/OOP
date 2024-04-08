//Programmer Emman Abrar Ali
#include <iostream>
#include <cmath>
using namespace std;

const float PI = 3.14;

// Abstract base class Shape
class Shape {
public:
    virtual float area() const = 0;
    virtual float perimeter() const = 0;
};//end base class 

//Derived classes from the base class Shape
class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r) : radius(r) {}//end constructor
    float area() const override {
        return PI * radius*radius;
    }//end function
    float perimeter() const override {
        return 2 * PI * radius;
    }//end function
};//end class circle 

class Rectangle : public Shape {
private:
    float length;float width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float area() const override {
        return length * width;
    }//end function
    float perimeter() const override {
        return 2 * (length + width);
    }//end function 
};//end class rectangle 

class Triangle : public Shape {
private:
    float base; float height; float side1; float side2; float side3;
public:
    Triangle(float b, float h, float s1, float s2, float s3) : base(b), height(h), side1(s1), side2(s2), side3(s3) {}//end constructor 
    float area() const override {
        return (base * height) / 2;
    }//end function 
    float perimeter() const override {
        return side1 + side2 + side3;
    }//end function
};//end class Trianlge

int main() {
    Circle circle(7.0);//instance circle 
    Rectangle rectangle(4.0, 8.0);//instance rectangle
    Triangle triangle(3.0, 8.0, 3.0, 4.0, 5.0);//instance triangle
//Assignning all the values for shapes 
    float circleRadius = 7.0;
    float rectangleLength = 4.0;
    float rectangleWidth = 8.0;
    float triangleBase = 3.0;
    float triangleHeight = 8.0;
    float triangleSide1 = 3.0;
    float triangleSide2 = 4.0;
    float triangleSide3 = 5.0;

    cout << "Area of circle with radius " << circleRadius << ": " << circle.area() << endl;
    cout << "Perimeter of circle with radius " << circleRadius << ": " << circle.perimeter() << endl;
     cout<<"___________________________________________________"<<endl;
    cout << "Area of rectangle with length " << rectangleLength << " and width " << rectangleWidth << ": " << rectangle.area() << endl;
    cout << "Perimeter of rectangle with length " << rectangleLength << " and width " << rectangleWidth << ": " << rectangle.perimeter() << endl;
     cout<<"___________________________________________________"<<endl;
    cout << "Area of triangle with base " << triangleBase << " and height " << triangleHeight << ": " << triangle.area() << endl;
    cout << "Perimeter of triangle with sides " << triangleSide1 << ", " << triangleSide2 << ", " << triangleSide3 << ": " << triangle.perimeter() << endl;
     cout<<"____________________________________________________"<<endl;
    return 0;
}//end main
