#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n, int k) {
    int i = 0, j = 0;
    int sum = 0, res = INT_MIN;
    while (j < n) {
        sum = sum + arr[j];

        if (j - i + 1 < k) {
            j++;
        }

        else if (j - i + 1 == k) {
            res = max(sum, res);

            sum = sum - arr[i];
            i++;
            j++;
        }
    }

    return res;
}

int main() {
    int arr[] = {2, 5, 1, 3, 2, 9, 1};
    int n = sizeof(arr) / sizeof(int);
    int k = 3;
    cout << maxSum(arr, n, k) << endl;
    return 0;
}