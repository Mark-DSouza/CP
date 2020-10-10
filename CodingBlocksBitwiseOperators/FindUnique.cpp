/*
    Problem Statement:
        You are given a list of numbers where every number is occuring twice except one number. 
        Find the unique nubmer.
*/

#include <iostream>
using namespace std;

int findUnique(int *a, int n) {
    int result = 0;
    for (int i = 0; i < n; i++)
        result = result ^ a[i];
    return result;
}

int main() {
    int a[] = {5, 2, 6, 9, 2, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    cout << findUnique(a, n) << endl;
    return 0;
}