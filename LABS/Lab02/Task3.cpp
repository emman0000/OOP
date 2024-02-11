Programmer Emman Ali-23k0051 LAB02 Task 3
#include<iostream>
using namespace std;
//bool function
bool hasSubsetSum(int array[], int arraySize, int target) {
    if(arraySize == 0) {
        return target == 0;
    }
//two recursive calls that exclude the last number and maintain the target sum.
    return hasSubsetSum(array, arraySize - 1, target) || hasSubsetSum(array, arraySize - 1, target - array[arraySize - 1]);
}
//main function
int main() {
    int array[] = {3, 34, 4, 12, 5, 2};
    int size = sizeof(array) / sizeof(array[0]);
    int targetSum;
    cout << "Enter a target numbe: ";    cin >> targetSum;
    bool result = hasSubsetSum(array, size, targetSum); //calling function 
//Show results 
    if (result) {
        cout << "There exists a subset of the array that sums up to the target sum." << endl;
    }//end if 
    else {
        cout << "There does not exist a subset of the array that sums up to the target sum." << endl;
    }//end else

    return 0;
}//end main 
