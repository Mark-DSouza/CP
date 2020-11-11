/*
    Problem Statement:
        Top K Frequent Numbers

        Display the top K Frequent numbers in a given array
*/

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

void topKFrequent(int *arr, int n, int k) {
    unordered_map<int, int> map;
    priority_queue<pii, vector<pii>, greater<pii> > maxh;


    for (int i = 0; i < n; i++)
        map[arr[i]]++;

    for (auto element: map) {
        maxh.push({element.second, element.first});

        if (maxh.size() > k)
            maxh.pop();
    }

    while(maxh.size()) {
        cout << maxh.top().second << " ";
        maxh.pop();
    }
}

int main() {
    int arr[] = {1, 1, 1, 3, 2, 2, 4};
    int n = sizeof(arr)/sizeof(int);
    int k = 2;
    topKFrequent(arr, n, k); 
    return 0;
}