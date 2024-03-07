//Task 04 lab05 Emman Abrar Ali 23k0051
#include<string>
#include<iostream>
using namespace std;

class BankAccount{
string accountNumber; string accountHolderName; double balance;
public:
//Parameterised constructor
BankAccount(string Number, string Name, double Balance): accountNumber(Number), accountHolderName(Name), balance(Balance){}
//Member functions 

double DepositAmount(double amount){
balance+=amount;
return balance;
}//end deposit function 

double WihthdrawAmount(double amount){
 balance= balance-amount; 
  return balance;
}//end wihtdraw function 

void display(){
  cout<<"Account Number: "<<accountNumber<<"\n"<<"Account Holder Name: "<<accountHolderName<<"\n"<<"Balance: "<<balance<<endl;
}//end display function
};
int main (){
cout<<"Emman Abrar Ali 23k0051"<<endl;

  BankAccount accounts[3]= {BankAccount("546546", "Emman Abrar Ali", 5000), BankAccount("655778", "Areeba Hasnain",5000),BankAccount("555435", "Amna Asim",5000)};

  for(int i=0; i<3; i++){
    accounts[i].display();
  }//end for loop

  for(int i=0; i<3; i++){
    accounts[i].DepositAmount(500);
  }//end for loop

  for(int i=0; i<3; i++){
    accounts[i].WihthdrawAmount(200);
  }//end for loop
cout<<"\n"<<"-----------------------"<<endl;
cout<<"Updated details for bank accounts: "<<endl;
  for(int i=0; i<3; i++){
    accounts[i].display();
  }//end for loop
}//end main 
