#include <bits/stdc++.h>
using namespace std;

int xorOperation(int n, int start) {
    int XOR = start;
    for(int i = 1; i < n; i++) {
        XOR = XOR ^ (start + i * 2);
    }

    return XOR;
}

int main() {
    return 0;
}