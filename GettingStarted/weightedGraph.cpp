#include <iostream>
#include <map>
#include <list>
using namespace std;

template <typename T = string, typename W = double>
class Graph {
    map<T, list<pair<T, W> > > adjacencyList;

    public:
        void addEdge(const T &u, const T &v, const W &weight = 1, bool bidirectional = true) {
            adjacencyList[u].push_back(pair<T, W> (v, weight));

            if (bidirectional) {
                adjacencyList[v].push_back(pair<T, W> (u, weight));
            }
        }

        void displayGraph() {
            for (auto row : adjacencyList) {
                cout << row.first << " -> ";
                for (auto element : row.second) 
                    cout << "(" << element.first << "," << element.second << "); ";
                cout << endl;
            }
        }
};

int main() {
    Graph<string, double> g;
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Delhi", "Sianchen");
    g.addEdge("Delhi", "Bangalore");
    g.addEdge("Delhi", "Agra");
    g.addEdge("Amritsar", "Sianchen");

    g.displayGraph();
    return 0;
}