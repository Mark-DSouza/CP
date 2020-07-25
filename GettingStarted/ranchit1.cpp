#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

bool comp(int x, int y) {
    return x > y;
}

void vectors() {
    vector<int> A = {11, 2, 3, 14};
    
    cout << A[1] << endl; // 2

    sort(A.begin(), A.end());   // O(NlogN);
    // 2, 3, 11, 14
    
    bool present = binary_search(A.begin(), A.end(), 3); // true;
    cout << present << endl;
    present = binary_search(A.begin(), A.end(), 4); // false
    cout << present << endl;

    A.push_back(100);
    present = binary_search(A.begin(), A.end(), 100);
    cout << present << endl;

    // 2, 3, 11, 14, 100
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);
    // 2, 3, 11, 14, 100, 100, 100, 100, 100, 123

    // vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100); // >=
    // vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100); // >

    // cout << *it << " " << *it2 << endl; // 100 123
    // cout << it2 - it << endl; //5

    // // Sort a vector in descending order
    // sort(A.begin(), A.end(), comp);
    // vector<int>::iterator it3;
    // for (it3 = A.begin(); it3 != A.end(); it3++)
    //     cout << *it3 << " ";
    // cout << endl;

    auto it = lower_bound(A.begin(), A.end(), 100);
    auto it2 = upper_bound(A.begin(), A.end(), 100);
    cout << *it << " " << *it2 << endl;
    cout << it2 - it << endl;   // O(1)


    // Sort a vector in descending order
    sort(A.begin(), A.end(), comp);

    for (int x: A)
        cout << x << " ";
    cout << endl;

    for (int &x: A) {
        x++;
    }
    for (int x: A) {
        cout << x << " ";
    }
    cout << endl;
}

void sets() {
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(-1);
    s.insert(-10);

    for (int x : s)
        cout << x << " ";
    cout << endl;

    auto it = s.find(1);
    if (it == s.end())
        cout << "\nNot present"  << endl;
    else 
        cout << "\nPresent: " << *it << endl;
    
    auto it2 = s.upper_bound(-1);
    auto it3 = s.upper_bound(0);
    cout << *it2 << " " << *it3 << endl;

    auto it4 = s.upper_bound(2);
    if (it4 == s.end())
        cout << "Oops, cannot find that!" << endl;

    return;
}

void maps() {
    map<int, int> m;
    m[7] = 69;
    m[3] = 43;
    m[2] = 54;
    m[1432142] = 424;

    map<char, int> count;
    string name = "Mark D'Souza";

    for (char c: name)
        count[c]++;

    for (char c: name)
        cout << "\nThe frequency of " << c << " in my name is " << count[c] << endl;
}

int main() {
    vectors();
    sets();
    maps();
    return 0;
}