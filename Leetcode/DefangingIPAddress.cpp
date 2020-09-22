#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string defangIPaddr(string address) {
    for (size_t i = 0;; i++) {
        if (address[i] == '.') {
            address.replace(i, 1, string("[.]"));
            i+=2;
        }

        if (i == address.size() - 1) break;
    }

    return address;
}

int main() {
    string address = "1.1.1.1";
    cout << defangIPaddr(address) << endl;
    return 0;
}