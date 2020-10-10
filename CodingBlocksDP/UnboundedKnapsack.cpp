#include <iostream>
using namespace std;

// Recursive
int knapsack(int* weights, int* prices, int itemNumber, int currentWeight) {
    if (itemNumber == 0 || currentWeight == 0)
        return 0;
    
    else {
        int include = 0, exclude = 0;

        if (weights[itemNumber - 1] <= currentWeight)
            include = prices[itemNumber - 1] + knapsack(weights, prices, itemNumber - 1, currentWeight - weights[itemNumber - 1]);
        
        exclude = knapsack(weights, prices, itemNumber - 1, currentWeight);

        return max(include, exclude);
    }
}

// Bottom-Up Dynamic Programming
int knapsackBU(int* weights, int* prices, int numberOfItems, int maxWeight) {
    int dp[100][100] = {0};

    for (int n = 0; n <= numberOfItems; n++) {
        for (int w = 0; w <= maxWeight; w++) {
            if (n == 0 || w == 0)
                dp[n][w] = 0;

            else {
                int include = 0, exclude = 0;

                if (weights[n - 1] <= w)
                    include = prices[n - 1] + dp[n][w - weights[n - 1]];
                
                exclude = dp[n - 1][w];

                dp[n][w] = max(include, exclude);
            }
        }
    }

    return dp[numberOfItems][maxWeight];
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