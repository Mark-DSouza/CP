/*
    Problem statement:
        Find an element in a rotated array

    Approach:
        Find the smallest element. It divides the rotated array into exactly 2 sorted arrays.
*/

#include <bits/stdc++.h>
using namespace std;

int rotatedBinarySearch(int arr[], int n, int element) {
    int start = 0;
    int end = n - 1;
    int pivot = -1;

    return pivot;
    //Code incomplete
}

int main() {
    int arr[] = {11, 12, 13, 14, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    cout << rotatedBinarySearch(arr, n, 3) << endl;

    return 0;
}