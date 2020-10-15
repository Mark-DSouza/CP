/* 
    Problem Statement:
        Display the length of the Longest Common Substring given two strings x and y as input.
*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int longestCommonSubstring(string x, string y, size_t m, size_t n) {
    // int **t = new int*[m+1];
    // for (int i = 0; i <= m; i++)
    //     t[i] = new int[n+1];

    int t[m+1][n+1];

    // Initialization
    for (int i = 0; i <= m; i++)
        t[i][0] = 0;
    for (int i = 0; i <= n; i++)
        t[0][i] = 0;

    // Iteration
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i-1] == y[j-1])   // The current states match so the length of substring is 1 + previous state
                t[i][j] = 1 + t[i-1][j-1];
            
            else 
                t[i][j] = 0;    // The current states do not match so the length of current substring is 0
        }
    } 

    int result = INT_MIN;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            result = max(result, t[i][j]);
    return result;
}

int main() {
    string x("abcde"), y("abfce");
    size_t m = x.size(), n = y.size();
    cout << longestCommonSubstring(x, y, m, n) << endl;
    return 0;
}