/*
    Problem statement:
        Find an element in a rotated array

    Approach:
        Find the smallest element. It divides the rotated array into exactly 2 sorted arrays.
*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int element) {

    while (start <= end) {
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

int findPivot(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    int pivot = -1;

    while(start <= end) {
        if (start <= end) {
            pivot = start;
            break;
        }

        int mid = start + (end - start) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        if (arr[mid] < arr[prev] && arr[mid] < arr[next]) {
            pivot = mid;
            break;
        }

        else if (arr[start] < arr[mid])
            start = mid + 1;

        else 
            end = mid - 1;
    }

    return pivot;
}

// int rotatedBinarySearch(int arr[], int n, int element) {
//     int pivot = findPivot(arr, n);
//     int firstResult = binarySearch(arr, 0, pivot-1, element);
//     if (firstResult != -1) 
//         return firstResult;
//     return binarySearch(arr, pivot, n-1, element);
// }

int rotatedBinarySearch(int arr[], int n, int element) {
    int pivot = findPivot(arr, n);
    if (binary_search(arr, arr + pivot, element))
        return lower_bound(arr, arr + pivot, element) - arr;
    if (binary_search(arr+pivot, arr + n, element))
        return lower_bound(arr+pivot, arr+n, element) - arr;
    return -1;
}

int main() {
    int arr[] = {11, 12, 13, 14, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    cout << rotatedBinarySearch(arr, n, 3) << endl;

    return 0;
}