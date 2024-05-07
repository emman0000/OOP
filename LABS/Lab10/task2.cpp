//Programmer Emman Ali 23k0051 Lab 10 task 2 
#include <iostream>
#include <string>
using namespace std;

// Base class
class Account {
public:
    Account(const string& accountNumber) : accountNumber(accountNumber) {}
    string accountNumber;
    double balance;

    // Pure
    virtual double deposit(double amount) = 0;
    virtual double withdraw(double amount) = 0;
    virtual float calcInterest() = 0;

    // Getter 
    string getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
};//end main class 

// Derived 
class SavingsAccount : public Account {
    double interestRate;

public:
    SavingsAccount(const string& accountNumber, double ir) : Account(accountNumber), interestRate(ir) {}

    double deposit(double amount) override {
        balance += amount;
        cout << "Savings account balance after deposit: " << balance << endl;
        return balance;
    }//end 

    double withdraw(double amount) override {
        if (balance - amount >= 0) {
            balance -= amount;
            cout << "Savings account balance after withdrawal: " << balance << endl;
        } else {
            cout << "Error: Insufficient funds for withdrawal." << endl;
        }
        return balance;
    }//end 

    float calcInterest() override {
        double interest = balance * (interestRate / 100);
        balance += interest; 
        cout << "Savings account balance after interest: " << balance << endl;
        return interest;
    }
};//end class 

// Derived 
class CurrentAccount : public Account {
    double overdraftLimit;

public:
    CurrentAccount(const string& accountNumber, double odl) : Account(accountNumber), overdraftLimit(odl) {}

    double deposit(double amount) override {
        balance += amount;
        cout << "Current account balance after deposit: " << balance << endl;
        return balance;
    }//end 

    double withdraw(double amount) override {
        if (balance - amount >= -overdraftLimit) {
            balance -= amount;
            cout << "Current account balance after withdrawal: " << balance << endl;
        } else {
            cout << "Error: Withdrawal exceeds overdraft limit." << endl;
        }
        return balance;
    }//end 

    float calcInterest() override {
        return 0.1f; 
    }
};//end class 

int main() {
    SavingsAccount s("REORO34", 5.0);
    CurrentAccount c("RFJJ4395", 1000.0);

    s.deposit(4000.0);
    c.deposit(6000.0);
    s.deposit(5500.0);
    s.withdraw(1000.0);
    s.calcInterest();
    cout<<"------------------------------------------------------"<<endl;
    cout << "Savings account balance: " << s.getBalance() << endl;
    cout << "Current account balance: " << c.getBalance() << endl;

    return 0;
}//end main 
