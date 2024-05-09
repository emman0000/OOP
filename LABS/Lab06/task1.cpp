//Banking system task 1 
//Programmer Emman Abrar Ali 23k0051

#include <iostream>
#include <string>
using namespace std;  
class BankAccount{
int accountId; double balance; int* transactionHistory; int numTransactions;
public:
//construtor
BankAccount(int accId, double bl, int* th, int n): accountId(accId), balance(bl), numTransactions(n){
 transactionHistory = new int[n]; 
  for(int i=0; i<n; i++){
    transactionHistory[i] = th[i];
  }//end of for loop
}//end of constructor 

//copy constructor
BankAccount(const BankAccount& other): accountId(other.accountId), balance(other.balance), numTransactions(other.numTransactions){
  transactionHistory = new int [numTransactions];
  for(int i=0; i<numTransactions; i++){
    transactionHistory [i]= other.transactionHistory[i];
  }//end for loop
}//end copy construtor

//Destructor
~BankAccount(){delete[]transactionHistory;}//end of destructor

//getters
int getaccountId()const{return accountId;}
double getbalance()const{return balance;}
int getnumTransactions()const{return numTransactions;}

//function display
void display(){
  cout<<"Account ID: "<<accountId<<endl;
  cout<<"Balance: "<<balance<<endl;
  cout<<"Number of transactions: "<<numTransactions<<endl;
  cout<<"Transaction history: ";
  for(int i=0; i<numTransactions; i++){
    cout<<transactionHistory[i]<<" ";
  }//end of for loop
  cout<<endl;
}//end of function

void updateTransactionHistory(int*  newTransaction, int newNumTransactions){ delete[]transactionHistory;
    //deletes
   transactionHistory = new int[newNumTransactions];
  for(int i=0; i<newNumTransactions; i++){
    transactionHistory[i] = newTransaction[i];
  }//end of for loop
    numTransactions = newNumTransactions;
  }//end function to update account details for transaction


};//end of class bank account 

int main(){
int initialTransactions[]={50,100,-30};
int numInitialTransactions =sizeof(initialTransactions)/sizeof(initialTransactions[0]);
  //creating objects of bank account class
  BankAccount account1(1, 1000, nullptr, 0);
  //copy of original account
   BankAccount account2 = account1;
  cout<<"OG account details: "<<endl;
  account1.display();
  cout<<"Copy of OG account: "<<endl;
  account2.display();
  cout<<"\n\n"; cout<<"-------------------";
  cout<<"Updating account..."<<endl;

  int updatedTransaction[]={100, -50};
  int numUpdatedTransactions = sizeof(updatedTransaction)/sizeof(updatedTransaction[0]);
 account1.updateTransactionHistory(updatedTransaction, numUpdatedTransactions); 
  cout<<"Updated account details: "<<endl;
  account1.display();
  


  return 0;
}//end main 
