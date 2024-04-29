//Programmer Emman Ali 23k0051 task 1 
#include <iostream>
#include <string>
using namespace std;

class Logo {
  string design;
public:
    Logo(const string& design) : design(design) {}
    friend class Platform; //declaring friend class here helps use all the functions n the calss 
};//end class

class Platform {
    string platformName; Logo logo;

public:
    Platform(const string& platformName, const string& design) : platformName(platformName), logo(design) {}

    void modifyLogo(const string& newDesign) {
        logo.design = newDesign;
    }//end function

    void showDetails() const {
        cout << "Platform Name: " << platformName << endl;
        cout << "Design: " << logo.design << endl;
    }//end function
};//end class

class Server {
    string category; int storage;

public:
    Server(const string& category, int storage) : category(category), storage(storage) {}

    void displayInfo() const {
        cout << "Server Category: " << category << endl;
        cout << "Storage: " << storage << "GB" << endl;
    }//end functionk
};//end class 

int main() {
    Platform socialMedia("Social Media", "Blue Bird");
    socialMedia.showDetails();
    cout << "\n\n";
    socialMedia.modifyLogo("Dogecoin");
    socialMedia.showDetails();

    return 0;
}//end main
