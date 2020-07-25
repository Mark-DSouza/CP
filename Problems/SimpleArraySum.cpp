#include <iostream>
using namespace std;

int main() {
    #ifndef ONLILE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    long int sum = 0;
    
    int size;
    cin >> size;
    for (int i = 0, current; i < size; i++ ) {
        cin >> current;
        sum += current;
    }

    cout << sum;
    return 0;
}