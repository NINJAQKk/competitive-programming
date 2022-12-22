#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

 void dfs(vector<int> adj[], int pos, bool visited[], int teams[], int cur) {
    visited[pos]= true;
    if ((teams[pos]==1 && cur==2) || (teams[pos]==2 && cur==1)) {
        cur = 0;
        return;
    }

    teams[pos] = cur;
    if (cur==1) {
        cur=2;
    } else {
        cur=1;
    }

    for (int i: adj[pos]) {
        if(!visited[i]) {
            dfs(adj, i, visited, teams, cur);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("test.in", "r", stdin);
    cin.tie(0);

    int n, m; cin >> n >> m;

    int teams[n];
    
    vector<int> adj[n];

    fr(i, m) {
        int a, b; cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }

    fr(i, n) {
        if (teams[i]!=1 || teams[i]!=2) {
            bool visited[n] = {false};
            int cur = 1;
            dfs(adj, i, visited, teams, cur);
            if (cur == 0) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
        
    }

    for (int i:teams) {
        cout << i << " ";
    }
}