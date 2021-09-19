#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

bool checkCycle(map<int, vector<int>> &graph, vector<bool> &vis,
                vector<bool> &dfsVis, int node) {

  vis[node] = true;
  dfsVis[node] = true;

  for (auto i : graph[node]) {

    if (!dfsVis[node]) {
      if (checkCycle(graph, vis, dfsVis, i))
        return true;
    } else if (vis[i]) {
      return true;
    }
  }
  dfsVis[node] = false;
  return false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  map<int, vector<int>> graph;

  int n, e;
  cin >> n >> e;

  for (int i = 0; i < e; i++) {
    int src, dest;
    cin >> src >> dest;
    graph[src].push_back(dest);
  }
  vector<bool> vis(n, false), dfsVis(n, false);

  bool isCyclic = false;
  for (int i = 0; i < n; i++) {
    if (!dfsVis[i]) {
      if (checkCycle(graph, vis, dfsVis, i)) {
        isCyclic = true;
        break;
      }
    }
  }

  if (isCyclic) {
    cout << "Cycle Detected\n";
  } else {
    cout << "No Cycle Detected\n";
  }

  return 0;
}
