#include <bits/stdc++.h>
using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> shuffled;
    for (int i = 0; i < n; i++) {
        shuffled.push_back(nums[i]);
        shuffled.push_back(nums[n + i]);
    }
    return shuffled;

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txtf", "w", stdout);

    vector<int> nums = {2, 5, 1, 3, 4, 7};
    vector<int> shuffled = shuffle(nums, 3);
    for(int x: shuffled)
        cout << x << " ";
    cout << endl;
}