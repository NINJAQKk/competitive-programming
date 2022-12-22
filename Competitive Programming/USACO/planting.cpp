#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    freopen("planting.txt", "r", stdin);
    // freopen("planting.out", "w", stdout);
    cin.tie(0);

    int n; cin >> n;

    int con[n] = {0};
    int mx = 0;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        con[a-1]++;
        con[b-1]++;
        mx = max(con[a-1], max(con[b-1], mx));
    }

    cout << mx+1;


}