/*
    Problem Statement:
        Lucky Numbers: 4, 7, 44, 47, 74, 77, 444, 447, 474, 477,
        Find the position of the given number
*/

#include <iostream>
using namespace std;

int position(int n) {
    int count = 0;
    int pos = 0;
    int temp = n;
    while(temp) {
        count++;
        pos += (1 << count);
        temp /= 10;
    }
    pos -= 1 << count;

    int i = 0;
    while(n) {
        int rem = n % 10;
        if (rem == 7) pos += (1 << i);
        i++;
        n /= 10; 
    }
    return pos + 1;
}

int main() {
    int n = 74;
    cout << position(n) << endl;
    return 0;
}