/*
    Problem Statement:
        Display the length of the Longest Common Subsequence, given 2 strings x and y as input.
*/

#include <iostream>
#include <cstring>
using namespace std;

int lcsRecursive(string x, string y, size_t m, size_t n) {

    // base condition
    if (m == 0 || n == 0)
        return 0;

    // recursive condition(Choice Diagram)
    else {
        if (x[m-1] == y[n-1])
            return 1 + lcsRecursive(x, y, m-1, n-1);

        else 
            return max(lcsRecursive(x, y, m-1, n), lcsRecursive(x, y, m, n-1));
    }
}

int lcsTopDown(string x, string y, size_t m, size_t n, int **t) {
    // base condition
    if (m == 0 || n == 0)
        return 0;
    
    // Memoization Check
    if (t[m][n] != -1)
        return t[m][n];

    // Choice Diagram
    else {
        if (x[m-1] == y[n-1])
            return t[m][n] = 1 + lcsTopDown(x, y, m-1, n-1, t);
        
        else 
            return t[m][n] = max(lcsTopDown(x, y, m, n-1, t), lcsTopDown(x, y, m-1, n, t));
    }
}

int lcsBottomUp(string x, string y, size_t m, size_t n) {
    int **t = new int*[m+1];
    for(int i = 0; i <= m; i++)
        t[i] = new int[n+1];

    // Initialization
    for(int i = 0; i <= m; i++)
        t[i][0] = 0;
    for(int j = 0; j <= n; j++)
        t[0][j] = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if (x[i-1] == y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            
            else 
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }

    return t[m][n];
}

int main() {
    string x("abcdgh"), y("abdefhr");
    size_t m = x.size();
    size_t n = y.size();

    cout << lcsRecursive(x, y, x.size(), y.size()) << endl;

    int **t = new int*[m+1];
    for (int i = 0; i <= m; i++)
        t[i] = new int[n+1];
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++)
            t[i][j] = -1;
    cout << lcsTopDown(x, y, m, n, t) << endl;

    cout << lcsBottomUp(x, y, m, n) << endl;
    return 0;
}