#include <iostream>
using namespace std;

// O(n)
int getMissingNo(int *a, int n) {
    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++) 
        total -= a[i];
    return total;
}

// O(N)
// This implementation is better because we may exceed INT_MAX with the previous implementation for large array
int getMissingNoXOR(int *a, int n) {
    int x1 = 1;
    int x2 = a[0];
    for (int i = 1; i < n; i++)
        x2 = x2 ^ a[i];

    for (int i = 2; i <= n + 1; i++ ) 
        x1 = x1 ^ i;

    return x1 ^ x2; 
}

int main() {
    int a[] = {1, 2, 4, 5, 6};
    cout << getMissingNo(a, 5) << endl;
    cout << getMissingNoXOR(a, 5) << endl;
    return 0;
}