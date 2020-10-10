#include <iostream>
using namespace std;

int findCandidate(int* arr, int n) {
    int maj_index = 0, count = 1;

    for(int i = 1; i < n; i++ ) {
        if (arr[maj_index] == arr[i])
            count++;
        else
            count--;
        
        if (count == 0) {
            maj_index = i;
            count = 1;
        }
    }

    return arr[maj_index];
}

bool isMajority(int* arr, int n, int cand) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == cand)
            count++;
    }

    if (count > n / 2)
        return true;
    return false;
}

void printMajority(int* arr, int n) {
    bool isMaj = isMajority(arr, n, findCandidate(arr, n));

    if (isMaj)
        cout << endl;
}

int main() {
    int arr[] = {1, 1, 2, 1, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printMajority(arr, n);
    return 0;
}