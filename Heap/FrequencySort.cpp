/*
    Problem Statement:
    Frequency Sort

    Sort the elements of the array based on frequency
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

void frequencySort(vector<int>& v) {
    unordered_map<int, int> map;
    for (int value: v)
        map[value]++;


    priority_queue<pair<int, int> > maxh;
    for (auto element: map) {
        maxh.push({element.second, element.first});
    }

    v.clear();
    while (maxh.size()) {
        auto freq = maxh.top().first;
        auto ele = maxh.top().second;
        for (int i = 1; i <= freq; i++)
            v.push_back(ele);
        maxh.pop();
    }     
}

int main() {
    vector<int> v{1, 1, 1, 3, 2, 2, 4};
    frequencySort(v);

    for (auto element: v)
        cout << element << " ";
    cout << endl;
    return 0;
}