#include <iostream>
#include <math.h>
using namespace std;

void nonDecreasing(double &a, double &b) {
    if (a > b) {
        double temp = a;
        a = b;
        b = temp;
    }

    return;
}

int main() {
    double a, b, c;

    cin >> a >> b >> c;

    double root1, root2, discriminant;
    discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        
        nonDecreasing(root1, root2);
        if (discriminant)
            cout << "Real and Distinct" << endl << root1 << " " << root2;
        
        else
            cout << "Real and Equal" << endl << root1 << " " << root2;
    }

    else
        cout << "Imaginary";

    return 0;
}