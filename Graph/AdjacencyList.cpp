#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    return;
}

void printGraph(vector<int> adj[], int V) {
    for (int i = 0; i < V; i++) {
        for (auto vecElement: adj[i])
            cout << vecElement << "  ";
        cout << endl;
    }
    return ;
}

int main() {
    int V = 5;
    vector<int> adj[V];     // Array of vectors
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    printGraph(adj, V); 
    return 0;
}