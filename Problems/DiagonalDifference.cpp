/* 
    Problem:
        Given a square matrix, calculate the absolute difference between the sums of its diagonals.
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    #ifndef ONLILE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int size;
    cin >> size;

    int leftDiagonal = 0, rightDiagonal = 0;
    vector<vector<int> > matrix(size, vector<int> (size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
            if (i == j) leftDiagonal += matrix[i][j];
            if (j == size - 1 - i) rightDiagonal += matrix[i][j];
        }
    }

    cout << abs(leftDiagonal - rightDiagonal);

    return 0;
}