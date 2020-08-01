#include <iostream>
using namespace std;

long long factorial(int n) {
    if (!n) 
        return 1;
    
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int main() {
    #ifndef ONLILE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    
    int n;
    cin >> n;

    int number;
    long long sum = 0;
    while(cin >> number) {
        sum += factorial(number) % 107;
    }

    cout << sum % 107;

    return 0;
}