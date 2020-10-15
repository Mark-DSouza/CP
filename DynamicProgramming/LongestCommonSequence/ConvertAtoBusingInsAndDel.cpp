/*
    Problem Statement:
        Display the minimum number of Deletions and Insertions to convert given string a to given string b
*/

#include <iostream>
using namespace std;

void MinimumInsertionsAndDeletions(string a, string b, size_t m, size_t n) {
    size_t t[m+1][n+1];
    for (size_t i = 0; i <= m; i++)
        t[i][0] = 0;
    for (size_t j = 0; j <= n; j++)
        t[0][j] = 0;
    
    for (size_t i = 1; i <= m; i++)
        for (size_t j = 1; j <= n; j++)
            if (a[i-1] == b[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else 
                t[i][j] = max(t[i-1][j],t[i][j-1]);

    cout << "Deletions: " << m - t[m][n] << "\t" << "Insertions: " << n - t[m][n] << endl;
    return;
}

int main() {
    string a("heap"), b("pea");
    size_t m = a.size(), n = b.size();
    MinimumInsertionsAndDeletions(a, b, m, n);
    return 0;
}