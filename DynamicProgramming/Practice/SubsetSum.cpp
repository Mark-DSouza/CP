/*
    Problem Statement:
        Can a subset be formed whose sum is sum. Return bool.
*/

#include <iostream>
using namespace std;

bool subsetSum(int *arr, int sum, int n) {
    bool **t = new bool*[n+1];
    for (int i = 0; i <= n; i++)
        t[i] = new bool[sum+1];
    
    for (int j = 0; j <= sum; j++)
        t[0][j] = false;
    for (int i = 0; i <= n; i++)
        t[i][0] = true;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j<= sum; j++)
            if (arr[i-1] <= sum)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            else 
                t[i][j] = t[i-1][j];

    return t[n][sum];
}

int main() {
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 141;
    int n = sizeof(arr) / sizeof(int);
    cout << subsetSum(arr, sum, n) << endl;
    return 0; 
}