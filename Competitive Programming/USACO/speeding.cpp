#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<int> lims, speeds;
    int mx = 0;
    for (int i=0; i<n; i++) {
        int l, s;
        cin >> l >> s;  
        for (int j=0; j<l; j++) {
            lims.push_back(s);
        }
    }
    for (int i=0; i<m; i++) {
        int l, s;
        cin >> l >> s;  
        for (int j=0; j<l; j++) {
            speeds.push_back(s);
        }
    }
    for (int i=0; i<100; i++) {
        int sl = lims[i];
        int cs = speeds[i];
        mx = max(mx, cs-sl);
    }
    cout << mx;
}