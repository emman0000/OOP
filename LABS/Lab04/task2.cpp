//Programmer Emman Abrar Ali Lab04 Task2
#include<iostream>
#include<string>
using namespace std;


class Book {
    string name;
    string author;
    int ISBN_number;
    int page_count;
    int pages_read;
public:
// Default constructor
Book() : name(" "), author(" "), ISBN_number(0), page_count(1000), pages_read(0) {}

//setters 
void setName(string n) { name = n; }
void setAuthor(string a) { author = a; }
void setISBN_number(int i) { ISBN_number = i; }
void setPage_count(int pc) { page_count = pc; }

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
  b1.setName("Divergent");
  b1.setAuthor("Some Sarah Girl");
  b1.setISBN_number(87654);
  b1.setPage_count(500);

  b1.display();



    b1.pagetracker(200);
    b1.pagetracker(100);
    b1.pagetracker(200);

    return 0;
}//end main
