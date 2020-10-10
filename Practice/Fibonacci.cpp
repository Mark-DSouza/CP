#include <iostream>
using namespace std;

// Recursive
int fib(int n) {
    // Base Case
    if (n == 0 || n == 1)
        return n;
    
    // Recursive Case
    return fib(n - 1) + fib(n - 2);
}

// Top-Down Dynamic Programming: Recursion + Memoization
int fibTD(int n, int *dp) {
    // Base Case
    if (n == 0 || n == 1) {
        dp[n] = n;
        return dp[n];
    }

    // Recursive Case
    // If Already Computed
    if (dp[n] != -1)
        return dp[n];
    // Compute and Store it
    else {
        dp[n] = fibTD(n - 1, dp) + fibTD(n - 2, dp);
        return dp[n];
    }
}

// Bottom-Up DP: Iterative
int fibBU(int n) {
    int *dp = new int[n + 1];

    // Base Case
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int FibOptimal(int n) {
    int a = 0;
    int b = 1;
    int c;

    if (n == 0)
        return a;
    
    if (n == 1)
        return b;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main() {
    cout << fib(7) << endl;

    int *dp = new int[100];
    for(int i = 0; i < 100; i++ )
        dp[i] = -1;
    cout << fibTD(10, dp) << endl;
    cout << fibBU(10) << endl;
    cout << FibOptimal(10) << endl;
    return 0;
}