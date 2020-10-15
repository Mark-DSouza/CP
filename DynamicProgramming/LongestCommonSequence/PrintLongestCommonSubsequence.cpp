/*
    Problem Statement:
        Print the Longest Common Subsequence, given 2 strings x and y as input.
*/

#include <iostream>
#include <algorithm>
using namespace std;

string printLCS(string x, string y, size_t m, size_t n) {
    // Longest Common Subsequence
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
            i--;
        }
        else 
            j--;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string x("acbcf"), y("abcdaf");
    size_t m = x.size(), n = y.size();
    cout << printLCS(x, y, m, n) << endl;
    return 0;
}