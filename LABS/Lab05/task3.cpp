//Task03 Lab05 Emman Abrar Ali 23k0051
#include <iostream>
#include <string>
using namespace std;

class ValidateString {
private:
    string s;

public:
    ValidateString(string s) : s(s) {}

    // Function to check string validity using bool
    bool IsValid() const {
        for (char ch : s) {
              if (ch == ' ')
                continue;
            if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))) {
                return false;
            }
        }
        return true;
    }
};

int main() {
  cout<<"Emman Abrar Ali 23k0051"<<endl;
    // Objects
    ValidateString Sentence("I have no brain cells");
    ValidateString Sentence2("I have 2 braincells");

    cout << "String 1: I have no brain cells " << endl;
    cout << "Is this sentence purely alphabetical? : " << (Sentence.IsValid() ? "Yes" : "No") << endl;

    cout << endl << "String 2: I have 2 braincells " << endl;
    cout << "Is this sentence purely alphabetical? : " << (Sentence2.IsValid() ? "Yes" : "No") << endl;

    return 0;
}//end main 
