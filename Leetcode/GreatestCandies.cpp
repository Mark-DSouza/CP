#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int max = *max_element(candies.begin(), candies.end());
    vector<bool> output;
    for(int x: candies) {
        if (x + extraCandies >= max)
            output.push_back(true);
        else
            output.push_back(false);
    }

    return output;
}

int main() {
    return 0;
}