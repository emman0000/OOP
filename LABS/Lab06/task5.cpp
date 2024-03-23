
 //school managment system task 5
//Programmer Emman Abrar Ali 23k0051
#include <iostream>
#include <string>
using namespace std;

class Course {
    string courseId;
    string courseName;
    int creditHours;
public:
    Course(string id, string name, int c): courseId(id), courseName(name), creditHours(c) {} //end of constructor 

    string getcourseId() const { return courseId; }
    string getcourseName() const { return courseName; }
    int getcredithours() const { return creditHours; }
}; //end of class Course

class Student {
    string StudentId;
    string name;
    int maxcourses;
    Course** courses;
    int numCourses;

public:
    Student(string id, string n, int max): StudentId(id), name(n), maxcourses(max), numCourses(0) {
        courses = new Course*[maxcourses]; 
        for(int i = 0; i < maxcourses; i++) {
            courses[i] = nullptr; //initializing all pointers to null
        }
    } //end constructor

    ~Student() {
        for(int i = 0; i < numCourses; i++) {
            delete courses[i];
        }
        delete [] courses;
    } //end destructor 

    void enroll(Course* course) {
        if(numCourses < maxcourses) {
            courses[numCourses++] = course;
        } else {
            cout << "Cannot enroll into anymore courses." << endl;
        }
    } //end function 

    void drop(Course* course) {
        if(course == nullptr) {
            cout << "Course pointer is null." << endl;
            return;
        }
        for(int i = 0; i < numCourses; i++) {
            if(courses[i] == course) {
                delete courses[i]; // Deallocate memory for the dropped course
                // Move the remaining courses to fill the empty slot
                for(int j = i; j < numCourses - 1; j++) {
                    courses[j] = courses[j + 1];
                }
                numCourses--;
                cout << "Course dropped successfully." << endl;
                return;
            }
        }
        cout << "Course not found in enrolled courses." << endl;
    }

    int getTotalCreditHours() const {
        int totalCredits = 0;
        for(int i = 0; i < numCourses; i++) {
            totalCredits += courses[i]->getcredithours();
        }
        return totalCredits;
    }

    void printEnrolledCourses() const {
        cout << "Enrolled Courses:" << endl;
        for(int i = 0; i < numCourses; i++) {
            cout << "Course Code: " << courses[i]->getcourseId() << ", Name: " << courses[i]->getcourseName() << ", Credit Hours: " << courses[i]->getcredithours() << endl;
        }
    }
}; //end class student 

int main() {
    Course c1("253453", "Computer Science", 3);
    Course c2("25654", "Maths", 3);
    Course c3("123456", "Physics", 4);

    Student s1("23k0051", "Emman Abrar Ali", 3);
    s1.enroll(&c1);
    s1.enroll(&c2);
    s1.printEnrolledCourses();
    cout << "Total Credit Hours: " << s1.getTotalCreditHours() << endl;

    s1.drop(&c1);
    s1.printEnrolledCourses();
    cout << "Total Credit Hours: " << s1.getTotalCreditHours() << endl;

    s1.enroll(&c3);
    s1.printEnrolledCourses();
    cout << "Total Credit Hours: " << s1.getTotalCreditHours() << endl;

    return 0;
}//end main
