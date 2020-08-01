#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string rhombusEnd(n, '*');
    string rhombusBody = string(1, '*') + string(n - 2, ' ') + string(1, '*');
    for (int i = 1; i <= n; i++) {
        for (int j = n - i; j>=0; j--) cout << " ";

        if (i == 1 || i == n) 
            cout << rhombusEnd << endl;

        else
            cout << rhombusBody << endl;
    }

    return 0;
}