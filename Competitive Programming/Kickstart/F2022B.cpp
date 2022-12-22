#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("test.in", "r", stdin);
    // freopen("tracing.out", "w", stdout);
    cin.tie(0);
    int t; cin >> t;
    for (int T=0; T<t; T++) {
        int n, q; cin >> n >> q;

        unordered_map<int, int> levels; //key=container #; value=level
        levels[1] = 1;
        int cuml[n+1] = {};
        cuml[1] = 1;
        vector<pair<int, int>> cons;
        for (int i=0; i<n-1; i++) {
            int a, b; cin >> a >> b;
            pair<int, int> temp = make_pair(min(a,b), max(a,b));
            cons.pb(temp);
        }
        sort(all(cons), [](pair<int,int>a, pair<int,int> b){return a.first<b.first;});

        for (int i=0; i<n-1; i++) {
            int a,b;
            if (levels.find(cons[i].first)!=levels.end()) {
                a = cons[i].first;
                b = cons[i].second;
            } else {
                b = cons[i].first;
                a = cons[i].second;
            }
            levels[b] = levels[a]+1;
            cuml[levels[b]]++;
        }

        for (int i=0; i<q; i++) {
            int a; cin >> a;
        }
        
        int ans = 0;
        for (int i=1; i<n+1; i++) {
            q-=cuml[i];
            if (q<0) break;
            ans+= cuml[i];
        }

        cout << "Case #" << T+1 << ": " << ans << "\n"; 
    }
}