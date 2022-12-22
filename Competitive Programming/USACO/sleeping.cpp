#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    // freopen("test.in", "r", stdin);
    // freopen("sleeping.out", "w", stdout);
    cin.tie(NULL);

    int T; cin >> T;
    for (int loops = 0; loops<T; loops++) {
        int n; cin >> n;
        int mx = 0, sum = 0;
        vector<int> log;
        for (int i=0; i < n; i++) {
            int a;
            cin >> a;
            log.push_back(a);
            sum += a;
            mx = max(mx, a);
        }

        if (mx==0) {
            cout << 0 << "\n";
            continue;
        }

        bool done = true;
        for (int i=mx; i<= (int)sum/2; i++) {
            if (sum%i!=0) {
                continue;
            }
            int cur = 0;
            done = true;
            for (int j=0; j<n; j++) {
                cur += log[j];
                if (cur == i) {
                    cur = 0;
                }
                if (cur > i) {
                    done = false;
                    break;
                }
            }
            if (done) {
                cout << n-(sum/i) << "\n";
                done = false;
                break;
            }
            if (i==(int)sum/2) {
                done = true;
            }
        }
        if (done) {
            cout << n - 1 << "\n";
        }
    }
}