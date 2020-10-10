#include <iostream>
using namespace std;

// Recursion
int knapsack(int* weights, int* prices, int N, int W) {
    // Base Case 
    if (N == 0 || W == 0)
        return 0;

    int inc = 0, exc = 0;

    // Including the current item
    if (weights[N - 1] <= W)
        inc = prices[N - 1] + knapsack(weights, prices, N - 1, W - weights[N - 1]);

    // Excluding the current Item
    exc = 0 + knapsack(weights, prices, N - 1, W);

    return max(inc, exc);
}

// Bottom-Up Dynamic Programming: Uses a 2-D Array to store previous calculations
int knapsackBU(int* weights, int* prices, int N, int W) {
    int dp[100][100] = {0};

    for (int n = 0; n <= N; n++) {
        for (int w = 0; w <= W; w++) {
            if (n == 0 || w == 0)
                dp[n][w] = 0;

            else {
                int inc = 0, exc = 0;
                if (weights[n - 1] <= w) {
                    inc = prices[n - 1] + dp[n-1][w - weights[n-1]];
                }
                exc = dp[n-1][w];
                dp[n][w] = max(inc, exc);
            }
        }
    }

    return dp[N][W];
}

int main() {
    int weights[] = {2, 7, 3, 4};
    int prices[] = {5, 20, 20, 10};
    int N = 4;
    int W = 11;

    cout << knapsack(weights, prices, N, W) << endl
        << knapsackBU(weights, prices, N, W) << endl;
    return 0;
}