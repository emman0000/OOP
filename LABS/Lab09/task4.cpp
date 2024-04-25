
//Programmer Emman Ali 23k0051
//Lab 09 task 4
#include<iostream>
#include<string>
using namespace std;
//using forward declaration in order to use friend class
class PrintClass;

class PerimeterClass{
int length; int breadth;
public:
PerimeterClass(int l, int b):length(l),breadth(b){}
friend class PrintClass;
int calcPerimeter(){return 2*(length+breadth);}
};//end lcass

class PrintClass{
public:
void display(PerimeterClass &p){
  int perimeter=p.calcPerimeter();
  cout<<"The perimeter of the object is: "<<perimeter<<endl;
}
};//end class

int main(){
PerimeterClass pPerimeter(7,9);

  PrintClass pPrint;
  pPrint.display(pPerimeter);

  return 0;
}//end main 
