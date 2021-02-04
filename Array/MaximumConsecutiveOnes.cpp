/*
    Problem Statement:
        Return the maximum number of consecutive 1's in a binary string
*/

#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnesNaive(int arr[], int n) {
    int res = 0;

    for (int i = 0; i < n; i++) {
        int curr = 0;
        for (int j = i; j < n; j++) {
            if (arr[j] == 1)
                curr++;
            else 
                break;
        }
        
        res = max(res, curr);
    }

    return res;
}

int maxConsecutiveOnes(int arr[], int n) {
    int res = 0, curr = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            curr++;
            res = max(res, curr);
        }
        else {
            curr = 0;
        }
    }

    return res;
}

int main() {
    int arr[] = {0, 1 ,1, 0, 1, 0};
    int n = sizeof(arr) / sizeof(int);

    cout << maxConsecutiveOnesNaive(arr, n) << endl;
    cout << maxConsecutiveOnes(arr, n) << endl;

    return 0;
}