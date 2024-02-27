//Programmer Emman Abrar Ali Assignment Task2
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//class table
class Table {
    const int capacity;   int seatsoccupied;   bool clean;
public: 
//constructor
    Table(int capacity = 4) : capacity(capacity), seatsoccupied(0), clean(true) {
        if (capacity < 1) {
            cout << "Must be a valid number greater than 1. How can there be less than 1 seat in a table?" << endl;
        }//end if 
    }//end constructor
//function to check if the table is clean and ready for the number of people
    void useTable(int numofpeople) {
        if (clean && numofpeople <= capacity) {
            seatsoccupied = numofpeople; 
            clean = false; 
            cout << "Table is now occupied by " << numofpeople << " people" << endl;
        }//end if
    }//end function
//function for table is being used 
    void havelunch() {
        if (!clean) {
            cout << "Table is in use" << endl; 
            clean = false;
        }
    }//end function
//function to check availability of table
    void leaveTable() {
        cout << "Table is unoccupied" << endl; 
        seatsoccupied = 0; 
    }//end function
//check for cleanliness of table
    void cleanTable() {
        if (seatsoccupied == 0) {
            clean = true; 
            cout << "Table is now clean" << endl;
        }//end if 
    }//end function
//getters
    int getCapacity() const { 
        return capacity;
    }

    bool isClean() const { 
        return clean;
    }

    int getSeatsOccupied() const { 
        return seatsoccupied;
    }
};//end class table


void occupyTable(vector<Table>& tables, int numofpeople) {
    for (Table& table : tables) {
        if (table.getSeatsOccupied() == 0 && numofpeople <= table.getCapacity()) {
            table.useTable(numofpeople);
            return;
        }
    }
    cout << "No table available" << endl;
}//end function

void emptyTable(vector<Table>& tables, int tableNumber) {
    if (tableNumber >= 0 && tableNumber < tables.size()) {
        tables[tableNumber].leaveTable();
    } else {
        cout << "Invalid try again!" << endl;
    }
}//end function 

int main() {
    cout << "Emman Abrar Ali 23k0051" << endl;
    vector<Table> tables = {Table(4), Table(8), Table(6), Table(2), Table(4)};

    occupyTable(tables, 4);
    occupyTable(tables, 8);
    tables[0].cleanTable();
    cout << "Table  is clean: " << (tables[0].isClean() ? "Yes" : "No") << endl;
    tables[0].useTable(2);
    tables[0].useTable(4);
    tables[0].useTable(6);
    cout<< "Table is clean: " << (tables[0].isClean() ? "Yes" : "No") <<endl;
    emptyTable(tables, 1);

    return 0; 
}//end main

