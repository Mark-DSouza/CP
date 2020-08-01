/*
    Pattern:
    1
    11
    202
    3003
    40004
*/

#include <iostream>
using namespace std;

int main() {
    #ifndef ONLILE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int lines;
    cin >> lines;

    for (int i = 1; i <= lines; i++) {
        if (i == 1) {
            cout << 1 << endl;
            continue;
        }

        for (int j = 1; j <= i; j++) {
            if (j == 1) cout << i - 1;
            else if (j == i) cout << i - 1;
            else cout << 0;
        }

        cout << endl;
    }
}