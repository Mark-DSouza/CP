#include <bits/stdc++.h>
using namespace std;

bool findSubarray(int arr[], int n, int k, int x) {
    int i = 0, j = 0, sum = 0;

    while (j < n) {
        sum = sum + arr[j];

        if (j - i + 1 < k) {
            j++;
        }

        else if (j - i + 1 == k) {
            if (sum == x) return true;

            sum = sum - arr[i];
            i++;
            j++;
        }
    }

    return false;
}

int main() {
    int arr[] = {1, 8, 30, -5, 20, 7};
    int n = sizeof(arr) / sizeof(int);
    if (findSubarray(arr, n, 3, 23))
        cout << "true";
    else 
        cout << "false";
    cout << endl;
    return 0;
}