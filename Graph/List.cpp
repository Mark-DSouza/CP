#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void addEdge(unordered_map<int, vector<int> >& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(unordered_map<int, vector<int> >& adj) {
    for(int i = 0; i < adj.size(); i++) {
        for (auto node : adj[i])
            cout << node << "  ";
        cout << endl;
    } 
}

int main() {
    unordered_map<int, vector<int> > adj;
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4);
    printGraph(adj);
    return 0;
}