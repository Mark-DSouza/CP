/* 
    Problem Statement:
        Display the length of the Longest Palindromic Subsequence given string x.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int longestPalindromicSubsequence(string x, size_t m) {
    string y(x);
    reverse(y.begin(), y.end());
    
    size_t t[m+1][m+1];
    for (auto& col: t)
        col[0] = 0;
    for (auto& firstRowElement: t[0])
        firstRowElement = 0;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++) 
            if (x[i-1] == y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
        else
            t[i][j] = max(t[i-1][j], t[i][j-1]);
    
    return t[m][m];
}

int main() {
    string x("agbcba");
    size_t m = x.size();
    cout << longestPalindromicSubsequence(x, m) << endl;
    return 0;
}