//Programmer Emman ALi-23k0051 LAB02 Task 4 
#include <iostream>
#include<string>
using namespace std;
struct Register{
  int courseID; string courseName; 
};

struct Student: public Register {
  int StudentId;  string FirstName; string LastName; string CellNo; string email;
};

int main() {
 Student students[5];
  for(int i=0; i<5; i++){
cout<< "Enter all the details for Student Number:" <<i+1<<endl;
    cout<<"Enter the course Id for this Student:";  cin >> students[i].courseID;
    cin.ignore();
    cout<<"Enter the course Name for this Student:"; 
     getline(cin, students[i].courseName);
    cout<<"Enter the First Name for this Student:"; 
     getline(cin, students[i].FirstName);
    cout<<"Enter the Last Name for this Student:";
     getline(cin, students[i].LastName);
    cout<<"Enter the Cell Number for this Student:"; 
    getline(cin,students[i].CellNo);
    cout<<"Enter the email for this Student:";
     getline(cin, students[i].email);
  }//end the loop for input 
  //Diplay the details of the all students
  for(int i=0; i<5; i++){
    cout<<"Student Number:"<<i+1<<endl;
    cout<<"Course ID:"<<students[i].courseID<<endl;
    cout<<"Course Name:"<<students[i].courseName<<endl;
    cout<<"First Name:"<<students[i].FirstName<<endl;
    cout<< "Last Name:"<<students[i].LastName<<endl;
    cout<< "Cell Number:"<<students[i].CellNo<<endl;
    cout<< "Email:"<<students[i].email<<endl; 
  }//end the for loop for display
   return 0;
  }//end main
  
    

