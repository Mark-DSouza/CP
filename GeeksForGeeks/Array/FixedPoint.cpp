/*
    Problem Statement:
        Given an array of n distinct integers(negative possible) sorted in ascending order, 
        write a funciton tha returns a Fixed Point in the array,
        if there is any Fixed Point present in array, else returns -1

        Fixed Point: arr[i] == i
*/

#include <iostream>
using namespace std;

// Time: O(logN), Space: O(1)
int binarySearch(int* a, int low, int high) {
    int mid = (low + high) / 2;

    if (high >= low) {
        if (mid == a[mid])
            return mid;
        else if (mid > a[mid])
            return binarySearch(a, mid + 1, high);
        else
            return binarySearch(a, low, mid - 1);
    }

    return -1;
}

int main() {
    int a[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "The Fixed Point is: "<< binarySearch(a, 0, n - 1) << endl;
    return 0;
}

// Linear Search is the simpler solution, but you wanna impress those interviewers!