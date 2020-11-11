/*
    Problem Statement:
        Sort a K Sorted Array / Nearly Sorted Array

        Sort a K Sorted Array.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> kSort(int *arr, int k, int n) {
    priority_queue<int, vector<int>, greater<int> > minh;
    vector<int> v; 

    for (int i = 0; i < n; i++) {
        minh.push(arr[i]);
        if (minh.size() > k) {
            v.push_back(minh.top());
            minh.pop();
        }
    }

    while(minh.size()) {
        v.push_back(minh.top());
        minh.pop();
    }

    return v;
}

int main() {
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr)/ sizeof(int);
    vector<int> v = kSort(arr, 3,  n);
    for (auto x: v)
        cout << x << " ";
    cout << endl;
    return 0;
}