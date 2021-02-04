/*
    Find an element in a sorted array given that the type of sorting,
    ascending/descending is not known
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

int orderAgnosticBinarySearch(int arr[], int n, int element) {
    if (n == 1)
        if (element == arr[0])
            return 0;

    if (arr[0] < arr[n - 1]) {
        cout << "Ascending" << endl;
        return binarySearch(arr, n, element);
    }

    else {
        cout << "Descending" << endl;
        return reverseBinarySearch(arr, n, element);
    }
}

int main() {
    // int arr[] = {1, 2, 3, 4, 5};
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3};
    int n = sizeof(arr)/sizeof(int);
    cout << orderAgnosticBinarySearch(arr, n,  4) << endl;
    return 0;
}