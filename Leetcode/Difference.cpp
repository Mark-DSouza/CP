#include <bits/stdc++.h>
using namespace std;

int subtractProductAndSum(int n) {
    int sum(0), product(1);
    while(n) {
        int digit(n % 10);
        sum += digit;
        product *= digit;
        n /= 10;
    }

    return product - sum;
}

int main() {
    return 0;
}