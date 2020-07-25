/* 
    Problem:
        Given an array of integers, calculate the ratios of its elements that are positive, negative, and zero. Print the decimal value of each fraction on a new line with 6 places after the decimal.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    #ifndef ONLILE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int size;
    cin >> size;

    int temp;
    double negative = 0, zero = 0, positive = 0;
    for (int i = 0; i < size; i++) {
        cin >> temp;
        if (temp < 0)
            negative++;
        else if (!temp)
            zero++;
        else
            positive++;
    }

    cout << fixed << setprecision(6) 
        << positive / size << endl  
        << negative / size << endl
        << zero / size << endl;

    return 0;
}