#include <bits/stdc++.h>
using namespace std;

int maxToys(string toys) {
    int i = 0, j = 0, res = INT_MIN, n = toys.length();
    unordered_map<char, int> mp;

    while (j < n) {
        mp[toys[j]]++;

        if (mp.size() < 2) {
            j++;
        }

        else if (mp.size() == 2) {
            res = max(res, j-i+1);
            j++;
        }

        else if (mp.size() > 2) {
            while (mp.size() > 2) {
                mp[toys[i]]--;
                if (mp[toys[i]] == 0) mp.erase(toys[i]);
                i++;

                if (mp.size() == 2) res = max(res, j-i+1);
            }

            j++;
        }
    }

    return res;
}

int main() {
    string toys = "abacaaccacacab";
    cout << maxToys(toys) << endl;
    return 0;
}