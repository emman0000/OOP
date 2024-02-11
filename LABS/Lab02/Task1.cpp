//Programmer Emman Ali-23k0051 LAB02 Task 1
#include <iostream>  
using namespace std;
//function for swapping
void RecursiveSwap(int &x, int &y, int count) {  
    if (count == 0) {  
        return;  
    } //end if 
    else {  
        int temp = x;  
        x = y;   y = temp; 
        int c = count-1; //decrement count for recursive swap
       RecursiveSwap(x, y, c );  
    } //end else 
}//end function  
//Main function
int main() {  
    int x = 7, y = 9;  
cout << "Before swapping: x = " << x << ", y = " << y << endl;  
RecursiveSwap(x, y, 1); //I passed three values into the function I called the last one for the cout to continually swap the numbers until it decrements to 0. 
    cout << "After swapping: x = " << x << ", y = " << y << endl;  
    return 0;  
}//end main 
