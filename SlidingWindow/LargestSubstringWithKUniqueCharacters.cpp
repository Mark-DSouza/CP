#include <bits/stdc++.h>
using namespace std;

int largestSubstring(string s, int k) {
    int i = 0, j = 0;
    int n = s.length();
    int res = INT_MIN;
    unordered_map<char, int> mp;

    while(j < n) {
        mp[s[j]]++;

        if (mp.size() < k) {
            j++;    
        }

        else if (mp.size() == k) {
            res = max(res, j - i + 1);
            j++;
        }

        else if (mp.size() > k) {
            while (mp.size() > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);
                i++;

                if (mp.size() == k) res = max(res, j - i + 1);
            }

            j++;
        }
    }

    return res;
}

int main() {
    string s = "aabacbebebe";
    int k = 3;
    cout << largestSubstring(s, k) << endl;
    return 0;
}