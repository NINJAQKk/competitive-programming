#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (ll i = 0; i < x; i++)

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("test.in", "r", stdin);
    cin.tie(0);

    ll n; cin >> n;

    vector<ll> cows;

    fr(i, n) {
        ll a; cin >> a;
        cows.pb(a);
    }

    sort(all(cows), [](ll a, ll b){return b<a;});

    ll ans=0;
    ll ans2=0;
    ll cur = 0;
    fr(i, n) {
        cur = (i+1)*cows[i];
        if (cur>=ans) {
            ans=cur;
            ans2=cows[i];
        }
    }

    cout << ans << " " << ans2;
}