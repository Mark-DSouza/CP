#include <iostream>
using namespace std;

string runPlate(long long plate) {
    int digit, sumOdd = 0, sumEven = 0;
    while(plate > 0) {
        digit = plate % 10;
        
        if (digit & 1)
            sumOdd += digit;
        else 
            sumEven += digit;

        plate /= 10;
    }

    if (!(sumEven % 4) || !(sumOdd % 3))
        return "Yes";
    else
        return "No";
}

int main() {
    int n;
    cin >> n;

    long long plate;
    for (int i = 1; i <= n; i++ ) {
        cin >> plate;
        cout << runPlate(plate) << endl;
    }

    return 0;
}