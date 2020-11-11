/*
    Problem Statement:
        Display the kth smallest element given an array and k.
*/

#include <iostream>
#include <queue>
using namespace std;

int kthSmallestElement(int *arr, int k, int n) {
    priority_queue<int> maxh;

    for (int i = 0; i < n; i++) {
        maxh.push(arr[i]);
        if (maxh.size() > k)
            maxh.pop();
    }

    return maxh.top();
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr)/ sizeof(int);
    cout << kthSmallestElement(arr, 3, n) << endl;
    return 0;
}