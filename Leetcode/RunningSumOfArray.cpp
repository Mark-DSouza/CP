#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    int currentSum = 0;
    vector<int> sums;
    for (int x: nums) {
        currentSum += x;
        sums.push_back(currentSum); 
    }

    return sums; 
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    // vector<int> nums = {1,1,1,1,1};
    // vector<int> nums = {1, 2, 3, 4};
    vector<int> nums = {3, 1, 2, 10, 1};

    vector<int> sums = runningSum(nums);

    for (int x: sums)
        cout << " " << x;
    cout << endl;

    return 0;

}