
//Programmer Emman Ali=23k0051 LAB02 Task 5
#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 50;
// Structure 
struct Product {
    string productName;int price; int quantity; int productId;
};
// Class 
class ProductManagementSystem {
private: Product products[MAX_SIZE]; int numProducts;
public:
    ProductManagementSystem() : numProducts(0) {} //constructor

    // Function to add a new product
    void addProduct(const string& name, int price, int quantity, int productId) {
        if (numProducts < MAX_SIZE) {
products[numProducts].productName = name ; products[numProducts].price = price; products[numProducts].quantity = quantity;products[numProducts].productId = productId;
            numProducts++;
            cout << "Inventory has been updated" << endl;
        } else {
            cout << "Inventory is full" << endl;
        }//end else
    }//end function
    // Function to display product information
    void displayProducts(int productId) {
        bool exists = false;
        for (int i = 0; i < numProducts; i++) {
            if (products[i].productId == productId) {
                exists = true;
 cout << "Product ID:" << products[i].productId << endl; cout << "Product Name:" << products[i].productName << endl;cout << "Product Price:" << products[i].price << endl; cout << "Quantity Present in Inventory:" << products[i].quantity << endl;}//end if      
        }//end loop
        if (!exists) {
            cout << "No product with the given product ID is present in the inventory." << endl;
        }//end if 
    }//end function
    // Function to update product information
    void updateProduct(int productId, int newQuantity, int newPrice) {
        bool exists = false;
        for (int i = 0; i < numProducts; i++) {
            if (products[i].productId == productId) {
                exists = true;
                products[i].price = newPrice;
                products[i].quantity = newQuantity;
                cout << "Inventory has been updated" << endl;
            }//end  if 
        } //end loop
        if (!exists) {
            cout << "No product with the given product ID is present in the inventory." << endl;
        }
    }
};

int main() {
    ProductManagementSystem P;
    int choice;
    do {
        cout << "1. Add a new product" << endl;
        cout << "2. Display Inventory" << endl;
        cout << "3. Update Inventory" << endl;
        cout << "4. Exit" << endl;
        cout << "What would you like to do pick a number: ";
        cin >> choice;

 switch (choice) {
case 1: {
int productId, quantity, price;        
string name;
cout << "Enter the Product Id:"; cin >> productId;
cout << "Enter the quantity : "; cin >> quantity;
cout << "Enter the price  : "; cin >> price;
cout << "Enter the name of the product: ";  cin.ignore();getline(cin, name);
 P.addProduct(name, price, quantity, productId);
 break;}

case 2: {
int productId;
cout << "Enter an Id to display product details: ";
cin >> productId;
 P.displayProducts(productId);
break;}

 case 3: {
int productId, newQuantity, newPrice;
cout << "Enter Product ID to update information: ";
 cin >> productId;
cout << "Enter the new quantity: ";
cin >> newQuantity;
cout << "Enter the new price: ";
cin >> newPrice;
P.updateProduct(productId, newQuantity, newPrice);
 break;}

 case 4: {
cout << "Exiting the program." << endl;
 break;}

 default: cout << "Error choice not valid. Please try again." << endl;}//end switch
}/* end while*/ while (choice != 4);  return 0;
} //end main 
