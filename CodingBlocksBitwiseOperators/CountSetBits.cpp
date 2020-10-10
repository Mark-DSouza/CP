/*
    Problem Statement:
        Count the number of set bits in a number
*/

#include <iostream>
using namespace std;

// Time: O(Number of bits)
int countSetBits(int n) {
    int count = 0;

    while(n) {
        count += n & 1;
        n = n >> 1;
    }

    return count;
}

// Time: O(Number of set bits)
int countSetBitsOptimal(int n) {
    int count = 0;

    while(n) {
        n = n & (n - 1);    // Gets rid of the lowest set bit
        count++;
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    cout << countSetBits(n) << endl
        << countSetBitsOptimal(n) << endl;
    return 0;
}