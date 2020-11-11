#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int t[1001][1001];

int minCost(int *arr, int i, int j) {
    if (i >= j)
        return 0;
    
    int mn = INT_MAX;
    for (int k = i; k <= j-1; k++) {
        int tempAns = minCost(arr, i, k) + minCost(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];

        if (mn > tempAns)
            mn = tempAns;
    }

    return mn;
}

int minCostMemoized(int *arr, int i, int j) {
    if (i >= j)
        return 0;
    
    if (t[i][j] != -1)
        return t[i][j];

    int mn = INT_MAX;
    for (int k = i; k <= j-1; k++) {
        int tempAns = minCostMemoized(arr, i, k) + minCostMemoized(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];

        if (tempAns < mn)
            mn = tempAns;
    }

    return t[i][j] = mn;
}

int main() {
    // int arr[] = {40, 20, 30, 10, 30};
    int arr[] = {10, 30, 5, 60};

    int size = sizeof(arr)/ sizeof(int);
    cout << minCost(arr, 1, size-1) << endl;

    memset(t, -1, sizeof(t));
    cout << minCostMemoized(arr, 1, size-1) << endl;
    return 0;
}