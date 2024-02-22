//Programmer Emman Al-23k0051 Lab04 task1
#include <string>
#include <iostream>
using namespace std;

class Book {
    string name;
    string author;
    int ISBN_number;
    int page_count;
    int pages_read;

public:
    // Default constructor
    Book() {
        name = "";
        author = "";
        ISBN_number = 0;
        page_count = 0;
        pages_read = 0;
    }

    // Parameterized constructor
    Book(string n, string a, int i, int pc) {
        name = n;
        author = a;
        ISBN_number = i;
        page_count = pc;
        pages_read = 0;
    }

    // Method to track pages read
    void pagetracker(int pages) {
        pages_read += pages;
        if (pages_read >= page_count) {
            cout << "\nYou have finished the book" << endl;
        } else {
            cout << "\nYou have yet to finish this book" << endl;
        }
    }

    // Method to display book information
    void display() {
        cout << "\n\nName of the Book is: " << name << endl;
        cout << "Name of the author is: " << author << endl;
        cout << "ISBN Number: " << ISBN_number << endl;
        cout << "Total number of pages in the book: "<< page_count << endl;
    }
};

int main() {
    Book b1;
    b1.display();

    Book b2("Divergent", "Some Sarah Girl", 876543245678 , 500);
    b2.display();
    b2.pagetracker(200);
    b2.pagetracker(100);
    b2.pagetracker(200);

    return 0;
}//end main
