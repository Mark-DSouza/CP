/*
    Problem Statement:
        Print the Shortest Common Supersequence.
*/

#include <iostream>
#include <algorithm>
using namespace std;

string printShortestCommonSupersequence(string x, string y, size_t m, size_t n) {
    size_t t[m+1][n+1];

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
    
    // Backtracking
    string result;
    int i = m, j = n;
    while(i > 0 && j > 0) {
        if (x[i-1] == y[j-1]) {
            result.push_back(x[i-1]);
            i--;
            j--;
        }

        else if (t[i-1][j] > t[i][j-1]) {
            result.push_back(x[i-1]);
            i--;
        }

        else {
            result.push_back(y[j-1]);
            j--;
        }
    }

    // Print the remaining non-LCS part before the beginning of the sequence
    while(i > 0) {
        result.push_back(x[i-1]);
        i--;
    }

    while(j > 0) {
        result.push_back(y[j-1]);
        j--;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string x("acbcf"), y("abcdaf");
    size_t m = x.size(), n = y.size();
    cout << printShortestCommonSupersequence(x, y, m, n) << endl;
    return 0;
}