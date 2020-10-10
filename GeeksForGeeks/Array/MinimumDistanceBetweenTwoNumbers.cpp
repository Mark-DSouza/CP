#include <iostream>
#include <climits>
using namespace std;

// O(N^2)
int minDist(int *arr, int n, int x, int y) { 
    int min_dist = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if ((arr[i] == x && arr[j] == y || arr[j] == x && arr[i] == y) && (min_dist > abs(i - j)))
                min_dist = abs(i - j);
        }
    }
    return min_dist;
}

// O(N)
int minDistOptimal(int *arr, int n, int x, int y) {
    int minDist = INT_MAX, prev, i;

    for(i = 0; i < n; i++) {
        if (arr[i] == x || arr[i] == y)
            prev = i;
            break;
    }

    for (; i < n; i++) {
        if (arr[i] == x || arr[i] == y) {
            if (arr[prev] != arr[i] && (i - prev) < minDist) {
                minDist = i - prev;
                prev = i;
            }
            else {
                prev = i;
            }
        }
    }

    return minDist;
}

int main() {
    int arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
    // int arr[] = {3, 5, 4, 2, 6, 3, 0, 0, 5, 4, 8, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int y = 6;
    cout << minDist(arr, n, x, y) << endl;
    cout << minDistOptimal(arr, n, x, y) << endl;
    return 0;
}