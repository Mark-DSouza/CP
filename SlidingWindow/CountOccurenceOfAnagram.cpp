#include <bits/stdc++.h>
using namespace std;

int countOfAnagrams(string s, string ptr) {
    int i(0), j(0), count(0), k(ptr.length()), sizeOfMap;
    unordered_map<char, int> mp;

    for (auto ch: ptr) {
        mp[ch]++;
        // if (mp[ch] == 1) sizeOfMap++;
    }
    sizeOfMap = mp.size();

    while (j < s.length()) {
        if (mp.find(s[j]) != mp.end()) {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                sizeOfMap--;
        }

        if (j - i + 1 < k)
            j++;

        else if (j - i + 1 == k) {
            if (sizeOfMap == 0)
                count++;

            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]]++;
                if (mp[s[i]] == 1)
                    sizeOfMap++;
            }
            i++;
            j++;
        }
    }
    
    return count;
}

int main() {
    string s = "forxxorfxxdofr";
    string ptr = "for";

    cout << countOfAnagrams(s, ptr) << endl;

    return 0;
}