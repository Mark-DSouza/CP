/*
    Problem Statement:
        Display the Length of the Longest Repeating Subsequence.
*/

#include <iostream>
using namespace std;

int longestRepeatingSubsequence(string x, size_t m) {
    size_t t[m+1][m+1];
    string y(x);

    for (int i = 0; i <= m; i++)
        t[i][0] = 0;
    for (int j = 0; j <= m; j++)
        t[0][j] = 0;
    
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            if (x[i-1] == y[j-1] && i != j)
                t[i][j] = 1 + t[i-1][j-1];
            else 
                t[i][j] = max(t[i-1][j], t[i][j-1]);
    
    return t[m][m];
}

int main() {
    string x("aabebcdd");
    size_t m = x.size();
    cout << longestRepeatingSubsequence(x, m) << endl;
    return 0;
}