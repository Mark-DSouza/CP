/*
    Problem Statement:
        Clear the ith bit of a number
*/

#include <iostream>
using namespace std;

void clearIthBit(int& n, int i) {
    int mask = ~(1 << i);
    n = n & mask;
}

int main() {
    int n = 13, i = 2;
    clearIthBit(n, i);
    cout << n << endl;
    return 0;
}