#include <iostream>
using namespace std;

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

// Time Complexity: O(N loglogN)
void seive(int n) {
    if (n <= 1)
        return;

    bool *isPrime = new bool[n+1];
    // bool isPrime[n+1];
    fill(isPrime, isPrime+n+1, true);

    for (int i = 2; i*i <= n; i++) {
        if (isPrimeOptimised(i)) {
            for (int j = i*i; j <= n; j += i)
                isPrime[j] = false;
        }    
    }

    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            cout << i << " ";
    
    cout << endl;
}

int main() {
    int n = 100;
    seive(n);
    return 0;

}