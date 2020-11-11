#include <iostream>
using namespace std;

int firstOccurence(int arr[], int n, int ele) {
    int start = 0;
    int end = n - 1;

    int first = -1;
    while(start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == ele) {
            first = mid;
            end = mid - 1;
        }
        else if (arr[mid] < ele) 
            start = mid + 1;
        else 
            end = mid - 1;
    }

    return first;
}

int main() {
    int arr[] = {2, 4, 10, 10, 10, 18, 20};
    int n = sizeof(arr)/sizeof(n);
    cout << firstOccurence(arr, n, 10) << endl;
    return 0;
}