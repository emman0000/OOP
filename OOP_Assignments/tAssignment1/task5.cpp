//Programmer Emman Abrar Ali 23k0051 Assignment Task5
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Class  Restaurant
class Restaurant {
private:
    string restaurantname;
    string restaurantaddress;
    vector<string> menu;
    vector<int> prices;
    vector<string> validcoupons;
    static int coupons_redeemed;

public:
    // Constructor to initialize the Restaurant
    Restaurant(string name, string address, vector<string> menu, vector<int> prices, vector<string> valid_coupons)
        : restaurantname(name), restaurantaddress(address), menu(menu), prices(prices), validcoupons(valid_coupons) {}

    // Function to display the restaurant menu
    void display_menu() const {
        cout << "Restaurant: " << restaurantname << endl;
        cout << "Menu: " << endl;
        for (int i = 0; i < menu.size(); i++) {
            cout << menu[i] << ": PKR " << prices[i] << endl;
        }
    }
//Static methods here because they will remain constant for all instances 
    // Static method to get coupons redeemed count
    static int getCouponsRedeemedCount() {
        return coupons_redeemed;
    }//end 
    // Static method to increment coupons redeemed count
    static void incrementCouponsRedeemed() {
        coupons_redeemed++;
    }//end 
};//end of class Restaurant

// Static member initialization
int Restaurant::coupons_redeemed = 0; //static members are always initialised outside the class because they remain constant throughout the program.

// Class BOGO Coupon
class BOGOCoupon {
private:
    string couponcode;string validfrom;string validtill;string restaurantcode;
//pretty much everything is a string due to alphanumeric values 
public:
    // Constructor coupon initialisation 
    BOGOCoupon(string code, string from, string till, string restaurant)
        : couponcode(code), validfrom(from), validtill(till), restaurantcode(restaurant) {}

    // Function to check if the coupon is valid
    bool valid() const {
        if (validfrom <= validtill) {
            cout << "Coupon is valid" << endl;
            return true;
        } else {
            cout << "This coupon has expired or is not valid" << endl;
            return false;
        }//end else 
    }//end function 

    // Function to redeem the coupon
    void RedeemCoupon(string restaurantname) {
        if (restaurantcode == restaurantname) {
            if (valid()) {
                cout << "Coupon has been redeemed. Applying discount..." << endl;
                Restaurant::incrementCouponsRedeemed();
            }//end if 
        }//end if 
    }//end function 
};//end BOGO class

// Class representing a User
class User {
private:
    string name; int age;string mobile_number;vector<string> coupons_list;
//customer details in class will help track information of coupons 
public:
    // Constructor for  user
    User(string n, int a, string mobile) : name(n), age(a), mobile_number(mobile) {
        cout << "Customer Name: " << name << ", Age: " << age << ", Mobile Number: " << mobile_number << endl;
    }//end of constructor

    // Function to accumulate a coupon
    void accumulate_coupon(string coupon) {
      int count=0;
        coupons_list.push_back(coupon);
      count++; cout<<"You have accumulated "<<count<<" coupons"<<endl;
    }//end function

    // Function to check if the user has a valid coupon for a restaurant
    bool has_valid_coupon(string restaurant_name) {
        for (string coupon : coupons_list) {
            BOGOCoupon bogo(coupon, "", "", "");
            if (bogo.valid()) {
                cout << "User has a valid coupon for " << restaurant_name << endl;
                return true;
            }//end if condition 
        }//end for loop
        cout << "User does not have a valid coupon for " << restaurant_name << endl;
        return false;
    }//end function

    // Function to redeem a coupon
    bool redeem_coupon(string coupon) {
        for (string c : coupons_list) {
            if (c == coupon) {
                BOGOCoupon bogo(c, "", "", "");
                bogo.RedeemCoupon("Food Haven");
                return true;
            }//end if 
        }//end for 
        return false;
    }//end function
};//end of class user 

int main() {
    cout<<"Emman Abrar Ali 23k0051"<<endl;
    // Define restaurants
    Restaurant food_haven("Food Haven", "City Center", {"Sushi", "Pad Thai", "Mango Tango"}, {10, 12, 8}, {"FH-BOGO-12345"});
    Restaurant pixel_bites("Pixel Bites", "Cyber Street", {"Binary Burger", "Quantum Quinoa", "Data Donuts"}, {11, 15, 8}, {"PB-BOGO-67890"});

    // Display menus of both places first
  cout<<"Available Menus for Food Haven and Pixel Bites"<<endl;
    food_haven.display_menu();
    pixel_bites.display_menu();

    // TEST user 
    User user1("Sabeeh", 20, "54350505450");
    user1.accumulate_coupon("FH-BOGO-12345");
    user1.accumulate_coupon("PB-BOGO-67890");
    user1.has_valid_coupon("Food Haven");
    user1.redeem_coupon("FH-BOGO-12345");
    user1.redeem_coupon("PB-BOGO-67890");
    cout << "Total coupons redeemed: " << Restaurant::getCouponsRedeemedCount() << endl;

    //TEST user 2
    User user2("Amna", 19, "9876543210");
    user2.accumulate_coupon("FH-BOGO-553453");
    user2.accumulate_coupon("PB-BOGO-435534");
    user2.has_valid_coupon("Food Haven");
    user2.redeem_coupon("FH-BOGO-553453");
    user2.redeem_coupon("PB-BOGO-435534");
    cout << "Total coupons redeemed: " << Restaurant::getCouponsRedeemedCount() << endl;

    return 0;
}//end main

