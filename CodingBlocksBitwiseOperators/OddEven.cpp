/*
    Problem Statement:
        Find if a number is even or odd
*/

#include <iostream>
using namespace std;

void isOddOrEven(int n) {
    if (n & 1)
        cout << "Odd" << endl;
    else
        cout << "Even" << endl;
}

int main() {
    int n = 8;
    isOddOrEven(n);
    return 0;
}