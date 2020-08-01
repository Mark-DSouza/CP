#include <iostream>
using namespace std;

int determineQuad(int x, int y) {
    if (x > 0 && y > 0) 
        return 1;
    else if (x < 0 && y > 0)
        return 2;
    else if (x < 0 && y < 0)
        return 3;
    else
        return 4;
}

int main() {
    int x, y;
    cin >> x >> y;

    if (x && !y) {
        cout << 0;
        return 0;
    }

    int turns;
    int quad = determineQuad(x, y);
    if (quad < 4)
        turns = quad + (abs(x) - 1) * 4;
    else
        turns = quad + (abs(x) - 2) * 4;
    
    cout << turns;
    return 0;
}