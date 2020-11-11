/*
    Problem Statement:
        Display the count of the total number of ways that the expression can result in true.
*/

#include <iostream>
using namespace std;

int solve(string s, int i, int j, bool isTrue) {
    if (i > j)
        return false;

    if (i == j)
        if (isTrue)
            return s[i] == 'T';
        else    
            return s[i] == 'F';
    
    int ans = 0;
    for (int k = i+1; k <= j-1; k+=2) {
        int lt = solve(s, i, k-1, true),
            lf = solve(s, i, k-1, false),
            rt = solve(s, k+1, j, true),
            rf = solve(s, k+1, j, false);

        if (s[k] == '&')
            if (isTrue)
                ans += lt * rt;
            else 
                ans += lf * rf + lt * rf + lf * rt;
        
        else if (s[k] == '|')
            if (isTrue)
                ans += lt * rt + lt * rf + lf * rt;
            else 
                ans += lf * rf;
        
        else 
            if (isTrue)
                ans += lt * rf + rt * lf;
            else 
                ans += lt * rt + lf * rf;
    }

    return ans;
}

int main() {
    // string s("T|F&T^F");
    string s("T|F&T");
    cout << solve(s, 0, s.size()-1, true) << endl;
    return 0;
}