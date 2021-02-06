#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)  {
    int i(0), j(0), n(nums.size());
    list<int> l;
    vector<int> v;

    while (j < n) {
        while (l.size() > 0 && l.back() < nums[j])
            l.pop_back();
        l.push_back(nums[j]);

        if (j - i + 1 < k) {
            j++;
        }

        else if (j - i + 1 == k) {
            v.push_back(l.front());

            if (l.front() == nums[i])
                l.pop_front();
            i++;
            j++;
        }

    }

    return v;
}

int main() {
    vector<int> nums = {9, 11};
    int k = 2;

    vector<int> res = maxSlidingWindow(nums, k);
    for (auto x: res)
        cout << x << " ";
    cout << endl;
}