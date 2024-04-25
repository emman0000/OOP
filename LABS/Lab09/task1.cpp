#include <iostream>
#include <string>
using namespace std;
class Logo {

    string logo;

public:
    Logo(const string& logo) : logo(logo) {}

    friend class Platform;
};

class Platform {

    string name;
    Logo logo;

public:
    Platform(const string& name, const string& logo) : name(name), logo(logo) {}

    void changeLogo(const string& newLogo) {
        logo.logo = newLogo;
    }

    void display() const {
        cout << "Platform: " << name << endl;
        cout << "Logo: " << logo.logo << endl;
    }
};

class Server {

    string type;
    int capacity;

public:
    Server(const std::string& type, int capacity) : type(type), capacity(capacity) {}

    void display() const {
        cout << "Server Type: " << type << endl;
        cout << "Capacity: " << capacity << "GB" << endl;
    }
};

int main() {
    Platform twitter("Twitter", "Blue Bird");
    twitter.display();

    cout << std::endl;

    // Changing logo to Dogecoin
    twitter.changeLogo("Dogecoin");
    twitter.display();

    return 0;
}//end main 

