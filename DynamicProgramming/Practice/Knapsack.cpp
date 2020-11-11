#include <iostream>
#include <cstring>
using namespace std;

int knapsack(int *weights, int *val, int W, int N) {
    // Base Condition
    if (W == 0 || N == 0)
        return 0;

    // Choice Diagram
    else {
        if (weights[N-1] <= W)
            return max(val[N-1] + knapsack(weights, val, W-weights[N-1], N-1), 
                        knapsack(weights, val, W, N-1));
        else 
            return knapsack(weights, val, W, N-1);
    }
}

int knapsackMemoized(int *weights, int *val, int W, int N, int **t) {
    if (W == 0 || N == 0)
        return 0;

    else if (t[N][W] != -1)
        return t[N][W];
    
    else 
        if (weights[N-1] <= W)
            return t[N][W] = max(val[N-1] + knapsackMemoized(weights, val, W-weights[N-1], N-1, t),
                                    knapsackMemoized(weights, val, W, N-1, t));
        else 
            return t[N][W] = knapsackMemoized(weights, val, W, N-1, t);
}

int knapsackBottomUp(int *weights, int *val, int W, int N) {
    int **t = new int*[N+1];
    for(int i = 0; i <= N; i++)
        t[i] = new int[W+1];

    for (int i = 0; i <= N; i++)
        t[i][0] = 0;
    for (int j = 0; j <= W; j++)
        t[0][j] = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= W; j++) 
            if (weights[i-1] <= j)
                t[i][j] = max(val[i-1] + t[i-1][j-weights[i-1]], t[i-1][j]);
            else 
                t[i][j] = t[i-1][j];

    return t[N][W];
}

int main() {
    int weights[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;
    int N = sizeof(weights) / sizeof(int);
    cout << knapsack(weights, val, W, N) << endl;

        int **t = new int*[N+1];
        for(int i = 0; i <= N; i++)
            t[i] = new int[W+1];

        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= W; j++)
                t[i][j] = -1;
    cout << knapsackMemoized(weights, val, W, N, t) << endl;

    cout << knapsackBottomUp(weights, val, W, N) << endl;
    return 0;
}