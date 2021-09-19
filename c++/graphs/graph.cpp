#include <bits/stdc++.h>
using namespace std;

class Graph {
  int v;
  list<int> *adj;

public:
  Graph(int v);
  void addEdge(int u, int v);
  void printGraph();
};

Graph::Graph(int v) {

  this->v = v;
  adj = new list<int>[v];
}
void Graph::addEdge(int u, int v) {

  adj[u].push_back(v);
  adj[v].push_back(u);
}

void Graph::printGraph() {
  for (int i = 0; i < v; i++) {
    cout << " vertex -> ";
    for (int nbr : adj[i]) {
      cout << nbr << ",";
    }
    cout << endl;
  }
}

int main() {

  int v;
  cout << "enter number of vertices :\n";
  cin >> v;
  Graph g(v);
  int e;
  cout << "enter number of edges :";
  cin >> e;
  cout << "adding\n";
  int x, y;
  for (int i = 0; i < e; i++) {
    cin >> x >> y;
    g.addEdge(x, y);
  }
  cout << "added\n";
  g.printGraph();
}
