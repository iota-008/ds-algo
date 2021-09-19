#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

// check bipartite using dfs
bool checkBipartite(map<int, vector<int>> &graph, vector<int> &color, int src) {

  for (auto i : graph[src]) {
    if (color[i] == 0) {
      color[i] = color[src] == 1 ? 2 : 1;
      if (!checkBipartite(graph, color, i))
        return false;
    } else if (color[i] == color[src]) {
      return false;
    }
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n, e;
  cin >> n >> e;
  map<int, vector<int>> graph;
  for (int i = 0; i < e; i++) {
    int src, dest;
    cin >> src >> dest;
    graph[src].push_back(dest);
  }
  vector<int> color(n, 0);
  color[0] = 1;
  if (checkBipartite(graph, color, 0)) {
    cout << "graph is bipartite\n";
  } else {
    cout << "graph is not bipartite\n";
  }

  return 0;
}
