/*
    Problem Statement:
        Count the number of trailing zeros in the factorial of a given number.

        Factorial are very large numbers and overflow very easily. A naive approach will not suffice
*/

#include <iostream>
using namespace std;

// This function basically counts the number of 5's in the prime factorisation
// Each 5 when paired with a 2 results in a 10 i.e. a 0
// The 5's will always be less than the 2's, hence we count the 5's
// There are some numbers that have more than one 5 in their prime factorisation. They should be counted
int trailingZeros(int n) {
    int count = 0;
    for (int i = 5; i <= n; i*=5) {
        count += n/i; // floor(n/5), floor(n/25), floor(n/125) -> to account for numbers with one 5, two 5's, ...
    }
    return count;
}

int main() {
    int n = 100;
    cout << trailingZeros(n) << endl;
    return 0;
}