#include <iostream>
using namespace std;

int main() {
    char character;
    cin >> character;

    if (character >= 'a' && character <= 'z')
        cout << "lowercase";
    else if (character >= 'A' && character <= 'Z')
        cout << "UPPERCASE";
    else
        cout << "Invalid";
    
    return 0;
}