#include <iostream>
using namespace std;

int countSubsetsWithSum(int* arr, int sum, int n) {
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++)
        dp[i] = new int[sum + 1];
    
    for(int i = 0; i <= sum; i++)
        dp[0][i] = 0;
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) 
                dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];
}

int main() {
    int arr[] = {2, 3, 5, 6, 8, 10};
    int sum = 10;
    int n = sizeof(arr)/sizeof(int);
    cout << countSubsetsWithSum(arr, sum, n) << endl;
    return 0;
}