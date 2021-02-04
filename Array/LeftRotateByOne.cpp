/*
    Left Rotate(Counterclock-wise) the array by one
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Store the first element in a temporary variable and shift everything to the left by one.
    Store the temporary variable in the last location
*/

void leftRotateOne(int *arr, int n) {
    int temp = arr[0];
    for (int i = 1; i < n; i++)
        arr[i-1] = arr[i];
    arr[n-1] = temp;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    leftRotateOne(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}