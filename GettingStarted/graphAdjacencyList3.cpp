#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

template <typename T>
class Graph {
    map<T, list<T> > adjacencyList;

    public:
        void addEdge(const T &u, const T &v, bool bidirectional = true) {
            adjacencyList[u].push_back(v);

            if (bidirectional) 
                adjacencyList[v].push_back(u);
        }

        void displayGraph() {
            for (auto pair: adjacencyList) {
                cout << pair.first << " -> ";
                for (auto element : pair.second) 
                    cout << element << ", ";
                cout << endl;
            }
        }
};

int main() {
    Graph<string> g;
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Delhi", "Sianchen");
    g.addEdge("Delhi", "Bangalore");
    g.addEdge("Delhi", "Agra");
    g.addEdge("Amritsar", "Sianchen");

    g.displayGraph();
    return 0;
}