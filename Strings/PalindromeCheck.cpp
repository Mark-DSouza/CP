/*
    Problem Statement:
        Check if a given string is a palindrome.
*/

#include <bits/stdc++.h>
using namespace std;

// Naive Method
// Reverse the original string and compare it
bool isPalNaive(string str) {
    string rev = str;
    reverse(rev.begin(), rev.end());
    return (rev == str);
}
// Space: Theta(n)
// Time: Theta(n)

// Efficient
// Initialize 2 indices at first and last position. If they are equal, increment and decrement resp.
// If they cross or become equal, return true.
bool isPal(string &str) { // String will be copied if you don't use &str
  int begin = 0;
  int end = str.length();
  while (begin < end) {
    if (str[begin] != str[end]) {
      return false;
    }
    begin++;
    end--;
  }

  return true;
}
// Time: O(n), Space: O(1)

int main() {
    string str = "abba";
    cout << isPal(str) << endl;
    return 0;
}
