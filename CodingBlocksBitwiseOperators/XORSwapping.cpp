/*
    Problem Statement:
        Swap 2 numbers using XOR operations
*/

#include <iostream>
using namespace std;

void XORSwapping(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return;
}

int main() {
    int a = 5, b = 7;
    XORSwapping(a, b);
    cout << a << endl << b << endl;
    return 0;
}