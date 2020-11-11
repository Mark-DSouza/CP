#include <iostream>
using namespace std;

int factorialIterative(int n) {
    if (n == 0)
        return 1;

    int fact = 1;
    while(n) {
        fact *= n;
        n--;
    }

    return fact;
}

int factorialRecursive(int n) {
    // Base case
    if (n <= 1)
        return 1;
    
    // Recursive case
    return n * factorialRecursive(n-1);
}

int main() {
    int n = 6;
    cout << factorialIterative(n) << endl
        << factorialRecursive(n) << endl;
    return 0;
}