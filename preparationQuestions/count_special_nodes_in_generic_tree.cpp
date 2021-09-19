#include <bits/stdc++.h>
using namespace std;

class TreeNode {
  TreeNode<T> **children;
  int childCount;

public:
  T data;

  TreeNode(T data); // Constructor
  int numChildren();
  void addChild(TreeNode<T> *child);
  TreeNode<T> *getChild(int index);
  void setChild(int index, TreeNode<T> *child);
};

int dfs(TreeNode<int> *root, unordered_set<int> &path) {

  if (path.count(root->data)) {
    return 0;
  }

  path.insert(root->data);

  int child = root->numChildren();
  int count = 0;

  for (int i = 0; i < child; i++)
    count += dfs(root->getChild(i), path);

  path.erase(root->data);

  return 1 + count;
}

int countSpecialNodes(TreeNode<int> *root) {
  // Write your code here
  unordered_set<int> path;
  return dfs(root, path);
}
