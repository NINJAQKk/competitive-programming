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
    for (int i=0; i<t; i++) {
        int n;
        cin >> n;

        vector<pair<int, int>> durs;
        vector<pair<string, int>> cols;
        for (int j=0; j<n; j++) {
            string c; int d, u;
            cin >> c >> d >> u;
            pair<string, int> co = make_pair(c, u);
            pair<int, int> du = make_pair(d, u);
            durs.pb(du);
            cols.pb(co);
        }

        sort(all(cols), [](pair<string, int>a, pair<string, int>b){
            if (a.first==b.first) return a.second<b.second;
            return a.first<b.first;
        });

        sort(all(durs), [](pair<int, int>a, pair<int, int>b){
            if (a.first==b.first) return a.second<b.second;
            return a.first<b.first;
        });

        int ans = 0;
        for (int j=0; j<n; j++) {
            if (cols[j].second==durs[j].second) ans++;
        }

        // for (pair<string, int> j: cols) {
        //     cout << j.first << " " << j.second << "\n";
        // }



        cout << "Case #" << i+1 << ": " << ans << "\n"; 
    }
}