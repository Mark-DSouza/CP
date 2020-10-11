#include <iostream>
using namespace std;

bool subsetSum(int arr[], int sum, int n) {
    int **dp = new int*[n+1];
    for (int i = 0; i <= n; i++)
        dp[i] = new int[sum+1];
    
    for (int i = 0; i <= sum; i++)
        dp[0][i] = false;
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i-1] <= j)
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

bool equalSumSubset(int* arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2)
        return false;
    
    else {
        return subsetSum(arr, sum/2, n);
    }
}

int main() {
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr)/sizeof(int);
    cout << equalSumSubset(arr, n) << endl;
    return 0;
}