#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    freopen("test.in", "r", stdin);
    // freopen("tracing.out", "w", stdout);
    cin.tie(0);
    int t; cin >> t;
    for (int i=0; i<t; i++) {
        int n; cin >> n;
        vector<vector<int>> srst;
        for (int i=0; i<n; i++) {
            vector<int> temp;
            int a; cin >> a;
            temp.pb(a);
            temp.pb(i);
            srst.pb(temp);
        }

        sort(srst.begin(), srst.end(), [](vector<int>&a, vector<int>&b) {return a[0] < b[0];});
        reverse(srst.begin(), srst.end());


        // for (vector<int> item : srst) {
        //     for (int i : item) {
        //         cout << i << " ";
        //     }
        //     cout << "\n";
        // }
        cout << "Case #" << i+1 << ": ";
        int pos = 0;
        int ans[n];
        for (int s=0; s<n; s++) {
            if (pos == n) break;
            if (srst[pos][0] <= srst[s][0]*2) {
                if (s == pos) {
                    if (pos == n-1) {
                        ans[srst[s][1]] = -1;
                    } else {
                        ans[srst[s][1]] = srst[pos+1][0];
                    }
                } else {
                    ans[srst[s][1]] = srst[pos][0];
                }
                continue;
            }
            s--;
            pos++;
        }
        for (int item : ans) {
            cout << item << " ";
        }
        cout << "\n";
    }
}