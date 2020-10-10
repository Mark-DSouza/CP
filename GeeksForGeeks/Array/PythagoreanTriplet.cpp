/*
    Problem Solving:
        Given an array of integers, writes a function that returns true if there is a 
        triplet (a, b, c) that satisfies a^2 + b^2 = c^2
*/

#include <iostream>
#include <algorithm>
using namespace std;

// O(N^3)
// Returns true if there is Pythagorean triplet in a[0..n-1]
bool isTriplet(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                // Calculate square of array elements
                int x = a[i] * a[i], y = a[j] * a[j], z = a[k] * a[k];

                if (x == y + z || y == x + z || z == x + y)
                    return true;
            }
        }
    }

    // If we reach here, no triplet found
    return false;
}


// O(N^2)
bool isTripletOptimal(int* a, int n) {
    for (int i = 0; i < n; i++)             // O(N)
        a[i] *= a[i];

    sort(a, a + n);                         // O(N logN)

    for (int i = n - 1; i >= 2; i--) {
        int l = 0;
        int r = i -1;

        while(l < r) {                      // O(N^2)
            if (a[l] + a[r] == a[i])
                return true;

            else
                (a[l] + a[r] < a[i]) ? l++ : r--; 
        }
        
    }

    return false;
}

int main() {
    int a[] = {1, 4, 3, 7, 5};
    int n = sizeof(a)/sizeof(a[0]);
    cout << isTriplet(a, n) << endl
        << isTripletOptimal(a, n) << endl;
    return 0;
}