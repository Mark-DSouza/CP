#include <bits/stdc++.h>
using namespace std;

int lastOccurence(int arr[], int n, int element) {
    int start = 0;
    int end = n - 1;
    int res = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (element == arr[mid]) {
            res = mid;
            start = mid + 1;
        }

        else if (element < arr[mid]) {
            end = mid - 1;
        }

        else {
            start = mid + 1;
        }
    }

    return res;
}

int main() {
    int arr[] = {1, 2, 3, 10, 10, 10, 10, 12, 15};
    int n = sizeof(arr) / sizeof(int);
    cout << lastOccurence(arr, n, 10) << endl;
    return 0;
}