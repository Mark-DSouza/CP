#include <iostream>
#include <math.h>
using namespace std;

int main() {
    #ifndef ONLILE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    long long binary;
    long long decimal;
    int power;
    for (int i = 0; i < n; i++) {
        cin >> binary;

        decimal = 0;
        power = 0;
        while(binary) {
            if(binary & 1)
                decimal += pow(2, power);
            power++;
            binary = binary / 10; 
        }

        cout << decimal << endl;
    }

    return 0;
}