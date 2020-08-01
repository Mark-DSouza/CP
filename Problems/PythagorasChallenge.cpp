#include <iostream>
#include <math.h>
using namespace std;

void dispalyPythagoras(int limit) {
    if ((int) pow(sqrt(limit), 2) == limit)
        cout << "(" << 0 << "," << sqrt(limit) << ")";

    int a, b, c = 0;
    int m = 2;
    while (c * c <= limit) {
        for (int n = 1; n < m; n++) {
            a = m * m - n * n;
            b = 2 * m * n;
            c = m * m + n * n;

            if (c * c > limit)
                break;
            
            else if (c * c == limit)
                cout << "(" << a << "," << b << ")";
        }

        m++;
    }

    cout << endl;
    return;
}

int main() {
    int n;
    cin >> n;

    int limit;
    for(int i = 0; i<n; i++) {
        cin >> limit;
        dispalyPythagoras(limit);   
    }
    return 0;
}