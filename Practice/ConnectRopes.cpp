/*
    Problem Statement:
        Find the minimum cost of connecting all the ropes if the cost of connecting any 2 ropes is the sum
        of their lengths
*/

#include <iostream>
#include <queue>
using namespace std;

int minCost(int *arr, int n) {
    priority_queue<int, vector<int>, greater<int> > minh;
    int cost = 0;
    for (int i = 0; i < n; i++)
        minh.push(arr[i]);

    while(minh.size() > 1) {
        int rope1 = minh.top();
        minh.pop();
        int rope2 = minh.top();
        minh.pop();

        cost += rope1 + rope2;
        minh.push(rope1 + rope2);
    }

    return cost;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    cout << minCost(arr, n) << endl;
    return 0;
}