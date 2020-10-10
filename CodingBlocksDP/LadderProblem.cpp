#include <iostream>
using namespace std;

// Recursion
int ways(int n) {
    // Ground
    if (n == 0)
        return 1;   // No. of ways of reaching from the ground is just 1
    
    if (n < 0)
        return 0;

    return ways(n - 1) + ways(n - 2) + ways(n - 3);
}

// Recursion with general (n, k)    Time: O(k^n)
int ways2(int n, int k) {
    if (n == 0)
        return 1;
    
    if (n < 0)
        return 0;

    int ans = 0;
    for(int j = 1; j <= k; j++)
        ans += ways2(n - j, k);
    return ans;
}


// Bottom-Up Approach with (n, k)   Time: O(kn)
int waysBU(int n, int k) {
    int *dp = new int[n];
    dp[0] = 1;

    for(int step = 1; step <= n; step++) {
        dp[step] = 0;
        for(int j = 1; j <= k; j++) {
            if (step - j >= 0) {
                dp[step] += dp[step - j];
            }
        }
    }

    return dp[n];
}


// Homework: Do Top-Down DP....It's already done in MyLadderProblem.cpp


// Can we do it in Time: O(n)?
// Yes, use the homework recursion!!

int main() {
    int n = 4;
    cout << ways(4) << endl;
    cout << ways2(3, 2) << endl;
    cout << ways2(4, 3) << endl;
    cout << ways2(5, 4) << endl;
    cout << waysBU(5,4) << endl;
    return 0;
}