#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

int main() {
    ios_base::sync_with_stdio(false);
    freopen("test.in", "r", stdin);
    // freopen("factory.out", "w", stdout);
    cin.tie(0);

    int n; cin >> n;

    // unordered_map<int, int> belts;
    bool pos[n] = {};
    fr(i, n-1) {
        int a, b; cin >> a >> b;
        // belts[a] = b;
        pos[a-1] = true;
    }

    fr(i, n) {
        if (!pos[i]) {
            cout << i+1;
            break;
        }
    }

}