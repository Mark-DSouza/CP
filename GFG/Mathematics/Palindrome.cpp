#include <iostream>
using namespace std;

bool isPalindrome(int n) {
    int temp = n;
    int rev = 0;
    while(temp) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    return rev == n;
}

int main() {
    int n = 12321;
    cout << isPalindrome(n) << endl;
    return 0;
}