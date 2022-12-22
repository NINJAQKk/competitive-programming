#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

int main() {
    ios_base::sync_with_stdio(false);
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    cin.tie(0);

    int n; cin >> n;
    vector<int> pfxrow;
    pfxrow.pb(0);
    fr(i, n) {
        int a; cin >> a;
        pfxrow.pb((pfxrow[i]+a)%7);
        // cout << a << " " << pfxrow[i+1] << "\n";
    }
    int vals[7] = {0, 1, 2, 3, 4, 5, 6};
    int a = find_end(all(pfxrow), begin(vals), begin(vals)+1) - find(all(pfxrow), 0); //0
    int b = find_end(all(pfxrow), begin(vals)+1, begin(vals)+2) - find(all(pfxrow), 1); //1
    int c = find_end(all(pfxrow), begin(vals)+2, begin(vals)+3) - find(all(pfxrow), 2); //2
    int d = find_end(all(pfxrow), begin(vals)+3, begin(vals)+4) - find(all(pfxrow), 3); //3
    int e = find_end(all(pfxrow), begin(vals)+4, begin(vals)+5) - find(all(pfxrow), 4); //4
    int f = find_end(all(pfxrow), begin(vals)+5, begin(vals)+6) - find(all(pfxrow), 5); //5
    int g = find_end(all(pfxrow), begin(vals)+6, begin(vals)+7) - find(all(pfxrow), 6); //6

    cout << max(0, max(a, max(b, max(c, max(d, max(e, max(f, g)))))));
}