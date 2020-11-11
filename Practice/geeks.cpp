#include <bits/stdc++.h>
#include <cmath>
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

int exactly3Divisors(int N)
{
    //Your code here
    int n = floor(sqrt(N));
    int *isPrime = new int[n+1];
    fill(isPrime, isPrime+n+1, true);

    for (int i = 2; i*i <= n; i++) {
        if (isPrimeOptimised(i)) {
            for (int j = i*i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    int count = 0;
    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            count++;

    return count;
}

