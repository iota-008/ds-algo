#include <bits/stdc++.h>
using namespace std;
template <class T> void bfs(T source, map<T, set<T>> Graph, bool visited[]) {

  cout << "source : " << source << endl;
  queue<T> nodesVisited;
  nodesVisited.push(source);
  while (!nodesVisited.empty()) {

    source = nodesVisited.front();
    nodesVisited.pop();

    for (auto i : Graph[source]) {

      if (!visited[i]) {

        visited[i] = true;
        cout << "\t->" << i;
        nodesVisited.push(i);
      }
    }
  }
}

int main() {

  map<int, set<int>> Graph;
  int n;
  cout << "enter number of nodes :";
  cin >> n;

  int e;
  cout << "\nenter no of edges ";
  cin >> e;
  cout << "\nenter edges as 'a  b' \n";

  for (int i = 0; i < e; i++) {
    int source, destination;
    cin >> source >> destination;
    Graph[source].insert(destination);
    Graph[destination].insert(source);
  }

  bool visited[n];
  memset(visited, false, sizeof(visited));
  int source;
  cout << "\nenter source to start dfs :";
  cin >> source;
  bfs(source, Graph, visited);
}
