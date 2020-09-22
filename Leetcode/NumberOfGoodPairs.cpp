#include <bits/stdc++.h>
using namespace std;

// double factorial(int n) {
//     double fact = 1;
//     while(n) {
//         fact *= n;
//         n--;
//     }

//     return fact;
// }

// int pairs(int n) {
//     return factorial(n) / (factorial(n - 2) * factorial(2)); 
// }

// int numIdenticalPairs(vector<int>& nums) {
//     unordered_map<int, int> count;
//     for(int x: nums)
//         count[x]++;

//     int pair = 0;
//     for(auto x: count){
//         if (x.second > 1)
//             pair += pairs(x.second);
//     }

//     return pair;
// }

int numIdenticalPairs(vector<int>& nums) {
    int count[101] = {0};   // To keep count of the number of occurence of a any number from 1 to 100
    int pairs = 0;
    for(int x: nums) {
        pairs += count[x];  // The number of new pairs is 1 less than the number of occurence for a given x
        count[x]++;         // Hence we increment count after adding to pairs
    }

    return pairs;
}


int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    // vector<int> nums = {1, 1, 1, 1};

    cout << numIdenticalPairs(nums) << endl;
    return 0;
}