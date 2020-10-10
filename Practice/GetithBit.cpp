#include <iostream>
using namespace std;

int getIthBit(int n, int i) {
    return n & (1 << i) ? 1 : 0;
}

int main() {
    cout << getIthBit(10, 3) << endl;
    return 0;
}