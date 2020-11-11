/*
    Problem Statement:
        Display the count of the number of partitions required to make the input string into 
        a palindrome in each partition
*/

#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(string s, int i, int j) {
    if (i >= j)
        return true;

    while(i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }

    return true;
}

int palPart(string s, int i, int j) {
    if (i >= j)
        return 0;
    
    if (isPalindrome(s, i, j))
        return 0;

    int mn = INT_MAX;
    for (int k = i; k <= j-1; k++) {
        int temp = 1 + palPart(s, i, k) + palPart(s, k+1, j);

        if (temp < mn)
            mn = temp;
    }

    return mn;
}

int main() {
    string s("nitik");
    size_t n = s.size();
    cout << palPart(s, 0, n-1) << endl;
    return 0;
}