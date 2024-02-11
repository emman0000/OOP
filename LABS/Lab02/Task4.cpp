//Programmer Emman ALi-23k0051 LAB02 Task 4 
#include <iostream>
#include<string>
using namespace std;
struct Register{ //structure for Register consists of only two variables, courseID could also be declared as a string data type that way I can take 0s but here I have kept it simple.
  int courseID; string courseName; 
}; //end struct

struct Student: public Register { //struct student inherits the members of the struct register
  int StudentId;  string FirstName; string LastName; string CellNo; string email;
};
//main function starts 
int main() {
 Student students[5]; //array to store memory 
  for(int i=0; i<5; i++){ //pretty straightforward loop that takes iput for all 5 students categorically
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
  for(int i=0; i<5; i++){ //another loop to display the register
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
  
    

