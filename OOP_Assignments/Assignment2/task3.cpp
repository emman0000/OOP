//Programmer Emman Abrar Ali 23k0051
//Daraz Loyalty Points Task 3
#include<iostream>
#include<string>
using namespace std;

class DarazPersonData {
private:
    string lastname; string firstname; string address; string city; string state; string zip; string phone;

public:
    DarazPersonData(string lname, string fname, string add, string c, string s, string z)
        : lastname(lname), firstname(fname), address(add), city(c), state(s), zip(z) {} //end constrcutor

    // Getters
    string getLastName() const { return lastname; }
    string getFirstName() const { return firstname; }
    string getAddress() const { return address; }
    string getCity() const { return city; }
    string getState() const { return state; }
    string getZip() const { return zip; }
    string getPhone() const { return phone; }

    // Setters
    void setLastName(string lname) { lastname = lname; }
    void setFirstName(string fname) { firstname = fname; }
    void setAddress(string add) { address = add; }
    void setCity(string c) { city = c; }
    void setState(string s) { state = s; }
    void setZip(string z) { zip = z; }
    void setPhone(string p) { phone = p; }
};//end class DarazPersonData

class DarazCustomerData {
private:
    int customerNumber;
    int loyaltyPoints;

public:
    DarazCustomerData(int customerNum, int points) : customerNumber(customerNum), loyaltyPoints(points) {}//end constrcutor

    // Getters
    int getCustomerNumber() const { return customerNumber; }
    int getLoyaltyPoints() const { return loyaltyPoints; }

    // Setters
    void setCustomerNumber(int num) { customerNumber = num; }
    void setLoyaltyPoints(int points) { loyaltyPoints = points; }
};//end class DarazCustomerData

class DarazLoyaltyProgram {
public:
    void AddLoyaltyPoints(DarazCustomerData& customer, int points) {
        customer.setLoyaltyPoints(customer.getLoyaltyPoints() + points);
    }//end function to add points

    void redeemLoyaltyPoints(DarazCustomerData& customer, int points) {
        customer.setLoyaltyPoints(customer.getLoyaltyPoints() - points);
    }//end function to redeem points

    void displayCustomerDetails(DarazPersonData& person, DarazCustomerData& customer) {
        cout << "Customer Details:" << endl;
        cout << "Name: " << person.getFirstName() << " " << person.getLastName() << endl;
        cout << "Address: " << person.getAddress() << ", " << person.getCity() << ", " << person.getState() << " " << person.getZip() << endl;
        cout << "Phone: " << person.getPhone() << endl;
        cout << "Customer Number: " << customer.getCustomerNumber() << endl;
        cout << "Loyalty Points: " << customer.getLoyaltyPoints() << endl;
          cout<<"______________________________________________\n";
    }//end function
}; //end class 

int main() {
    cout<<"Programmer Emman Abrar Ali 23k0051\n\n***********************\n";
    cout<<"DARAZ CUSTOMER LOYALTY SCHEME:\n";
    DarazPersonData person1("Muhammad", "Sabeeh", "Gulshan", "Karachi", "KHI", "032576899");
    DarazPersonData person2("Rumaisa", "Kashif", "NHS Phase 2", "Karachi", "KHI", "034599729");
    //Loyalty Points 
    DarazCustomerData customer1(1, 190);
    DarazCustomerData customer2(2, 230);
    DarazLoyaltyProgram loyaltyProgram;
    // Add some loyalty points
    loyaltyProgram.AddLoyaltyPoints(customer1, 50);
    loyaltyProgram.displayCustomerDetails(person1, customer1);

    // Redeem some loyalty points
    loyaltyProgram.redeemLoyaltyPoints(customer2, 30);
    loyaltyProgram.displayCustomerDetails(person2, customer2);

    return 0;
}//end main
