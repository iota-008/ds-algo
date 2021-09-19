#include <bits/stdc++.h>

using namespace std;

template <class T>
void dfs(T source, map<T, set<T>> Graph, bool visited[],
         stack<T> nodesVisited) {

  // recursive
  /*if(!visited[source]){

      visited[source] = true;
      cout << source << "\t";
  }

  for(int i:Graph[source]){

      if(visited[i] == false){

          dfs(i,Graph,visited,nodesVisited);
      }
  }
  return;*/

  // iterative

  visited[source] = true;
  cout << "\t->" << source;
  while (!nodesVisited.empty()) {

    source = nodesVisited.top();
    nodesVisited.pop();

    if (!visited[source]) {

      visited[source] = true;
      cout << "\t->" << source;
    }

    for (auto i : Graph[source]) {

      if (!visited[i]) {

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
  stack<int> nodesVisited;
  int source;
  cout << "\nenter source to start dfs :";
  cin >> source;
  // visited[source] = true;
  nodesVisited.push(source);
  dfs(source, Graph, visited, nodesVisited);
  // printing graph;
  /* for(auto i : Graph){

      cout << i.first << "->";
      for(auto j : i.second){
          cout << j << ", ";
  }
  cout << "\n";
  }*/
}
