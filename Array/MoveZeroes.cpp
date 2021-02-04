/*
    Move Zeroes To The Right

    We are given an array of integers and we need to move all the zeros to the end,
    without changing the order of the rest of the integers.
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return;
}

// Naive Solution
// - If the element is a non-zero integer, then we don't do anything
// - If the element is zero, then we search for the first non-zero integer starting from that element
//      and then swap with current element
// Repeat for every element of the array
// Time: O(n^2)
void naiveMoveToEnd(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] != 0) {
                    swap(arr[i], arr[j]);
                    break;
                }
            }
        }
    }
}

// Efficient Solution
// - We consider the array to be in order and we maintain a count of the number of non-zero elements,
// - If the current element is 0, it is in order
// - If the current element is non-zero, the current element is swapped with arr[count] (That's the 1st zero el)
void moveZeros(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[count]);
            count++;
        }
    }
}

int main() {
    int arr[] = {10, 5, 0, 0, 8, 0, 9, 0};
    int n = sizeof(arr)/sizeof(int);
    // naiveMoveToEnd(arr, n);
    moveZeros(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}