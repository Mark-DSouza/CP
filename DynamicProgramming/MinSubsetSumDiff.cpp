#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int minSubsetSumDiff(int arr[], int n) {
    bool **dp = new bool*[n+1];
    
    int range = 0;
    for(int i = 0; i < n; i++)
        range += arr[i];
    
    for(int i = 0; i <= n; i++)
        dp[i] = new bool[range+1];
    
    for(int i = 0; i <= range; i++)
        dp[0][i] = false;
    for(int i = 0; i <= n; i++)
        dp[i][0] = true;
    
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= range; j++) {
            if (arr[i-1] <= j)
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    int minimum = INT_MAX;
    for(int i = 0; i <= range; i++)
        if(dp[n][i])
            minimum = min(minimum, abs(range - 2 * i));

    return minimum;
}

int main() {
    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr) / sizeof(int);
    cout << minSubsetSumDiff(arr, n) << endl;
    return 0;
}