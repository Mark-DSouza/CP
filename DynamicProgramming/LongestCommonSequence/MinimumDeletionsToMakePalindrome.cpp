/*
    Problem Statement:
        Display the Minimum Number of Deletions to convert a given string x into a Palindrome.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int minimumNumberOfDeletions(string x, size_t m) {
    string y(x);
    reverse(y.begin(), y.end());
    
    size_t t[m+1][m+1];
    for (int i = 0; i <= m; i++)
        t[i][0] = 0;
    for (int j = 0; j <= m; j++)
        t[0][j] = 0;
    
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            if (x[i-1] == y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else 
                t[i][j] = max(t[i-1][j], t[i][j-1]);
    
    return m - t[m][m];
}

int main() {
    string x("agbcba");
    size_t m = x.size();
    cout << minimumNumberOfDeletions(x, m) << endl;
    return 0;
}