#include <bits/stdc++.h>
using namespace std;


// O(N), S(N)
// string restoreString(string s, vector<int>& indices) {
//     string restored(s);
//     int pos;
//     for(int i = 0; i < s.size(); i++) {
//         pos = indices[i];
//         restored[pos] = s[i];
//     }
// }

// O(N), S(1)
string restoreString(string s, vector<int>& indices) {
    int i = 0;
    while(i < indices.size()) {
        if (i == indices[i]) i++;   // If char is in correct position go to next position

        else {
            swap(s[i], s[indices[i]]);  // Swaps current char to correct position
            swap(indices[i], indices[indices[i]]);  // Swaps corresponding indices to correct for char swap
        }
    }

    return s;
}

int main() {

    return 0;
}