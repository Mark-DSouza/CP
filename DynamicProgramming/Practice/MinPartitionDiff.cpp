/*
    Problem Statement:
        Display the minimum possible partition difference.
*/

#include <iostream>
using namespace std;

bool subsetSum(int *arr, int sum, int n, bool **t) {
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

int minPartitionDiff(int *arr, int n) {
    int range = 0;
    for (int i = 0; i < n; i++)
        range += arr[i];

    bool **t = new bool*[n+1];
    for (int i = 0; i <= n; i++)
        t[i] = new bool[range+1];

    subsetSum(arr, range, n, t);

    for (int j = range/2; j >= 0; j--)
        if (t[n][j])
            return range - 2 * j;
}

int main() {
    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr) / sizeof(int);

    cout << minPartitionDiff(arr, n) << endl;
    return 0;
}

// This question requires you to construct the Subset Sum table and use the last row 
// to determine the minimum Partition difference using : |Range - 2 * S1|, where S1 is the smaller sum
// It is related to Subset Sum and Equal Sum Partition