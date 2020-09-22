#include <bits/stdc++.h>
using namespace std;

vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> decompressedList;
    for(int i = 0; i * 2 < nums.size(); i++) {
        for(int j = 1; j <= nums[2*i]; j++)
            decompressedList.push_back(nums[2*i + 1]);
    }

    return decompressedList;
}

int main() {
    return 0;
}