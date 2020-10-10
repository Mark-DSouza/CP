#include <iostream>
using namespace std;

int sumOfNaturals(int n) {
    return n * (n + 1) / 2;
}

int main() {
    cout << sumOfNaturals(3) << endl;
    return 0;
}