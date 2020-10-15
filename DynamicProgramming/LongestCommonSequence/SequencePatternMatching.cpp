/*
    Problem Statement:
        Display Boolean if Pattern a is present in b.
*/

#include <iostream>
using namespace std;

bool patternMatching(string x, string y, size_t m, size_t n) {
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
    
    return t[m][n] == m;
}

int main() {
    string a("axy"), b("adxcpy");
    size_t m = a.size(), n = b.size();
    cout << patternMatching(a, b, m, n) << endl;
    return 0;
}