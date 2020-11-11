#include <iostream>
using namespace std;

// gcd(a, b) = gcd(a-b, b) works until a and b are equal or one of them is 0
int gcd(int a, int b) {
    while (a != b) {
        if (a > b)
            a = a - b;
        else 
            b = b - a;
    }

    return a;
}

// Time Complexity: log(min(a, b))
int gcdOptimised(int a, int b) {
    if (b == 0)
        return a;
    
    return gcd(b, a%b);
}
int main() {
    int a = 12, b = 15;
    cout << gcd(a, b) << endl << gcdOptimised(a, b) << endl;
    return 0;
}