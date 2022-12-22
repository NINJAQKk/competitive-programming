#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

int main() {
    ios_base::sync_with_stdio(false);
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin.tie(0);

    int n, b;
    cin >> n >> b;

    int path[n];
    fr(i, n) {
        cin >> path[i];
    }

    unordered_map<int, int> szdist;
    fr(i, b) {
        int sz, dist, ans=1;
        cin >> sz >> dist;
        if (szdist.find(sz)!=szdist.end()) {
            if (szdist[sz]>dist) {
                ans = 0;
            }
        } else {
            int it = 0, comp = 0, mx = 0;
            while (it < n) {
                if (path[it]<=sz) {
                    mx = max(mx, it-comp);
                    comp = it;
                }
                it++;
            }
            szdist[sz] = mx;
            if (mx > dist) {
                ans = 0;
            }
        }
        // int it = 0;
        // while(it+dist < n && ans) {
        //     int cur = dist;
        //     while (cur > 0) {
        //         if (path[it+cur]>sz) {
        //             cur--;
        //         } else {
        //             it += cur;
        //             break;
        //         }
        //         if (cur == 0) ans = 0;
        //     }
        // }
        cout << ans << "\n";
    }
}