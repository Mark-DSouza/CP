/*
    Problem Statement:
        Display the count of Partitions with given difference
*/

#include <iostream>
using namespace std;

int countSubsets(int *arr, int sum, int n) {
    int **t = new int*[n+1];
    for (int i = 0; i <= n; i++)
        t[i] = new int[sum+1];

    for (int j = 0; j <= sum; j++)
        t[0][j] = 0;
    for (int i = 0; i <= n; i++)
        t[i][0] = 1;

    for (int i = 1; i <=n ; i++)
        for (int j =1 ; j <= sum; j++)
            if (arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            else
                t[i][j] = t[i-1][j];
    
    return t[n][sum];
}

int countPartitionsWithDiff(int *arr, int diff, int n) {
    int arraySum = 0;
    for (int i = 0; i < n; i++)
        arraySum += arr[i];
    
    return countSubsets(arr, (arraySum - diff)/2, n);
}

int main() {
    int arr[] = {1, 1, 2, 3};
    int diff = 1;
    int n = sizeof(arr) / sizeof(int);
    cout << countPartitionsWithDiff(arr, diff, n) << endl;
    return 0;
}