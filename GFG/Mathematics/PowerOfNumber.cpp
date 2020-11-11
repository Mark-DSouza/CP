#include <iostream>
using namespace std;

// Time Complexity: O(log N)
int pow(int base, int exponent) {
    if (exponent == 0)
        return 1;

    else 
        if (exponent & 1)       // If the exponent is odd
            return pow(base, exponent/2) * pow(base, exponent/2) * base;
        else                    // If the exponent is even
            return pow(base, exponent/2) * pow(base, exponent/2);
}

int main() {
    cout << pow(2, 8) << endl;
    return 0;
}