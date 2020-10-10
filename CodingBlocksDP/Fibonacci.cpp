#include <iostream>
using namespace std;

// Recursion
int fib(int n) {
    // This function is essentially performing Mathematical Induction
    if (n == 0 || n == 1)               // This is the base case
        return n;
    return fib(n - 1) + fib(n - 2);     // This is our assumption to prove fib(n)
}


// Top-Down Dynamic Programming = Recursion + Memoization
int fibTopDown(int n, int *dp) {
    // Base Case
    if (n == 0 || n == 1) {
        dp[n] = n;
        return n;
    }

    // Already Computed
    if (dp[n] != -1)
        return dp[n];

    // Compute and Store it
    else {
        dp[n] = fibTopDown(n - 1, dp) + fibTopDown(n - 2, dp);
        return dp[n];
    }
}


// Bottom-Up Dynamic Programming = Iterative Approach
int fibBottomUp(int n) {
    int *dp = new int[n];
    // The Base Case in Top-Down DP becomes an assignment in Bottom-Up DP
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];      // dp[i] is the ith Fibonacci Number
    
    return dp[n];
}


// Optimal Fibonacci, Space: O(1), Time: O(N)
int fibOptimal(int n) {
    int a = 0;      // Keeps track of previous state
    int b = 1;      // Keeps track of previous state
    int c;          // Holds current Fibonacci number

    if (n == 0)
        return a;
    else if (n == 1)
        return b;
    
    for(int i = 2; i <=n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}


int main() {
    cout << fib(7) << endl;

    int dp[100];
    for (int i(0); i < 100; i++)
        dp[i] = -1;

    cout << fibTopDown(7, dp) << endl;
    cout << fibBottomUp(7) << endl;
    cout << fibOptimal(7) << endl;

    return 0;
}