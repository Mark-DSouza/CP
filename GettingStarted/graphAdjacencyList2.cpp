#include <iostream>
#include <map>
#include <string>
#include <list>
using namespace std;

class Graph {
    map<string, list<string> > adjacencyList;

    public:
        void addEdge(const string &u, const string &v, bool bidirectional = true) {
            adjacencyList[u].push_back(v);

            if (bidirectional) 
                adjacencyList[v].push_back(u);
        }

        void displayGraph() {
            for (auto row : adjacencyList) {
                cout << row.first << " -> ";
                for (auto element : row.second) 
                    cout << element << " , ";
                cout << endl;
            }
        }
};

int main() {
    Graph g;
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Delhi", "Sianchen");
    g.addEdge("Delhi", "Bangalore");
    g.addEdge("Delhi", "Agra");
    g.addEdge("Amritsar", "Sianchen");
    g.displayGraph();
    return 0;
}