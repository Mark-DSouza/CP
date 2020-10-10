/*
    Problem Statement:
        We are given an array containing n numbers. All the numbers are present twice except for two
        numbers which are present only once. Find the unique numbers in linear time without using any
        space. (Hint - Use Bitwise)
    
    Input Format:
        Firsts line conatins the number n. Second line contains n space separated number;
        n < 10 ^ 5
*/

#include <iostream>
using namespace std;

void uniqueNumbers(int* a, int n) {
    int combinedResult = 0;
    for( int i = 0; i < n; i++)
        combinedResult = combinedResult ^ a[i];

    int mask = 1;
    while(1) {
        if (combinedResult & mask) break;
        mask = mask << 1;
    }

    int firstResult = 0;
    for (int i = 0; i < n; i++ )
        if (a[i] & mask)
            firstResult = firstResult ^ a[i];

    int secondResult = combinedResult ^ firstResult;
    cout << firstResult << endl << secondResult << endl;
}

int main() {
    int a[] = {1, 3, 5, 6, 3, 2, 1, 2};
    int n = sizeof(a) / sizeof(int);
    uniqueNumbers(a, n);
    return 0;
}