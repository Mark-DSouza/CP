#include <iostream>
using namespace std;

// Time: O(Number of bits)
int countSetBits(int n) {
    int count = 0;
    while(n) {
        if (n & 1)
            count++;
        n = n >> 1;
    }
    return count;
}

// Time: O(Number of set bits)
int countSetBitsOptimal(int n) {
    int count = 0;
    while(n) {
        count++;
        n = n & (n - 1);    // Gets rid of lowest set bit
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