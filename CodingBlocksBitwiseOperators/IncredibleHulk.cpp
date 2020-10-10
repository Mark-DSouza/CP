/*
    Problem Statement
        Hulk has to jump n levels above his current level in the minimum number of jumps.
        He can only jump in powers of 2. Assume he is on 0th level.

    Input:
        Test Case T with next lines with the levels
*/

// Answer is the number of set bits

#include <iostream>
using namespace std;

int minimumJumps(int n) {
    int count = 0;
    while(n) {
        count++;
        n = n & (n - 1);
    }

    return count;
}

int main() {
    int t;
    cin >> t;
    int n;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << minimumJumps(n) << endl;
    } 
    return 0;
}