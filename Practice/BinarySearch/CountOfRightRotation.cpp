/*
    Problem Statement:
        Find the number of right rotations on a sorted array.

    Approach:
        We will basically find the least element and return its position.

        Remember that the least element always lies in the unsorted half of the array.
*/

#include <bits/stdc++.h>
using namespace std;

int countOfRightRotations(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        if (arr[start] <= arr[end])
            return start;

        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;

        if (arr[mid] < arr[prev] && arr[mid] < arr[next])
            return mid;

        else if (arr[start] < arr[mid])
            start = mid + 1;
        
        else 
            end = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {11, 12, 13, 14, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    cout << countOfRightRotations(arr, n) << endl;

    return 0;
}