#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string employeeName;
    string employeeID;
public:
    Employee(string n, string i) : employeeName(n), employeeID(i) {}

    virtual double calculatePay() const {
        return 0.0; // Default implementation
    }

    virtual void displayDetails() const {
        cout << "Employee ID: " << employeeID << ", Name: " << employeeName;
    }
};

class FullTimeEmployee : public Employee {
private:
    double monthlySalary;
public:
  FullTimeEmployee(int id, const string& name, double salary)
    : Employee(name, to_string(id)), monthlySalary(salary) {}

    double calculatePay() const override {
        return monthlySalary;
    }

    void displayDetails() const override {
        Employee::displayDetails();
        cout << ", Type: Full-time, Monthly Salary: " << monthlySalary << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourlyWage;
    int hoursWorked;
public:
  PartTimeEmployee(int id, const string& name, double wage, int hours)
    : Employee(name, to_string(id)), hourlyWage(wage), hoursWorked(hours) {}

    double calculatePay() const override {
        return hourlyWage * hoursWorked;
    }

    void displayDetails() const override {
        Employee::displayDetails();
        cout << ", Type: Part-time, Hourly Wage: " << hourlyWage
             << ", Hours Worked: " << hoursWorked << endl;
    }
};

int main() {
    FullTimeEmployee fullTimeEmp(101, "AAA", 5000);
    PartTimeEmployee partTimeEmp(102, "BBB", 15, 40);

    cout << "Displaying Details:" << endl;
    fullTimeEmp.displayDetails();
    partTimeEmp.displayDetails();

    cout << "\nCalculating Pay:" << endl;
    cout << "Full-time Employee Pay: $" << fullTimeEmp.calculatePay() << endl;
    cout << "Part-time Employee Pay: $" << partTimeEmp.calculatePay() << endl;

    // Demonstrate static binding using base class pointer
    Employee* empPtr = &fullTimeEmp;
    cout << "Using base class pointer to calculate Full-time Employee Pay: $"
         << empPtr->calculatePay() << endl;

    return 0;
}//end main 
