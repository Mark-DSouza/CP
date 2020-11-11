#include <iostream>
using namespace std;

int lastOccurence(int arr[], int n, int ele) {
    int start = 0;
    int end = n - 1;

    int last = -1;
    while(start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == ele) {
            last = mid;
            
        }
    }
}

int main() {
    int arr[] = {2, 4, 10, 10, 10, 18, 20};
    int n = sizeof(arr)/sizeof(n);
    cout << lastOccurence(arr, n, 10) << endl;
    return 0;
}