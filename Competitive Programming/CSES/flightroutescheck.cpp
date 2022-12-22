#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

void dfs(bool reach[], int pos, vector<int> adj[], int& cnt) {
    reach[pos]= true;
    cnt++;
    for (int i: adj[pos]) {
        if(!reach[i]) {
            dfs(reach, i, adj, cnt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("test.in", "r", stdin);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> adj[n];

    fr(i, m) {
        int a, b; cin >> a >> b;
        adj[a-1].pb(b-1);
    }

    bool ans = true;
    fr(i, n) {
        bool reach[n] = {false};
        int cnt = 0;
        dfs(reach, i, adj, cnt);
        if (cnt!=n) {
            fr(j, n) {
                if (reach[j]!=true) {
                    cout << "NO\n" << i+1 << " " << j+1;
                    ans = false;
                    break;
                }
            }
        }
    }
    if (ans==true) {
        cout << "YES";
    }
}