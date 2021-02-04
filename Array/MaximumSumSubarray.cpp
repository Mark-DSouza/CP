/*
    Problem statement:
        Find the maximum sum of any possible subarray of a given array
*/

#include <bits/stdc++.h>
using namespace std;

int maxSumNaive(int arr[], int n) {
    int res = arr[0];

    for (int i = 0; i < n; i++) {
        int curr = 0;
        for (int j = i; j < n; j++) {
            curr = curr + arr[j];
            res = max(res, curr);
        }
    }

    return res;
}

int maxSum(int arr[], int n) {
    int res = arr[0];
    int maxEnding = arr[0];
    for (int i = 1; i < n; i++) {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }

    return res;
}

int main() {
    int arr[] = {2, 3, -8, 7, -1, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    cout << maxSumNaive(arr, n) << endl;
    cout << maxSum(arr, n) << endl;
    return 0;
}