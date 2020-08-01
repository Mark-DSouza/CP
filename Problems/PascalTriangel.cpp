#include <iostream>
using namespace std;

int factorial(int n) {
    if (!n)
        return 1;
    
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    #ifndef ONLILE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int lines;
    cin >> lines;

    // cout << combination(0, 0) << endl;
    // cout << combination(1, 0) << endl;
    // cout << combination(1, 1) << endl;
    // cout << combination(2, 0) << endl;
    // cout << combination(2, 1) << endl;
    // cout << combination(2, 2) << endl;
    // cout << combination(3, 0) << endl;
    // cout << combination(3, 1) << endl;
    // cout << combination(3, 2) << endl;
    // cout << combination(3, 3) << endl;
    // cout << combination(4, 0) << endl;
    // cout << combination(4, 1) << endl;
    // cout << combination(4, 2) << endl;
    // cout << combination(4, 3) << endl;
    // cout << combination(4, 4) << endl;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j <= i; j++) {
            cout << combination(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}