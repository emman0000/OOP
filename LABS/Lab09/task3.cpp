//Programmer Emman Ali 23k0051
//Lab 9 Task 3

#include<iostream>
#include<string>
using namespace std;

class Shape{
public:
virtual double Area() const =0; 
virtual ~Shape(){}
double operator+(const Shape& other){
  return this->Area () + other.Area();
}
};//end class shape 

class Rectangle : public Shape{
double length; double width;
public:
Rectangle(double l, double w):length(l), width(w){}
double Area() const override{
  return length * width;
}
};//end class

class Circle: public Shape{
double radius;
public: 
Circle(double r):radius(r){}
double Area() const override{
  return 3.14 * radius * radius;
}//end 
};///end class 


int main (){
Rectangle shape1(4,8);
  Circle  shape2(7);
  cout<<"The total sum of the two areas is: "<<endl;
  cout<<shape1+shape2;
  return 0;

}//end main 
