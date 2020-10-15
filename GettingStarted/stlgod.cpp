#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <climits>
// #include <bits/stdc++.h>
using namespace std;
bool f(int x, int y) {return x > y;}

void vectorDemo(void) {
    vector<int> a;
    a.push_back(11);
    a.push_back(2);
    a.push_back(3);
    a.push_back(14);

    // for(auto x: a)
    //     cout << x << endl;

    sort(a.begin(), a.end());
    for (auto x: a)
        cout << x << endl;

    bool present = binary_search(a.begin(), a.end(), 3);
    cout << present << endl;

    present = binary_search(a.begin(), a.end(), 4);
    cout << present << endl;

    a.push_back(100);
    present = binary_search(a.begin(), a.end(), 100);
    cout << present << endl;

    a.push_back(100);
    a.push_back(100);
    a.push_back(100);
    a.push_back(100);
    a.push_back(123);

    vector<int>::iterator it = lower_bound(a.begin(), a.end(), 100);
    vector<int>::iterator it2 = upper_bound(a.begin(), a.end(), 100);

    cout << *it << " " << *it2 << endl;
    cout << it2 - it << endl;

    
    sort(a.begin(), a.end(), f);
    for( int x : a)
        cout << x << endl;

    for (int &x : a)
        cout << ++x << endl;
    for (int x: a)
        cout << x << endl;
}

void setDemo(void) {
    set<int> S;
    S.insert(1);
    S.insert(2);
    S.insert(-1);
    S.insert(-10);

    for (int x: S)
        cout << x << " ";
    cout << endl;

    auto it = S.find(-1);
    if (it == S.end())
        cout << "Not Present" << endl;
    else 
        cout << "Present" << endl;
    cout << endl;

    auto it2 = S.upper_bound(-1);
    auto it3 = S.upper_bound(0);
    cout << *it2 << " " << *it3 << endl;

}

void mapDemo(void) {
    map<char, int> count;
    string x = "ranchit jain";

    for(char c: x)
        count[c]++;

    cout << count['a'] << " " << count['z'] <<endl;
}

int main() {
    set< pair<int, int> > S;
    S.insert({2, 3});
    S.insert({10, 20});
    S.insert({30, 400});
    S.insert({401, 450});

    int point = 12;

    pair<int, int> test = {point, INT_MAX};
    auto it = S.upper_bound(test);

    if (it == S.begin())
        cout << "Could not find the range!" << endl;
    else {
        it--;
        if ()
    }




}