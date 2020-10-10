#include <bits/stdc++.h>
using namespace std;

void countSortComplete(vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> frequency(range);
    for(int x: arr)
        frequency[x - min]++;

    for(int i = 1; i < range; i++)
        frequency[i] += frequency[i - 1];

    vector<int> result(arr);
    for(int x: arr)
        result[frequency[x - min]-- - 1] = x;

    arr = result;
}

void printVector(vector<int>& arr) {
    for(auto x: arr)
        cout << x << "\t" ;
    cout << endl;
}

int main() {
    vector<int> arr = { -5, -10, 0, -3, 8, 5, -1, 10 };
    countSortComplete(arr);
    printVector(arr);
    return 0;
}