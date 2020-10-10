#include <iostream>
using namespace std;

// Recursive Simple k = 3
int ways(int n) {
    // Border Case
    if (n < 0)
        return 0;

    // Base Case 
    if (n == 0)
        return 1;

    // Recursive Case
    return ways(n - 1) + ways(n - 2) + ways(n - 3);
}

// Bottom-Up Dynamic Programming Simple k = 3

// Recursive Advanced
int ways(int n, int k) {
    // Border Case
    if (n < 0)
        return 0;

    // Base Case
    if (n == 0)
        return 1;

    // Recursive Case
    int ans = 0;
    for (int j = 1; j <= k; j++)
        ans += ways(n - j, k);
    return ans;
}


// Top-Down Dynamic Programming (n, k)
int waysTD(int n, int k, int *dp) {
    if (n < 0)
        return 0;
    
    // Base Case
    if (n == 0) {
        dp[0] = 1;
        return dp[0];
    }

    // Recursive Case
    if (dp[n] != -1)
        return dp[n];
    else {
        dp[n] = 0;
        for (int j = 1; j <= k; j++)
            dp[n] += waysTD(n - j, k, dp);
        return dp[n];
    }
}

// Bottom-Up Dynamic Programming (n, k)  Time: O(kn)
int waysBU(int n, int k) {
    int *dp = new int[n + 1];

    dp[0] = 1;

    for(int step = 1; step <= n; step++) {
        dp[step] = 0;
        for(int j = 1; j <= k; j++) {
            if (step - j >= 0)
                dp[step] += dp[step - j]; 
        }
    }

    return dp[n];
}


// Optimal Solution: Time: O(k^2 + n)
int waysOptimal(int n , int k) {
    int *dp = new int[n + 1];

    dp[0] = 1;

    for (int step = 1; step <= k; step++) {
        dp[step] = 0;
        for (int j = 1; j <= k; j++) {
            if (step - j >= 0)
                dp[step] += dp[step - j];
        }
    }

    for (int step = k + 1; step <= n; step++) {
        dp[step] = 2 * dp[step - 1] - dp[step - 1 - k];
    }

    return dp[n];
}

int main() {
    cout << ways(4) << endl;
    cout << ways(4, 3) << endl;

    int *dp = new int[100];
    for (int i = 0; i < 100; i++)
        dp[i] = -1;
    cout << waysTD(5, 2, dp) << endl;

    cout << waysBU(50, 3) << endl;
    cout << waysOptimal(50, 3) << endl;
    return 0;
}