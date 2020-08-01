#include <iostream>
#include <unordered_map>
using namespace std;

double slope(double x1, double y1, double x2, double y2) {
    return (y2 - y1) / (x2 - x1);
}

int main() {

    #ifndef ONLILE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    
    int n, homeX, homeY;
    cin >> n >> homeX >> homeY;

    unordered_map<double, int> slopes;
    int x, y;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        slopes[slope(homeX, homeY, x, y)]++;
    }

    int lines = slopes.size();
    cout << lines;

    return 0;
}