#include <iostream>
#include <queue>
using namespace std;

void kClosestPointsToOrigin(int arr[][2], int n, int k) {
    priority_queue<pair<int, pair<int, int> > > maxh;

    for (int i = 0; i < n; i++) {
        int x = arr[i][0];
        int y = arr[i][1];
        int dist = x * x + y * y;
        maxh.push({dist, {x, y}});

        if (maxh.size() > k)
            maxh.pop();
    }

    while(maxh.size()) {
        cout << "(" << maxh.top().second.first << ", " << maxh.top().second.second << ")\t";
        maxh.pop();
    }

    cout << endl;
    return;
}

int main() {
    int points[][2] = {{1, 3}, {-2, 2}, { 5, 8}, {0, 1}};
    int n = sizeof(points)/sizeof(points[0]);
    int k = 2;
    kClosestPointsToOrigin(points, n, k);
    return 0;
}