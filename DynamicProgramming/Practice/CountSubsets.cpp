/*
    Problem Statement:
        Display the count of subsets with the given sum.
*/

#include <iostream>
using namespace std;

int countSubsets(int *arr, int sum ,int n) {
    int **t = new int*[n+1];
    for (int i = 0; i <= n; i++)
        t[i] = new int[sum+1];

    for (int j = 0; j <= sum; j++)
        t[0][j] = 0;
    for (int i = 0; i <= n; i++)
        t[i][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum ; j++)
            if (arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            else 
                t[i][j] = t[i-1][j];

    return t[n][sum];
}

int main() {
    int arr[] = {2, 3, 5, 6, 8, 10};
    int sum = 10;
    int n = sizeof(arr)/sizeof(int);
    cout << countSubsets(arr, sum, n) << endl;
    return 0;
}