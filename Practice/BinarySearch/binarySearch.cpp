/*
    Problem statement:
        Find an element in a sorted array.
*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int element) {
    int start = 0;
    int end = n - 1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if (element == arr[mid])
            return mid;
        
        else if (element < arr[mid])
            end = mid - 1;

        else 
            start = mid + 1;
    }

    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);
    cout << binarySearch(arr, n, 3) << endl;
    return 0;
}