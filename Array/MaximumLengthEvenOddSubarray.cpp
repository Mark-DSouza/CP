/*
    Problem Statement: 
        Find the length of the longest even odd subarray.
*/

#include <bits/stdc++.h>
using namespace std;

int maxEvenOddNaive(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        int curr = 1;
        for (int j = i + 1; j < n; j++) {
            if ((arr[j] % 2 == 0 && arr[j-1] % 2 == 1) || (arr[j] % 2 == 1 && arr[j-1] % 2 == 0))
                curr++;
            else break;
        }
        res = max(res, curr);
    }

    return res;
}

int maxEvenOdd(int arr[], int n) {
    int res = 1;
    int curr = 1;
    for (int i = 1; i < n; i++) {
        if ((arr[i] % 2 == 0 && arr[i-1] % 2 == 1) || (arr[i] % 2 == 1 && arr[i-1] % 2 == 0)) {
            curr++;
            res = max(res, curr);
        } else {
            curr = 1;
        }
    }

    return res;
}

int main() {
    int arr[] = {10, 12, 14, 7, 8};
    int n = sizeof(arr) / sizeof(int);
    cout << maxEvenOddNaive(arr, n) << endl;
    cout << maxEvenOddNaive(arr, n) << endl;
    cout << endl;
}