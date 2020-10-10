/*
    Problem Statements:
        Find all the subsequences of a string.
*/

#include <iostream>
#include <cstring>
using namespace std;

void filterChars(char *a, int number) {
    int i = 0;
    while(number) {
        (number & 1) ? cout << a[i] : cout << "";
        i++;
        number = number >> 1;
    }

    cout << endl;
}

// Generate a range of numbers from 0 to 2^n-1
void generateSubsets(char *a) {
    int n = strlen(a);
    int range = (1 << n) - 1;
    for (int i = 0; i <= range; i++) {
        filterChars(a, i);
    }   
}

int main() {
    char a[100];
    cin >> a;
    generateSubsets(a);
    return 0;
}