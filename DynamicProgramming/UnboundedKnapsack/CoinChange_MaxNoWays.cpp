/*
    Problem Statement:
        Given a coins array and a sum, find all the possible ways to achieve that sum. Display the maximum number of ways.
*/ 

#include <iostream>
using namespace std;

// Similar to CountSubsetSum()
int maxWays(int *coins, int sum, int n) {
    int **t = new int*[n+1];
    for (int i = 0; i <= n; i++)
        t[i] = new int[sum+1];
    
    for(int i = 0; i <= sum; i++)
        t[0][i] = 0;
    for(int i = 0; i <= n; i++)
        t[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j >= coins[i-1]) 
                t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
            else 
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][sum];
}

int main() {
    int coins[] = {1, 2, 3};
    int n = sizeof(coins) / sizeof(int);
    int sum = 5;

    cout << maxWays(coins, sum, n) << endl;
    return 0;
}



