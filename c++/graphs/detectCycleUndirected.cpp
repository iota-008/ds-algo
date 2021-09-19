#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

class Graph {

  list<int> *adj;
  int v;

public:
  Graph(int N) {
    v = N + 1;
    adj = new list<int>[v];
  }
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void printGraph() {
    for (int i = 0; i <= v; i++) {

      cout << "node : " << i << " -> ";
      for (auto j : adj[i]) {
        cout << " " << j;
      }
      cout << endl;
    }
  }
  bool dfsHelper(list<int> *, vector<bool> &, int, int);
  bool detectCycle();
};

bool Graph::dfsHelper(list<int> *adj, vector<bool> &vis, int src, int parent) {

  for (auto i : adj[src]) {

    if (!vis[i]) {
      vis[i] = true;
      if (dfsHelper(adj, vis, i, src))
        return true;
    } else if (parent != i) {
      return true;
    }
  }
  return false;
}

bool Graph::detectCycle() {

  vector<bool> vis(v, false);
  int parent = -1;
  vis[0] = true;
  return dfsHelper(adj, vis, 0, parent);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  // number rof nodes and edges
  int n, e;
  cin >> n >> e;
  Graph g(n);
  for (int i = 0; i < e; i++) {
    int src, dest;
    cin >> src >> dest;
    g.addEdge(src, dest);
  }

  if (g.detectCycle())
    cout << "YES, cycle is present in the graph\n";
  else
    cout << "NO, cycle not present in the graph\n";

  g.printGraph();
  return 0;
}
