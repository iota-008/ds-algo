#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {

  int i = low, j = high;
  int pivot = arr[low];
  while (i < j) {

    while (arr[i] <= pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i < j)
      swap(arr[i], arr[j]);
  }
  swap(arr[low], arr[j]);
  return j;
}

void quickSort(vector<int> &arr, int low, int high) {

  if (low < high) {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
  return;
}
int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;

  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  quickSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
    cout << arr[i];

  return 0;
}
