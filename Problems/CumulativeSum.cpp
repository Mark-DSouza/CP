#include <iostream>
using namespace std;

int main() {
    #ifndef ONLILE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int input, sum = 0;
    while(1) {
        cin >> input;
        sum += input;
        if (sum < 0)
            break;
        cout << input << '\n';
    }
    return 0;
}