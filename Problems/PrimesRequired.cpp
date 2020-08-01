#include <iostream>
using namespace std;

#define RANGE 1000000000

void primeSieve(long long *primes) {
    // All odd numbers are marked as prime for the time being
    for (long long i = 3; i <= RANGE; i+=2)
        primes[i] = 1;
    
    // The multiples of a prime i, from i*i onwards are marked as composite
    for (long long i = 3; i <= RANGE; i+=2) {
        if (primes[i]) {
            for (long long j = i*i; j <= RANGE; j = j + i)
                primes[j] = 0;
        }
    }

    // Special Cases
    primes[2] = 1;
    primes[0] = primes[1] = 0;
    return;
}

int main() {
    #ifndef ONLILE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    long long cases;
    cin >> cases;

    long long primes[1000000001] = {0};
    primeSieve(primes);
    
    long long primesRequired;
    for (long long i = 0; i < cases; i++) {
        cin >> primesRequired;

        long long k = 0, j = 0;
        while (j < primesRequired) {
            if (primes[k++]) j++;
        }

        cout << k-1 << endl;
    }
    return 0;
}