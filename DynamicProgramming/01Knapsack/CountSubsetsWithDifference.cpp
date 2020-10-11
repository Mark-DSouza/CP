#include <iostream>
using namespace std;

int countSubsetsWithDifference(int *arr, int diff, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int target = (diff + sum) / 2;

    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++)
        dp[i] = new int[target+1];
    
    for(int i = 0; i <= target; i++)
        dp[0][i] = 0;
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= target; j++) {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
            else 
                dp[i][j] = dp[i-1][j];
        }
    } 

    return dp[n][target];
}

int main() {
    int arr[] = {1, 1, 2, 3};
    int diff = 1;
    int n = sizeof(arr) / sizeof(int);
    cout << countSubsetsWithDifference(arr, diff, n) << endl;
    return 0;
}