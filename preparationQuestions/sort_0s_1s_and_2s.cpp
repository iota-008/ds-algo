#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // dutch national flag algorithm variation;
  // O(n);
  void sort012_best(int arr[], int n) {

    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {

      if (arr[mid] == 0) {
        swap(arr[low], arr[mid]);
        low++;
        mid++;
      } else if (arr[mid] == 1)
        mid++;
      else {
        swap(arr[mid], arr[high]);
        high--;
      }
    }
    return;
  }

  // O(2*N);
  void sort012_brute(int arr[], int n) {

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {

      if (arr[i] == 0)
        cnt0++;

      if (arr[i] == 1)
        cnt1++;

      if (arr[i] == 2)
        cnt2++;
    }

    for (int i = 0; i < n; i++) {

      if (cnt0 > 0) {

        arr[i] = 0;
        cnt0--;
      } else if (cnt1 > 0) {

        arr[i] = 1;
        cnt1--;
      } else if (cnt2 > 0) {

        arr[i] = 2;
        cnt2--;
      }
    }
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    Solution ob;
    // ob.sort012_brute(a, n);
    ob.sort012_best(a, n);

    for (int i = 0; i < n; i++)
      cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}
