#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

int lengthOfLongestSubstring(string s) {
  int n = s.size();

  if (n <= 0) return 0;

  int i = 0, j = 1;

  int ans = 0;

  unordered_map<int, int> m;

  while (j < n) {
    if (m[s[j]] > 0) {
      ans = max(ans, j - i);
      i = j;
      j = i + 1;
      m.clear();
      m[s[i]]++;

      continue;
    }

    else
      m[s[j]]++, j++;
  }

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

#endif

  string s;
  cin >> s;

  cout << lengthOfLongestSubstring(s) << "\n";

  return 0;
}