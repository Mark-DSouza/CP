#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegative(int arr[], int n, int k) {
    int i(0), j(0);
    vector<int> v;
    list<int> l;

    while (j < n) {
        if (arr[j] < 0) {
            l.push_back(arr[j]);
        }

        if (j - i + 1 < k)
            j++;

        else if (j - i + 1 == k) {
            if (l.size() ==  0)
                v.push_back(0);
            else {
                v.push_back(l.front());
                if (l.front() == arr[i])
                    l.pop_front();
            }

            i++;
            j++;
        }
    }

    return v;
}

void show(vector<int> vec) {
    for (auto x: vec) {
        cout << x << " ";
    }

    cout << endl;
}

int main() {
    int arr[] = {12, -1, -7, 8, -15, 30, 13, 28};
    int n = sizeof(arr) / sizeof(int);
    int k = 3;
    show(firstNegative(arr, n, k));
    return 0;
}