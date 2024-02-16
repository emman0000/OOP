// Programmer: Emman Ali (ID: 23k0051)
// LAB03-Task5
#include <string> 
#include <iostream>
#include <vector>
// declaring class
class Stationary {
    vector<string> items;
    vector<int> prices;
// declaring public data members
public:
    // Function to add items along with their prices
    void addItem(const string& itemName, int price) {
        items.push_back(itemName);
        prices.push_back(price);
    }//end function

    // Function to modify the price of an item
    void modifyPrice(int index, int newPrice) {
        if (index >= 0 && index < prices.size()) {
            prices[index] = newPrice;
        } else {
            cout << "Error: Invalid index" << endl;
        }
    }//end function 

    // Function to display the items and their prices
    void displayItems() const {
        cout << "Stationary Items:" << endl;
        for (size_t i = 0; i < items.size(); i++) {
            cout << items[i] << ": $" << prices[i] << endl;
        }
    }//end functio

    // Function to produce receipt
    void produceReceipt(const vector<int>& itemIndices, const vector<int>& quantities) const {
        int total = 0;
        cout << "Receipt: \n";
        for (size_t i = 0; i < itemIndices.size(); i++) {
            int index = itemIndices[i];
            if (index >= 0 && index < prices.size()) {
                cout << quantities[i] << " x " << items[index] << ": $" << (prices[index] * quantities[i]) << endl;
                total += (prices[index] * quantities[i]);
            }
        }
        cout << "Total: $" << total << endl;
    }//end function
}; // end class Stationary

int main (){
    Stationary shop; int choice; string itemname; int itemprice; int index; int newprice; vector<int>itemindex ; vector<int>quantities; int quantity;
    do{
        cout<<"\nStationary Shop Menu\n"; cout<<"1.Add\n";cout<<"2.Modify\n";cout<<"3.Display\n";cout<<"4.Receipt\n";cout<<"5.Close\n"; cout<<"Choose:"; cin>> choice;

   switch (choice){
       case 1: cout<<"ENTER THE NAME OF THE ITEM:" ;cin.ignore(); getline(cin,itemname); cout<<"ENTER THE PRICE:"; cin>>itemprice;shop.addItem(itemname,itemprice); break;
       case 2:  shop.displayItems(); cout << "ENTER INDEX: ";   cin >> index; cout << "ENTER THE NEW PRICE: $";cin >> newprice; shop.modifyPrice(index - 1, newprice); break;

        case 3: shop.displayItems();break;

        case 4: int n; cout<<"ENTER THE NUMBER OF ITEMS: "; cin >> n ; for(int i=0; i<n; i++){ cout<<"ENTER ITEM INDEX "<< i+1<<":";cin >>index;
        cout<<"Enter the quantity of the item "<<i+1<<":";cin>>quantity;
        itemindex.push_back(index-1); quantities.push_back(quantity);}
        shop.produceReceipt(itemindex,quantities); break;

        case 5: cout<<"-------Closing system Bye!\n\n------";
        break;
        default: cout<<"Error Enter a valid choice please\n";}
    }while(choice !=5);

       return 0;         
}//end main 
