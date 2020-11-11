#include <iostream>
#include <cmath>
using namespace std;

int countDigitsIterative(int n) {
    int count = 0;  
    while (n != 0) {
        n /= 10;
        count++;
    }

    return count;
}

int countDigitsRecursive(int n) {
    // Base case
    if (n == 0)
        return 0;
    
    // Recursive case
    return 1 + countDigitsRecursive(n / 10);
}

int countDigitsConstant(int n) {
    return floor(log10(n) + 1);  // Upper bound of log10(n)
}

int main() {
    int n = 123;
    cout << countDigitsIterative(n) << endl 
        << countDigitsRecursive(n) << endl
        << countDigitsConstant(n) << endl;
    return 0;
}