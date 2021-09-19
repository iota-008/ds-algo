#include <bits/stdc++.h>
using namespace std;

int prims(map<int, vector<pair<int, int>>> graph) {
  int n = graph.size() + 1;
  int cost = 0;
  int src;
  cin >> src;
  vector<bool> visited(n, false);
  vector<int> costs(n, INT_MAX);
  vector<int> parent(n);

  costs[src] = 0;
  parent[src] = -1;

  for (int count = 0; count < n - 1; count++) {
    int minVal = INT_MAX, minIndex;
    for (int i = 0; i < n; i++) {

      if (visited[i] == false && minVal > costs[i]) {

        minVal = costs[i];
        minIndex = i;
      }
    }

    visited[minIndex] = true;
    cost += minVal;

    int min_val = INT_MAX, min_index;
    for (auto i : graph[minIndex]) {
      if (visited[i.first] == false) {

        costs[i.first] = min(costs[i.first], i.second);
        parent[i.first] = minIndex;
      }
    }
    cout << "selected : " << minIndex << "\tcost : " << cost << endl;
  }

  cout << "parent : ";
  int index = 0;
  for (auto i : parent) {
    cout << "parent : " << index << " -> " << i << endl;
    index++;
  }
  return cost;
}

int main() {

  map<int, vector<pair<int, int>>> graph;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {

    int src, dest, wt;
    cin >> src >> dest >> wt;
    graph[src].push_back({dest, wt});
  }
  // graph[0].push_back({1, 4}); //
  // graph[0].push_back({7, 8});
  // graph[1].push_back({2, 8}); //
  // graph[1].push_back({7, 11});
  // graph[2].push_back({3, 7}); //
  // graph[2].push_back({8, 2}); //
  // graph[2].push_back({5, 4}); //
  // graph[3].push_back({4, 9}); //
  // graph[3].push_back({5, 14});
  // graph[4].push_back({5, 10});
  // graph[5].push_back({6, 2}); //
  // graph[6].push_back({7, 1}); //
  // graph[6].push_back({8, 6});
  // graph[7].push_back({8, 7});

  cout << "\ncost : " << prims(graph);
}
