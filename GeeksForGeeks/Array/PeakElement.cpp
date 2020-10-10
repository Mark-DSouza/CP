/*
    Problem Statement:
        Given an array of integers. Find a peak element in it.

        An array element is peak if it in NOT smaller than its neighbors
*/

#include <iostream>
using namespace std;

// O(logN)
// A binary search based function that returns index of a peak element
int findPeakUtil(int *a, int low, int high, int n) {
    // Find index of middle element
    int mid = (low + high) / 2;

    // Compare middle elements with its neighbours(if it has neighbours)!!! Absolute Genius!!!
    if ( (mid == 0 || a[mid-1] <= a[mid]) && (mid == n-1 || a[mid+1] >= a[mid]) )
        return mid;
    
    // If middle element is not peak and its left neighbour is greater than it,
    // the left half must have a peak element
    else if (mid > 0 && a[mid - 1] > a[mid])
        return findPeakUtil(a, low, mid - 1, n);

    // If middle element is not peak and its right neighbour is greater than it,
    // the right half must have a peak element
    else
        return findPeakUtil(a, mid + 1, high, n);
}


// A wrapper function over recursive function findPeakUtil()
int findPeak(int* a, int n) {
    return findPeakUtil(a, 0, n - 1, n);
}

int main() {
    int a[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Index of a peak point is " << findPeak(a, n);
    return 0;
}

// Linear Search "Can't Touch This"!