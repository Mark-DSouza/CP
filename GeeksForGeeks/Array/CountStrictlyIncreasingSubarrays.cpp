/*
    Problem Statement:
        Given an array of integers, count number of sub arrays(of size more than one)
        that are strictly increasing.
*/

#include <iostream>
using namespace std;

// Time: O(m) where m is number of subarrays in output
// Although we are using 2 loops, they will execute only the number of times we have output
int countIncreasing(int* a, int n) {
    // Initailise count of subarrays as 0
    int count = 0;

    // Pikc starting point
    for (int i = 0; i < n; i++) {
        // Pick ending point
        for (int j = i; j < n; j++) {
            if (a[j - 1] < a[j])
                count++;

            // If subarray arr[i...j] is not strictly increasing,
            // then subarrays after it, i.e., arr[i..j+1], arr[i..j+2], .... cannot
            // be strictly increasing
            else 
                break;
        }
    }

    return count;
}

// Time: O(N)
// This solution is based on the fact that there are (len - 1) * len / 2 sorted subarrays in a given sorted subarray
int countIncreasingOptimal(int a[], int n) {
    int count = 0;  // Initialize result

    // Initialize length of current increasing subarray
    int len = 1;

    // Traverse through the array
    for(int i = 0; i < n; i++) {
        // If arr[i+1] is greater than arr[i], then increment length
        if (a[i] < a[i + 1])
            i++;

        // Else Update count and reset length
        else {
            count += (((len - 1) * len) / 2);
            len = 1;
        }
    }

    // If last lenght is more than 1
    if (len > 1)
        count += (((len - 1) * len) / 2);

    return count;
}

int main() {
    int a[] = {1, 2, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Count of strictly increasing subarrays is " << countIncreasing(a, n) << endl
        << "Count of strictly increasing subarrays is " << countIncreasingOptimal(a, n) << endl;
    return 0;
}