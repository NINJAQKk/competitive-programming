#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

int main() {
    ios_base::sync_with_stdio(false);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> dias;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        dias.push_back(a);
    }
    sort(dias.begin(), dias.end());

    int mx = 0;
    for(int split=1; split<n-1; split++) {
        int beg = 0;
        int end = 0;
        int mx1 = 0;
        while (end<=split) {
            if(dias[end]-dias[beg]<=k) {
                mx1 = max(mx1, end-beg+1);
                end++;
            } else {
                beg++;
            }
        }
        beg = split+1;
        end = beg;
        int mx2 = 0;
        while (end<n) {
            if(dias[end]-dias[beg]<=k) {
                mx2 = max(mx2, end-beg+1);
                end++;
            } else {
                beg++;
            }
        }
        mx = max(mx, mx1+mx2);
    }
    cout << mx;
}