#include <bits/stdc++.h>
using namespace std;

string cows;

int dfs(int n, int p, int t, int type, vector<int> adj[]) {
  // Set up variables to keep track of the search results
  bool found = false;
  bool target = false;

  if (n==t) {
    if ((cows[n] - 'G' + type) != 0) {
        return 2;
    }
    return 1;
  }

    for (int j = 0; j < (int)adj[n].size(); j++) {
      int nd = adj[n][j];
      if (nd == t) {
        if ((cows[nd] - 'G' + type) != 0) {
          target = true;
        }
        found = true;
      }
      if (nd == p) {
        continue;
      }
      int cur = dfs(nd, n, t, type, adj);
      if (cur == 2) {
        target = true;
      } else if (cur != 0) {
        found = true;
      }
    }
  // Use the search results to determine the overall result for the current node
  if (target)
    return 2;
  if (found) {
    if ((cows[n] - 'G' + type) != 0) {
      return 2;
    } else {
      return 1;
    }
  }
  return 0;
}

int main() {
  freopen("milkvisits.in", "r", stdin);
  freopen("milkvisits.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  cin >> cows;

  vector<int> adj[n];
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }
  // H: type=0; G: type=-1;
  for (int i = 0; i < m; i++) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    cout << dfs(a - 1, -1, b - 1, c - 'H', adj) - 1;
  }
}