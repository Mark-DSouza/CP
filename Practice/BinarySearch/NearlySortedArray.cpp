/*
    Problem Statement:
        Search for an element in a nearly sorted array.

    Approach:
        Everything in a nearly sorted array lies in [i-1, i, i+1] range.
*/

#include <bits/stdc++.h>
using namespace std;

int nearlySortedArraySearch(int arr[], int n, int element) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (element == arr[mid])
            return mid;

        if (mid-1 >= start && arr[mid-1] == element)
            return mid-1;
        
        if (mid+1 <= end && arr[mid+1] == element)
            return mid+1;

        else if (element < arr[mid])
            end = mid - 2;

        else 
            start = mid + 2;
    }
}

int main() {
    int arr[] = {5, 10, 30, 20, 40};
    int n = sizeof(arr) / sizeof(int);
    
    cout << nearlySortedArraySearch(arr, n, 20) << endl;
    return 0;
}