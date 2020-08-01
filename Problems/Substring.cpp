#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    #ifndef ONLILE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int n, q;
    cin >> n;
    cin >> q;

    vector<string> stringVector;
    string str;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        stringVector.push_back(str);
    }


    string query;
    for (int i = 1; i <= q; i++) {
        cin >> query;
        int count = 0;
        for (string word: stringVector) {
            if (query == word.substr(0, query.length() - 1))
                count++;
        }

        cout << count << endl;
    }

    return 0;
}