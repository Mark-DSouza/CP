#include <iostream>
using namespace std;

int unboundedKnapsack(int *weights, int *val, int W, int N) {
    int t[N+1][W+1];

    for (auto& col: t)
        col[0] = 0;
    for (auto& rowElement: t[0])
        rowElement = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= W; j++)
            if (weights[i-1] <= j)
                t[i][j] = max(val[i-1] + t[i][j-weights[i-1]], t[i-1][j]);
            else 
                t[i][j] = t[i-1][j];
    
    return t[N][W];
}

int main() {
    int weights[] = {1, 2, 3, 4, 5};
    int val[] = {1, 3, 4, 5, 7};
    int W = 7;
    int N = sizeof(weights)/sizeof(int);
    cout << unboundedKnapsack(weights, val, W, N) << endl;
    return 0;
}