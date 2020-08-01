#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

double slope(double x1, double y1, double x2, double y2) {
    return (y2 - y1) / (x2 - x1);
}

int main() {
    int n;
    cin >> n;

    vector< vector<double> > segments(n, vector<double> (3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> segments[i][j];
        }
    }

    vector<double> slopes;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {;
        }
    }
    return 0;
}