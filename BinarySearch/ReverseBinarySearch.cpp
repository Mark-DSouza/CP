#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int ele) {
    int start = 0;
    int end = n - 1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == ele)
            return mid;
        else if (arr[mid]< ele)
            end = mid -1;
        else 
            start = mid + 1;
    }

    return -1;
}

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/ sizeof(int);
    cout << binarySearch(arr, n, 8) << endl;
    return 0;
}