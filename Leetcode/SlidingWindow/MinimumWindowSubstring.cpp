#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    int i(0), j(0), n(s.size()), start(0), end(INT_MAX);
    string res="";
    unordered_map<char, int> mp;

    for (auto ch: t) {
        mp[ch]++;
    }
    int count(mp.size());

    while (j < n) {
        if (mp.find(s[j]) != mp.end()) {
            mp[s[j]]--;
            if (mp[s[j]] == 0) count--;
        }

        if (count > 0) {
            j++;
        }

        else if (count == 0) {
            while (count == 0) {
                if (end - start > j - i) {
                    start = i;
                    end = j;
                }

                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1) count++;
                }

                i++;
            }

            j++;
        }
    }

    if (end - start == INT_MAX) return res;

    return s.substr(start, end - start + 1);
}

int main() {
    // string s = "abcabcbb";
    // string s = "bbbbb";
    // string s = "pwwkew";
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t) << endl;
    return 0;
}