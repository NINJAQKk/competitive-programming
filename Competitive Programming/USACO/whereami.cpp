#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    cin.tie(0);

    int n; cin >> n;
    string seq; cin >> seq;

    int ans;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i; j++) {
            if (seq.find(seq.substr(j, i), j+1)!=string::npos) {break;}
            if (j==n-i-1) {
                ans = i;
            }
        }
        if (ans) break;
    }

    cout << ans;
}