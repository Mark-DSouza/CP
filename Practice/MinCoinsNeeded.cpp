#include <iostream>
#include <climits>
using namespace std;

int coinsNeeded(int *coins, int amount, int n) {
    // Base Case
    if (amount == 0)
        return 0;

    // Recursive Case
    int ans = INT_MAX;

    for(int i = 0; i < n; i++) {
        if (amount - coins[i] >= 0) {
            int smallerAns = coinsNeeded(coins, amount - coins[i], n);
            if (smallerAns != INT_MAX)
                ans = min(ans, smallerAns + 1);
        }
    }
    
    return ans;
}

int main() {
    int us_coins[] = {1, 3, 7};
    cout << coinsNeeded(us_coins, 15, 3);
    return 0;
}