#include <iostream>
using namespace std;

int unboundedKnapsackIterative(int *weights, int *val, int W, int N) {
    int **T = new int*[N+1];
    for (int i = 0; i <= N; i++) 
        T[i] = new int[W + 1];

    for (int i = 0; i <= N; i++) 
        T[i][0] = 0;
    for (int i = 0; i <= W; i++)
        T[0][i] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (j - weights[i-1] >= 0)
                T[i][j] = max(val[i-1] + T[i][j - weights[i-1]], T[i-1][j]);
            else
                T[i][j] = T[i - 1][j];
        }
    }

    return T[N][W];
}

int main() {
    int weights[] = {1, 2, 3, 4, 5};
    int val[] = {1, 3, 4, 5, 7};
    int W = 7;
    int N = sizeof(weights)/ sizeof(int);

    cout << unboundedKnapsackIterative(weights, val, W, N) << endl;
    return 0;
}