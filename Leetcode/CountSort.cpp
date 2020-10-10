#include <bits/stdc++.h>
using namespace std;

vector<int> countSort(vector<int>& nums) {
    vector<int> frequency(101);

    for(int x: nums)
        frequency[x]++;

    for(int i = 1; i <= 100; i++) {
        frequency[i] = frequency[i - 1] + frequency[i];
    }

    vector<int> result(nums);
    for(int x: nums) {
        result[frequency[x]-- - 1] = x;
    }

    return result;
}

int main() {
    vector<int> nums({1,4,1,2,7,5,2});
    nums = countSort(nums);


    for(int x: nums)
        cout << x << endl;
    cout << endl;
    return 0;
}