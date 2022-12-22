#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    freopen("test.in", "r", stdin);
    // freopen("outofplace.out", "w", stdout);
    cin.tie(0);

    int n; cin >> n;
    int bes=0;
    vector<int> cows;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        cows.pb(a);
        if (a<cows[max(0,i-1)]) bes = i;
    }

    int cnt=0, cur=0;
    for (int i=bes-1; i>=0; i--) {
        if(cows[i]==cur) continue;
        if(cows[i]>cows[bes]) {
            cnt++;
            cur=cows[i];
        } else {
            break;
        }
    }
    cout << cnt;
}