#include <bits/stdc++.h>
using namespace std;

int numberOfSteps (int num) {
    int count = 0;
    while(num){
        if (num & 1)
            num--;
        else
            num >> 1;
        
        count++;
    }
    return count;
}

int main() {
    int num = 14;
    cout << numberOfSteps(num);
    return 0;
}
