//Programmer Emman Ali-23k0051 LAB02-Task6
//Using Eculidean's Method
#include <iostream>
using namespace std;

int calculateGCD(int x, int y) {
    if (y == 0)return x;
    return calculateGCD(y, x % y);
}//end function 

// Function to calculate LCM (Least Common Multiple) 
int calculateLCM(int x, int y) {
    return (x * y) / calculateGCD(x, y);//use gcd to calculate LCM
}//end function

int main() {
    int num1, num2;
    cout << "Enter first number X: "; cin >> num1;
    cout << "Enter second number Y: ";cin >> num2;
    int gcd = calculateGCD(num1, num2);
    int lcm = calculateLCM(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd << endl;
    cout << "LCM of " << num1 << " and " << num2 << " is: " << lcm << endl;
    return 0;
}//end main 
