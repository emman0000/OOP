//School student program task 4
//Programmer Emman Abrar Ali 23k0051
#include<iostream>
#include<string>
using namespace std;

class Person{
string name; int age; 
public:
Person(string n, int a): name(n), age(a){}//end constructor
string getname()const{return name;}
int getage()const{return age;}
};//base class Person ends

class Student: public Person{
string StudentId; int gradelevel;
public:
Student(string id, int gl, string n, int a): Person(n,a), StudentId(id), gradelevel(gl){}//end constructor
string getId()const{return StudentId;}
int getgradelevel()const{return gradelevel;}
};//end class student

class Teacher: public Person{
int roomnumber;
public:
Teacher(int rn, string n, int a): Person(n,a), roomnumber(rn){}//end constructor
int getroomnumber()const{return roomnumber;}
};//end class teacher

class GradStudent: public Student, public Teacher{
string job = "Teacher's Assistant";
public:
GradStudent(string id, int gl, string n, int a, int rn): Student(id,gl) , Teacher(rn,n,a){}//end constructor

void display(){
  cout<<"Name: "<<Person::getname()<<endl; cout<<"Age: "<<Person::getage()<<endl; cout<<"Student ID: "<<getId()<<endl;
  cout<< "Grade Level: "<<getgradelevel()<<endl; cout<< "Room Number: "<<getroomnumber()<<endl; cout<<" "<<job<<endl;
}//end function

};//end class grad student
int main(){
GradStudent g1("5853488", 6, "Emman Abrar Ali", 23, 324);
g1.display();


 return 0; 
}//end main 
