#include <iostream>
using namespace std;

int longestCommonSum(int *arr1, int *arr2, int n) {
    int maxlen = 0;
    for (int i = 0; i < n; i++) {
        int sum1 = 0, sum2 = 0;
        for (int j = i; j < n; j++) {
            sum1 += arr1[j];
            sum2 += arr2[j];

            if (sum1 == sum2) {
                int len = j - i + 1;
                if(len > maxlen)
                    maxlen = len;
            }
        }
    }

    return maxlen;
}

int longestCommonSumOptimal(int *arr1, int *arr2, int n) {
    int *diff = new int[2 * n  + 1];
    for (int i = 0; i < 2 * n + 1; i++)
        diff[i] = -1;

    int prefixSum1 = 0, prefixSum2 = 0, maxlen = 0;
    for (int i = 0; i < n; i++) {
        prefixSum1 += arr1[i];
        prefixSum2 += arr2[i];

        int currentDiff = prefixSum1 - prefixSum2;
        int diffIndex = prefixSum1 - prefixSum2;

        if (diffIndex == 0)
            maxlen = i + 1;

        else if (diff[n + diffIndex] == -1)
            diff[n + diffIndex] = i;

        else {
            int len = i - diff[diffIndex];
            if (len > maxlen)
                maxlen = len;
        }
    }

    return maxlen;
}

int main() {
    int arr1[] = {0, 1, 0, 1, 1, 1, 1};
    int arr2[] = {1, 1, 1, 1, 1, 0, 1};
    cout << longestCommonSumOptimal(arr1, arr2, 7) << endl;
    return 0;
}