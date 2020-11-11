#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a%b);
}

// a * b = gcd(a, b) * lcm(a, b)
int lcm(int a, int b) {
    return  a * b / gcd(a, b);
}

int main() {
    int a = 6, b = 8;
    cout << lcm(a, b) << endl;
    return 0;
}