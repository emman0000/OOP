//Task07 Lab05 23k0051 Emman Abrar Ali
#include<iostream>
#include<string>
#include<vector> //using vectors for this helped allocate memory more easily and in a real world scenario it would also be more efficient since space is no longer fixed
using namespace std;
class Fooditems {
string foodname ; int prices;
public:
Fooditems(string foodname, int prices): foodname(foodname), prices(prices){}
//Accessors (getters)
string getFoodname() const { return foodname; }

int getPrices() const { return prices; }
};//end class Food Items

class Menu {
    vector<Fooditems*> items;
public:
    void addItemToMenu(Fooditems* item) {
        items.push_back(item);
        cout << "Item added to menu.\n";
    }//end adding items to the menu function 

void removeItemFromMenu(int index){
  if(index >= 0 && index < items.size()){
  delete items[index];    items.erase(items.begin() + index);
   cout << "Item removed from menu.\n";
   } else {
   cout << "Invalid index, item not found.\n";
   }
  }//end function to remove items from the menu

void displayMenu(){
  cout << "Main Courses:\n"<<"-----------------"<<endl;
  for (int i = 0; i < items.size(); ++i) {
          cout << i+1 << ". " << items[i]->getFoodname() << " ~ PKR-" << items[i]->getPrices() << endl;
      }
      cout<<"-----------------\n"<<endl;
  }//end function to display the menu

//destructor
~Menu() {
for (int i = 0; i < items.size(); ++i) {  delete items[i];}
}//end destructor 
};//end class Menu


class Order {
    vector<Fooditems*> items;
    int totalPayment;
public:
//constructor
    Order(): totalPayment(0) {}

 void addItem(Fooditems* item) {
  items.push_back(item);
  totalPayment += item->getPrices();
  cout << "Item added to order.\n";
    }//end function for adding an item to the order list 
int getTotalPayment() {
        return totalPayment;
    }//end function for payment

    ~Order() {
    for (int i = 0; i < items.size(); ++i) {
    delete items[i];
        }//end for loop
    }//end destructor
};//end class Order

class Payment{
int amount;
public:
Payment (int a):amount(a){}//constructor
int getAmount() const { return amount; }//accessor
};//end class payment



int main (){
cout<<"Emman Abrar Ali 23k0051\n "<<endl;
  Menu restaurantMenu;
  restaurantMenu.addItemToMenu(new Fooditems("Nihari", 500));
  restaurantMenu.addItemToMenu(new Fooditems("Khao Suey", 1000));
  restaurantMenu.addItemToMenu(new Fooditems("Maal Poora", 700));
  restaurantMenu.addItemToMenu(new Fooditems("Gola Ganda", 600));
  restaurantMenu.addItemToMenu(new Fooditems("Kerela Masala", 800));

  restaurantMenu.displayMenu();

  Order customerOrder;
  customerOrder.addItem(new Fooditems("Nihari", 500));
  customerOrder.addItem(new Fooditems("Khao Suey", 1000));
  customerOrder.addItem(new Fooditems("Maal Poora", 700));

  cout << "Total payment:" << customerOrder.getTotalPayment()<<"PKR" << endl;
  Payment customerPayment(customerOrder.getTotalPayment());
  cout << "Customer pays:" << customerPayment.getAmount()<<"PKR" << endl;


 return 0; 
}//end main 
