/*
    Alice and Bob each created one problem for HackerRank. A reviewer rates the two challenges, awarding points on a scale from 1 to 100 for three categories: problem clarity, originality, and difficulty.

    The rating for Alice's challenge is the triplet a = (a[0], a[1], a[2]), and the rating for Bob's challenge is the triplet b = (b[0], b[1], b[2]).

    The task is to find their comparison points by comparing a[0] with b[0], a[1] with b[1], and a[2] with b[2].

    If a[i] > b[i], then Alice is awarded 1 point.
    If a[i] < b[i], then Bob is awarded 1 point.
    If a[i] = b[i], then neither person receives a point.
    Comparison points is the total points a person earned.

    Given a and b, determine their respective comparison points.

    #include <iostream>
    using namespace std;
*/

#include <iostream>
using namespace std;

int main() {
    #ifndef ONLILE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int a[3], b[3];
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    for (int j = 0; j < 3; j++)
        cin >> b[j];

    int alice = 0, bob = 0;
    for (int k = 0; k < 3; k++)
        if (a[k] > b[k])
            alice++;
        else if (a[k] < b[k])
            bob++;
    
    cout << alice << " " << bob;

    return 0;
}