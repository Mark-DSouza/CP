/*
    Problem Statement:
        Perform binary search on an array sorted in descending order
*/

#include <bits/stdc++.h>
using namespace std;

int reverseBinarySearch(int arr[], int n, int element) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (element == arr[mid])
            return mid;

        else if (element < arr[mid])
            start = mid + 1;

        else 
            end = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    cout << reverseBinarySearch(arr, n, 6) << endl;
    return 0;
}