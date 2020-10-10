#include <iostream>
using namespace std;

int noOfWays(int level, int *ways) {
    if (level < 0)
        return 0;
    if (level == 0) {
        ways[0] = 1;
        return ways[0];
    }
    
    if (ways[level] != -1)
        return ways[level];
    else {
        ways[level] = noOfWays(level - 1, ways) + noOfWays(level - 2, ways) + noOfWays(level - 3, ways);
        return ways[level];
    }
}

int main() {
    int level = 4;

    int *ways = new int[100];
    for(int i = 0; i < 100; i++)
        ways[i] = -1;
    cout << noOfWays(4, ways) << endl;
    return 0;
}