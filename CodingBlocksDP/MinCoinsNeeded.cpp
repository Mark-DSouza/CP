#include <iostream>
#include <climits>
// #include <algorithm>
using namespace std;

// Recursion
int coinsNeeded(int *coins, int amount, int n) {
    // Base Case
    if (amount == 0) {
        return 0;
    }

    // Recursive Case
    int ans = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(amount - coins[i] >= 0) {
            int smallAns = coinsNeeded(coins, amount - coins[i], n);
            if (smallAns != INT_MAX)
                ans = min(ans, smallAns + 1);
        }
    }

    return ans;
}

// Bottom-Up Dynamic Programming
int coinsNeededBU(int *coins, int amount, int n) {
    int *dp = new int[amount + 1];
    for (int i = 0; i < amount + 1; i++)
        dp[i] = INT_MAX;

    dp[0] = 0;

    for (int rupay = 1; rupay <= amount; rupay++) {
        // Iterate over coins
        for(int i = 0; i < n; i++) {
            if (coins[i] <= rupay) {
                int smallerAns = dp[rupay - coins[i]];
                if (smallerAns != INT_MAX)
                    dp[rupay] = min(dp[rupay], smallerAns + 1);
            }
        }
    }

    return dp[amount]; 
}

int main() {
    int us_coins[] = {1, 7, 10};
    int amount  = 15;
    int n = 3;
    cout << coinsNeeded(us_coins, amount, n) << endl;
    cout << coinsNeededBU(us_coins, amount, n) << endl;

    int coins[] = {1, 2, 5, 10};
    int paise = 13;
    cout << coinsNeeded(coins, paise, 4) << endl;
    return 0;
}