#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int i(0), j(0), n(s.size()), res(0);
    unordered_map<char, int> mp;

    while (j < n) {
        mp[s[j]]++;

        if (mp.size() == j - i + 1) {
            res = max(res, j - i + 1);
            j++;
        }

        else if (mp.size() < j - i + 1) {
            while (mp.size() < j - i + 1) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);
                i++;
                
                if (mp.size() == j - i + 1)
                    res = max(res, j-i+1);
            }

            j++;
        }
    }

    return res;
}

int main() {
    // string s = "abcabcbb";
    // string s = "bbbbb";
    // string s = "pwwkew";
    string s = "";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}