#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("test.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    cin.tie(0);

    int n, t; cin >> n >> t;
    int psum[n+1];
    psum[0] = 0;
    fr(i, n) {
        int a;
        cin >> a;
        psum[i+1] = psum[i] + a;
    }

    int b=0, e=1;
    int mx = 0;
    while (e<=n) {
        if(psum[e] - psum[b] <= t) {
            mx = max(mx, e-b);
            e++;
        } else {
            b++;
        }
    }
    cout << mx;
}