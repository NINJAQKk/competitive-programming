#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

void dfs1(vector<int> adj[], bool visited[], int pos) {
    visited[pos]= true;
    for (int i: adj[pos]) {
        if(!visited[i]) {
            dfs1(adj, visited, i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> adjs[m];
    vector<int> adjd[m];
    vector<int> cows[n];
    bool visited[n] = {false};

    fr(i, m) {
        string type; cin >> type;
        int a, b; cin >> a >> b;
        cows[a].pb(i);
        cows[b].pb(i);
        if (type=="S") {
            adjs[a].pb(b);
            adjs[b].pb(a);
        } else {
            adjd[a].pb(b);
            adjd[b].pb(a);
        }
    }

    fr(i, n) {
        if(visited[i]) {continue;}
        
    }
}