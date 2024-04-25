//Programmer Emman Ali 23k0051
//Lab 09 Task 2

#include<iostream>
#include<string>
using namespace std;

class Number{
int number;
public: Number(int n):number(n){}//end constructor
int  getNumber(){return number;}//end function
void setNumber(int n){number=n;}//end function

//Overloading prefix decrement operator --
Number operator--(){
  number/=4; return *this; //if it is prefix then the number is x by  4
}//end function

Number operator--(int){
  Number temp = *this;
  number/=4; return temp;
  //if the number is post it is / by 4
}//end function

//display
void display(){
  cout<<" "<<number<<endl;
}//end 

};//end class Number 

int main(){
Number n(28); 
cout<<"OG number: "; n.display();
--n; 
  cout<<"Prefix After effects: ";n.display();
n--;
cout<<"Postfix After effects: ";n.display();


 return 0; 
}//end main 
