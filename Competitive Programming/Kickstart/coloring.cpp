#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("test.in", "r", stdin);
    // freopen("tracing.out", "w", stdout);
    cin.tie(0);
    int t; cin >> t;
    for (int i=0; i<t; i++) {
        double n; cin >> n;
        int ans = ceil(n/2.5);
        cout << "Case #" << i+1 << ": " << ceil(ans/2.0) << "\n"; 
    }
}