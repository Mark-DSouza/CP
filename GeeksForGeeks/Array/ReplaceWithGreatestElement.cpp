/*
    Problem Statement:
        Given an array of integers, repalce every element with 
        the next greatest element (greatest element on the right side) in the array.

        Since the is no element next ot the last element, repalce it with -1
*/

#include <iostream>
using namespace std;

// Time: O(N), Space: O(1)
void nextGreatest(int* a, int n) {
    int max_from_right = a[n - 1];
    a[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--) {
        int temp = a[i];
        a[i] = max_from_right;
        if (max_from_right < temp)
            max_from_right = temp;
    }
}

void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) 
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {16, 17, 4 ,3, 5, 2};
    int n = sizeof(a) / sizeof(a[0]);
    nextGreatest(a, n);
    cout << "The modified array is : "<< endl;
    printArray(a, n);
    return 0;
}