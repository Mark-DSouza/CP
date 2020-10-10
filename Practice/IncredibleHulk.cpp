#include <iostream>
using namespace std;

int minimumJumps(int n) {
    int count = 0;
    while(n) {
        count++;
        n = n & (n - 1);
    }

    return count;
}

int main() {
    int t;
    cin >> t;
    int n;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << minimumJumps(n) << endl;
    } 
    return 0;
}