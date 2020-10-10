/*
    Problem Statement:
        Set the ith bit of the number
*/

#include <iostream>
using namespace std;

void setIthBit(int& n, int i) {
    n = n | (1 << i);
    return;
}

int main() {
    int n = 10, i = 2;
    setIthBit(n, i);
    cout << n << endl;
    return 0;
}