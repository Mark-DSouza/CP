/*
    Problem Statement:
        K Closest Numbers

        Display the K closest number to the given number x in the given array
*/ 

#include <iostream>
#include <queue>
using namespace std;

void kClosestNumbers(int *arr, int n, int k, int x) {
    priority_queue<pair<int, int> > maxh;

    for (int i = 0; i < n; i++) {
        maxh.push({abs(arr[i] - x), arr[i]});

        if (maxh.size() > k)
            maxh.pop();
    }

    while(maxh.size()) {
        cout << maxh.top().second << " ";
        maxh.pop();
    }
    cout << endl;
    return;
}

int main() {
    int arr[] = {5, 6, 7 , 8, 9};
    int n = sizeof(arr)/sizeof(int);
    int x = 7;
    int k = 3;
    kClosestNumbers(arr, n, k, x);
    return 0;
}