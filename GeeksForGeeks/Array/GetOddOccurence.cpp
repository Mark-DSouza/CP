/*
    Problem Statement:
        Given an array of positive integers. All numbers occur even number of times except one number
        which occurs odd number of times. Find it!
*/

#include <iostream>
using namespace std;

// Time: O(N), Space: O(1)
int getOddOccurence(int* a, int n) {
    int res = 0;
    for (int i = 0; i < n; i++ ) {
        res = res ^ a[i];
    }

    return res;
}

int main() {
    int a[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);
    cout << getOddOccurence(a, n) << endl;
    return 0;
}