#include <iostream>
#include <climits>
using namespace std;

int minCoinsNeeded(int *coins, int sum, int n) {
    int **t = new int*[n+1];
    for (int i = 0; i <= n; i++)
        t[i] = new int[sum+1];

    for (int i = 0; i <= sum; i++)
        t[0][i] = INT_MAX;
    for (int i = 0; i <= n; i++)
        t[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (coins[i-1] <= j) {
                int smallerAns = t[i][j-coins[i-1]];
                if (smallerAns != INT_MAX)
                    t[i][j] = min(smallerAns + 1, t[i-1][j]);
                else 
                    t[i][j] = t[i-1][j];
            }
            else 
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][sum];
}

int main() {
    int coins[] = {1, 2, 3};
    int sum = 5;
    int n = sizeof(coins)/ sizeof(int);

    cout << minCoinsNeeded(coins, sum, n) << endl;
    return 0;
}