/*
    Problem Statement:
        Can the set be partitioned into 2 subsets of equal sum. Display the boolean.
*/

#include <iostream>
using namespace std;

bool subsetSum(int *arr, int sum, int n) {
    bool **t = new bool*[n+1];
    for (int i = 0; i <= n; i++)
        t[i] = new bool[sum+1];

    for (int j = 0; j <= sum; j++)
        t[0][j] = false;
    for (int i = 0; i <= n; i++)
        t[i][0] = true;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
            if (arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            else 
                t[i][j] = t[i-1][j];

    return t[n][sum];
}

bool equalPartition(int *arr, int n) {
    // Equal partition means the set can be divided equally into 2 subsets
    // For that the sum must be even! Duh
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum & 1) // If sum is odd
        return false;

    else        // If sum is even, search for one partition of sum-sum/2=sum/2, the other one is automatically sum/2
        return subsetSum(arr, sum/2, n);
}

int main() {
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr)/sizeof(int);
    cout << equalPartition(arr, n) << endl;
    return 0;
}

// Subset sum is a derivative of subset sum