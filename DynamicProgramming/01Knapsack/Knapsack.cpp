#include <iostream>
using namespace std;

// Recursive
int knapsack(int* weights, int* val, int W, int N) {
    return 0;
}

int main() {
    int weights[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;-
    int N = sizeof(weights)/ sizeof(int);

    cout << knapsack(weights, val, W, N) << endl;
    return 0;
}

