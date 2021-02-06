#include <bits/stdc++.h>
using namespace std;

int largestWindow(int arr[], int n, int k) {
    int i = 0, j = 0, res = INT_MIN;
    int sum = 0;
    while (j < n) {
        sum = sum + arr[j];

        if (sum < k) {
            j++;
        }

        else if (sum == k) {
            res = max(res, j - i + 1);
            j++;
        }

        else if (sum > k) {
            while (sum > k) {
                sum = sum - arr[i];
                i++;
                if (sum == k)
                    res = max(res, j - i + 1);
            }
            j++;
        }
    }

    return res;
}

int main() {
    int arr[] = {4, 1, 1, 1, 2, 3, 5};
    int n = sizeof(arr) / sizeof(int);
    int k = 5;
    cout << largestWindow(arr, n, k) << endl;
    return 0;
}