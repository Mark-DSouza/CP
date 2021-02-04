/*
    Problem Statement:
        Count of an element in a sorted array
*/

#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[], int n, int element) {
    int start = 0;
    int end = n -1;
    int res = -1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if (element == arr[mid]) {
            res = mid;
            end = mid - 1;
        }

        else if (element < arr[mid]) {
            end = mid - 1;
        }

        else {
            start = mid + 1;
        }
    }

    return res;
}

int lastOccurence(int arr[], int n, int element) {
    int start = 0;
    int end = n - 1;
    int res = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (element == arr[mid]) {
            res = mid;
            start = mid + 1;
        }

        else if (element < arr[mid]) {
            end = mid - 1;
        }

        else {
            start = mid + 1;
        }
    }

    return res;
}

int countOfElement(int arr[], int n, int element) {
    int start = 0;
    int end = n - 1;
    
    int firstOcc = firstOccurence(arr, n, element);
    if (firstOcc == -1) return 0;

    int lastOcc = lastOccurence(arr, n, element);

    return lastOcc - firstOcc + 1;
}

int main() {
    int arr[] = {1, 2, 3, 10, 10, 10, 10, 12, 15};
    int n = sizeof(arr) / sizeof(int);
    cout << countOfElement(arr, n, 10) << endl;
    return 0;
}