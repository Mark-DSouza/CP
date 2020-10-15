/*
    Problem Statement:
        Given 2 arrays of rod lengths and their corresponding prices and the actual length of 
        the rod, maximise the profit of the rod by cutting it into appropriate pieces. Display max price.
*/

#include <iostream>
using namespace std;

// Same as unbounded knapsack, just changes in the variable names
int rodCutting(int* lengths, int* prices, int l, int n) {
    int **t = new int*[n + 1];
    for (int i = 0; i <= n; i++)
        t[i] = new int[l+1];

    for (int i = 0; i <= n; i++)
        t[i][0] = 0;
    for (int i = 0; i <= l; i++)
        t[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= l; j++) {
            if (j >= lengths[i-1])
                t[i][j] = max(prices[i-1] + t[i][j-lengths[i-1]], t[i-1][j]);
            else 
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][l];
}

int main() {
    int l = 4;
    int lengths[] = {1, 2, 3, 4};
    int prices[] = {4, 5, 8, 7};
    int n = sizeof(lengths)/sizeof(int);

    cout << rodCutting(lengths, prices, l, n) << endl;
    return 0;
}