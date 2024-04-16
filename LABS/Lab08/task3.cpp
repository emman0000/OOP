//Programmer Emman Abrar 23k0051
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string employeeName; string employeeID;
public:
    Employee(string n, string i) : employeeName(n), employeeID(i) {}

    virtual double calculatePay() const {
        return 0.0; 
    }//end 

    virtual void displayDetails() const {
        cout << "Employee ID: " << employeeID << ", Name: " << employeeName;
    }//end function
};//end class

class FullTimeEmployee : public Employee {
 double monthlySalary;
public:
  FullTimeEmployee(int id, const string& name, double salary)
    : Employee(name, to_string(id)), monthlySalary(salary) {}

    double calculatePay() const override {
        return monthlySalary;
    }//end function

    void displayDetails() const override {
        Employee::displayDetails();
        cout << ", Type: Full-time, Monthly Salary: " << monthlySalary << endl;
    }//end function
};//end class

class PartTimeEmployee : public Employee {
double hourlyWage;int hoursWorked;
public:
  PartTimeEmployee(int id, const string& name, double wage, int hours)
    : Employee(name, to_string(id)), hourlyWage(wage), hoursWorked(hours) {}

    double calculatePay() const override {
        return hourlyWage * hoursWorked;
    }//end function

    void displayDetails() const override {
        Employee::displayDetails();
        cout << ", Type: Part-time, Hourly Wage: " << hourlyWage
             << ", Hours Worked: " << hoursWorked << endl;
    }//end function 
};//end class 

int main() {
    FullTimeEmployee fullTimeEmp(151, "Emman ", 5000);
    PartTimeEmployee partTimeEmp(159, "Areeba ", 12, 30);

    cout << "Displaying Details:" << endl;
    fullTimeEmp.displayDetails();
    partTimeEmp.displayDetails();

    cout << "\nCalculating Pay:" << endl;
    cout << "Full-time Employee Pay: $" << fullTimeEmp.calculatePay() << endl;
    cout << "Part-time Employee Pay: $" << partTimeEmp.calculatePay() << endl;

//Here using pointer to refer to static 
    Employee* empPtr = &fullTimeEmp;
    cout << " calculate Full-time Employee Pay: $"
         << empPtr->calculatePay() << endl;

    return 0;
}//end main 
