#include <iostream>
using namespace std;

// Recursive
int knapsack(int* weights, int* val, int W, int N) {
    // base case
    if (W == 0 || N == 0)
        return 0;

    // recursive case
    else {
        if (W - weights[N-1] >= 0)
            return max(val[N-1] + knapsack(weights, val, W-weights[N-1], N-1), knapsack(weights, val, W, N-1));
        else
            return knapsack(weights, val, W, N-1);
    }
}

int knapsackMemoized(int* weights, int* val, int W, int N, int **dp) {
    // base case
    if (W == 0 || N == 0) {
        return dp[N][W] = 0;
    }

    // recursive case
    else {
        if (dp[N][W] != -1)
            return dp[N][W];
        
        else {
            if (W - weights[N-1] >= 0)
                return dp[N][W] = max(val[N-1] + knapsackMemoized(weights, val, W-weights[N-1], N-1, dp), 
                                knapsackMemoized(weights, val, W, N-1, dp));
            else 
                return dp[N][W] = knapsackMemoized(weights, val, W, N-1, dp);
        }
    }
}

int knapsackIterative(int *weights, int *val, int W, int N) {
    int **T = new int*[N+1];
    for(int i = 0; i <= N; i++)
        T[i] = new int[W+1];

    // base case becomes assignment
    for (int i = 0; i <= N; i++)
        T[i][0] = 0;
    for (int i = 0; i <= W; i++)
        T[0][i] = 0;
    
    // recursive case becomes iteration
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (j - weights[i-1] >= 0)
                T[i][j] = max(val[i-1] + T[i-1][j-weights[i-1]],
                                     T[i-1][j]);
            else 
                T[i][j] = T[i-1][j];
        }
    }

    return T[N][W];
}   

int main() {
    int weights[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;
    int N = sizeof(weights)/ sizeof(int);

    cout << knapsack(weights, val, W, N) << endl;

    int **dp = new int*[N+1];
    for (int i = 0; i <= N; i++)
        dp[i] = new int[W+1];
    
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= W; j++)
            dp[i][j] = -1;

    cout << knapsackMemoized(weights, val, W, N, dp) << endl;

    cout << knapsackIterative(weights, val, W, N) << endl;    
    return 0;
}

