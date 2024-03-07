// Task 2 Lab05 Emman Abrar Ali 23k0051
#include <iostream>
using namespace std;

class LoanHelper{
     float amount;  int numOfmonths; const float rate; 

public:
LoanHelper(float amount, float rate, int numOfmonths): amount(amount), numOfmonths(numOfmonths), rate(rate) {}

//method to calculate the loan
float calculateLoan(){
float payment= amount/numOfmonths*rate; 
   cout<<"You have to pay: "<< payment <<" every month for: "<<numOfmonths<<" months."<<endl;
   return payment;
}//end function 

};//end class loanhelper

int main() {
cout<<"Emmna Abrar Ali 23k0051"<<endl;
//first loan object
float amount=2000;
int numOfmonths=12;
float rate=0.5;

LoanHelper loan(amount, rate, numOfmonths); loan.calculateLoan();
//second loan object 
float amount2=10000;
int numOfmonths2=12;
float rate2=0.3;

LoanHelper loan2(amount2, rate2, numOfmonths2); loan2.calculateLoan();

    return 0;
}//end main 

