#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int n) {
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";

            if (n / i != i)
                cout << n / i << " ";
        }
    }
}

void printDivisorsOrdered(int n) {
    int i = 1;
    for (i = 1; i*i <= n; i++)
        if (n % i == 0)
            cout << i << " ";
    
    for (; i >= 1; i--) 
        if (n % i == 0 && i*i != n)
            cout << n / i << " ";
}

int main() {
    int n = 36;
    printDivisors(n);
    cout << endl;
    printDivisorsOrdered(n); 
    return 0;
}