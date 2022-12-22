#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, m; cin >> x >> y >> m;
    vector<int> xs, ys;

    for (int i=0; i<=m; i+= x) {
        xs.push_back(i);
    }
    for (int i=0; i<=m; i+= y) {
        ys.push_back(i);
    }

    int mx = 0;
    for (int x: xs) {
        for (int y: ys) {
            if (x + y <= m) {mx = max(mx, x + y);};
        }
    }

    cout << mx;
}