#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("test.in", "r", stdin);
    // freopen("diamond.out", "w", stdout);
    cin.tie(0);

    int n; cin >> n;
    string cows; cin >> cows;

    pair<int,int> pfx[n+1];
    pfx[0] = {0,0};

    int a=0, b=0;
    fr(i, n) {
        if (cows[i]=='G') {
            a++;
        } else {
            b++;
        }
        pfx[i+1] = {a,b};
    }

    ll cnt=0;
    for (int i=0; i<n-2; i++) {
        for (int j=i+2; j<n; j++) {
            if (pfx[j+1].first-pfx[i].first==1 || pfx[j+1].second-pfx[i].second==1) {
                cnt++;
            }
        }
    }

    cout << cnt;
}