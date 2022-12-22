#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
    cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2 >> a3 >> b3 >> c3 >> d3;
    int area1 = (c1 - a1) * (d1 - b1) - max(min(c1, c3) - max(a1, a3), 0) * max(min(d1, d3) - max(b1, b3), 0);
    int area2 = (c2 - a2) * (d2 - b2) - max(min(c2, c3) - max(a2, a3), 0) * max(min(d2, d3) - max(b2, b3), 0);
    cout << area1 + area2;
}