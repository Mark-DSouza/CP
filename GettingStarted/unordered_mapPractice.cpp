#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> umap;

    umap["Geeksforgeeks"] = 10;
    umap["Practice"] = 20;
    umap["Contribute"] = 30;

    for (auto x : umap ) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}