#include <iostream>
#include <list>
using namespace std;

class Graph {
    int vertices;
    list<int> *adjacencyList;

    public: 
        Graph(int v = 0): vertices(v), adjacencyList(new list<int>[v]) {}

        void addEdge(int u, int v, bool bidirectional = true) {
            adjacencyList[u].push_back(v);

            if (bidirectional)
                adjacencyList[v].push_back(u);
        }

        void displayGraph() {
            for (int i = 0; i < vertices; i++) {
                cout << i << " -> ";
                for (int v : adjacencyList[i])
                    cout << v << " , ";
                cout << endl;
            }
        }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.displayGraph();
    return 0;
}
