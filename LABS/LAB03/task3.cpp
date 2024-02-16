//Programo Emman Ali-23k0051 LAB03-Task3
#include <string>
#include <iostream>
using namespace std;

class Calendar {
    string tasks[12][30]; // 2d array :)
    int year;
public:
    Calendar(int y) {
        year = y;
    }
    void addTask(const string& details, int day, int month) {
        if (day >= 1 && day <= 30 && month >= 1 && month <= 12) {
            tasks[month - 1][day - 1] = details;
            cout << "Added! to: " << day << "/" << month << "/" << year << endl;
        } else {
            cout << "Invalid date" << endl;
        }
    } // end function

    void displayTasks() const {
        cout << "Tasks for " << year << ":" << endl;
        for (int month = 0; month < 12; month++) {
            for (int day = 0; day < 30; day++) {
                if (!tasks[month][day].empty()) {
                    cout << day + 1 << "/" << month + 1 << "/" << year << ": " << tasks[month][day] << endl;
                } // end if
            } // end second loop
        } // end first loop
    } // end function

    void removeTask(int day, int month, int year) {
        if (day >= 1 && day <= 30 && month >= 1 && month <= 12) {
            tasks[month - 1][day - 1].clear();
            cout << "Removed from " << day << "/" << month << "/" << year << endl;
        } else {
            cout << "Invalid date" << endl;
        } // end else
    } // end function

}; // end class

int main() {
    int year, month, date, Year;
    cout << "Enter what the current year is: ";
    cin >> Year;
    Calendar cal(Year);
    cal.addTask("Beach Trip", 20, 3);
    cal.addTask("Meeting with boss", 10, 3);
    cal.addTask("Dentist appointment", 15, 3);
    cal.addTask("Party", 25, 3);
    cal.addTask("Report meeting", 30, 3);
    cal.addTask("Birthday party", 5, 4);

    cout << "All tasks that were added are:" << endl;
    cal.displayTasks();
    cout << "Removing a task from the calendar. Enter date with spaces and no / sign: ";
    cin >> date >> month >> year;
    cal.removeTask(date, month, year);
    cout << "Updated tasks are: " << endl;
    cal.displayTasks();
    return 0;
} // end main
