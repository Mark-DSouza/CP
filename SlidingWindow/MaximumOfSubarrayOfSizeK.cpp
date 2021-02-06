#include <bits/stdc++.h>
using namespace std;

vector<int> maxSub(int arr[], int n, int k) {
    vector<int> v;
    list<int> l;
    int i = 0, j = 0;

    while (j < n) {
        while (l.size() > 0 && l.back() < arr[j]) {
            l.pop_back();
        }
        l.push_back(arr[j]);

        if (j - i + 1 < k) {
            j++;
        }

        if (j - i + 1 == k) {
            v.push_back(l.front());

            if (arr[i] == l.front()) {
                l.pop_front();
            }
            i++;
            j++;
        }
    }

    return v;
}

void show(vector<int> v) {
    for (auto x: v)
        cout << x << " ";
    cout << endl;
}

int main() {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(int);
    int k = 3;
    show(maxSub(arr, n, k));
    return 0;
}