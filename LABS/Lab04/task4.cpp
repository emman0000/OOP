
//Programmer Emman Abrar Ali 23k0051 Lab04 Task3

#include<iostream>
#include<string>
using namespace std;
//Create a class called Weekdays 
class WeekDays {
private:
    string Days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}; //string array because how else will you store words
    int CurrentDay; //duh

public:
    // Default constructor usually no need to make this since program will run one anyway
    WeekDays() {
        CurrentDay = 0; // Default current day is Sunday
    }//end of default constructor 

    // Parameterised constructor
    WeekDays(int n) {
        CurrentDay = n % 7; // we use %7 so that the days stay within the loop 
    }//end of PC
//Making a getter function for Current Day since it is a private data member and we want to be able to make  changes and use it.
    string getCurrentDay() {
        return Days[CurrentDay];
    }//end of function 
    string getNextDay() {
        return Days[(CurrentDay + 1) % 7]; 
    } string getPreviousDay() {
        return Days[(CurrentDay + 6) % 7]; 
    }
    string getNthDayFromToday(int n) {
        return Days[(CurrentDay + n) % 7];
    }
    void setCurrentDay(int n) {
        CurrentDay = n % 7; // Ensure CurrentDay stays within the loop of 7 days otherwise they will be out of bounds
    }
};

int main() {
    int CD;
    cout << "SUN=0, MON=1, TUE=2, WED=3, THU=4, FRI=5, SAT=6" << endl;
    cout << "Enter a number for a day of the week: ";
    cin >> CD;

    WeekDays W(CD);

    cout << "The current day is " << W.getCurrentDay() << endl;
    cout << "The next day is " << W.getNextDay() << endl;
    cout << "The previous day was " << W.getPreviousDay() << endl;

    int n;
    cout << "Enter a number n to find the nth day from today: ";
    cin >> n;
    cout << "The nth day from today will be " << W.getNthDayFromToday(n) << endl;

    return 0;
}//end main 
