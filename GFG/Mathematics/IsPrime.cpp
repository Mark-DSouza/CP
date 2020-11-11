#include <iostream>
using namespace std;

// Time Complexity: O(sqrt(N))
bool isPrime(int n) {
    if (n == 1)
        return false;
    
    // factors occur is pairs about the square root of n
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;
    
    return true;
}

// Adding a few optimizations
// Time Complexity: O(sqrt(N)/3)
bool isPrimeOptimised(int n) {
    if (n == 1)
        return false;

    if (n == 2 || n == 3)
        return true;

    // Checking if it is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    
    // Another optimization
    for (int i = 5; i*i <= n; i+=6)
        if (n % i==0 || n % (i+2) == 0)
            return false;

    return true;
}

int main() {
    int n = 101;
    cout << isPrime(n) << endl << isPrimeOptimised(n) << endl;
    return 0;
}