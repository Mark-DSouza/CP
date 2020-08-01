#include <iostream>
using namespace std;

int ninesComplement(int digit) {
    return 9 - digit;
}

typedef long long ll;

int main() {
    ll number, minimum = 0, place = 1;
    cin >> number;

    int digit, complement;
    while(number > 0) {
        digit = number % 10;
        complement = ninesComplement(digit);
        if (complement < digit)
            minimum += place * complement;
        else 
            minimum += place * digit;
        
        place *= 10;
        number /= 10;
    }

    cout << minimum;
}