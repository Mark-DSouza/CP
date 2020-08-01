#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) 
        return b;
    
    else if (b == 0)
        return a;

    else
        return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    int a, b;
    cin >> a;
    for (int i = 2; i <= n; i++) {
        cin >> b;
        a = gcd(a, b);
    }

    cout << a;
    return 0;
}


// #include <iostream>
// using namespace std;

// int gcd(int a, int b) {
//     if (b == 0) 
//         return a;
//     else
//         return gcd(b, a % b);
// }

// int findGCD(int *array, int n) {
//     int result = array[0];

//     for (int i = 1; i < n; i++) {
//         result = gcd(array[i], result);
//     }

//     return result;
// }

// int main() {
//     int n;
//     cin >> n;

//     int array[10];
//     for (int i = 0; i < n; i++) 
//         cin >> array[i];

//     cout << findGCD(array, n);
//     return 0; 
// }