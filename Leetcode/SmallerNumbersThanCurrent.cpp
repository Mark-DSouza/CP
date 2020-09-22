#include <bits/stdc++.h>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int> nums) {
    vector<int> frequency(101);         // The number of elements at each index
    vector<int> compoundFrequency(101); // The number of elements smaller than the current index
    vector<int> result;                 // The compoundFrequency of only the elements in nums

    for(int x: nums)
        frequency[x]++;
    
    for(int i = 1; i <= 100; i++) {
        compoundFrequency[i] = compoundFrequency[i - 1] + frequency[i - 1];
    }

    for(int x: nums)
        result.push_back(compoundFrequency[x]);
    
    return result;
}

int main() {
    return 0;
}