#include <bits/stdc++.h>
using namespace std;

int floor(int arr[], int n, int element) {
    int start = 0;
    int end = n - 1;

    int res = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (element == arr[mid]) {
            return arr[mid];
        }

        else if (element > arr[mid]) {
            res = arr[mid];
            start = mid + 1;
        }

        else 
            end = mid - 1;
    }

    return res;
}

int main() {
    int arr[] = {1, 2, 3, 4, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(int);
    cout << floor(arr, n, 5) << endl;
    return 0;
}