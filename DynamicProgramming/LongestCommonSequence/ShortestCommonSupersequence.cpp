/*
    Problem Statement:
        Display the length of the Shortest Common Supersequence, given 2 strings x and y as input.
*/

#include <iostream>
using namespace std;

int shortestCommonSupersequence(string x, string y, size_t m, size_t n) {
    int t[m+1][n+1];
    for (int i = 0; i <= m; i++)
        t[i][0] = 0;
    for (int j = 0; j <= n; j++)
        t[0][j] = 0;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (x[i-1] == y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else 
                t[i][j] = max(t[i-1][j], t[i][j-1]);

    return m + n - t[m][n];
}

int main() {
    string x("geek"), y("eke");
    size_t m = x.size(), n = y.size();
    cout << shortestCommonSupersequence(x, y, m, n) << endl;
    return 0;
}