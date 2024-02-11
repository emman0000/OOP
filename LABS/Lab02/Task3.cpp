Programmer Emman Ali-23k0051 LAB02 Task 3
//Programmer Emman Ali-23k0051, LAB02 Task3.
#include<iostream>
using namespace std;

bool hasSubsetSum(int arr[], int size, int targetSum) {
    if(size == 0) {
        return targetSum == 0;
    }
    return hasSubsetSum(arr, size - 1, targetSum) || hasSubsetSum(arr, size - 1, targetSum - arr[size - 1]);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetSum;

    cout << "Enter the target: ";
    cin >> targetSum;

    bool result = hasSubsetSum(arr, size, targetSum);

    if (result) {
        cout << "There exists a subset of the array that sums up to the target sum." << endl;
    } else {
        cout << "There does not exist a subset of the array that sums up to the target sum." << endl;
    }

    return 0;
}//end main 
