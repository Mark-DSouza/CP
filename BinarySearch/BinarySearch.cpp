/*
    Problem Statement:
        Search for an element in an array.
*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int ele) {
    int start = 0;
    int end = n - 1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == ele)
            return mid;
        else if(arr[mid] < ele)
            start = mid + 1;
        else 
            end = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(int);
    cout << binarySearch(arr, n, 2) << endl;
    return 0;
}

/*
    Binary Search is a Divide and Conquer Algorithm.
    In this iterative implementation, 
        at each iteration, we search the given subarray for the element
        we reduce the size of the subarray after each iteration
*/