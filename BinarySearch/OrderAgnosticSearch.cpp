#include <iostream>
using namespace std;

int asc(int arr[], int n, int ele) {
    int start = 0;
    int end = n - 1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == ele)
            return mid;
        else if (arr[mid] < ele)
            start = mid + 1;
        else 
            end = mid - 1; 
    }

    return -1;
}

int desc(int arr[], int n, int ele) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[ mid] ==  ele)
            return mid;
        else if (arr[mid] < ele) 
            end = mid - 1;
        else 
            start = mid + 1;
    }

    return -1;
}

int binarySearch(int arr[], int n, int ele) {
    if (arr[0] <= arr[n-1])
        return asc(arr, n, ele);
    else 
        return desc(arr, n, ele);
}

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/ sizeof(int);
    cout << binarySearch(arr, n, 7) << endl;
    return 0;
}