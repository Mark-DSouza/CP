/*
    Problem Statement:
        Display the K Largest Elements given k and given array
*/

#include <iostream>
#include <queue>
using namespace std;

void kLargestElements(int *arr, int k, int n) {
    priority_queue<int, vector<int>, greater<int> > minh;

    for (int i = 0; i < n; i++) {
        minh.push(arr[i]);

        if (minh.size() > k)
            minh.pop();
    }

    while(minh.size()) {
        cout << minh.top() << " ";
        minh.pop();
    }
    cout << endl;

    return;
}

int main() {
    int arr[] = {1, 10, 4, 3, 20, 15};
    int n = sizeof(arr)/ sizeof(int);
    kLargestElements(arr, 3, n);
    return 0;
}