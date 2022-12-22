#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("test.in", "r", stdin);
    cin.tie(0);

    int t; cin >> t;

    fr (T, t) {
        int n, k; cin >> n >> k;
        string cows; cin >> cows;

        vector<int> hs, gs;
        fr(i, n) {
            if (cows[i]=='G') {
                gs.pb(i);
            } else {
                hs.pb(i);
            }
        }

        bool visited[n] = {false};
        int curg=-1, curh=-1;
        string ans (n, ' ');
        int cnt = 0;
        
        for (int i=0; i<n; i++) {
            if (cows[i]=='G') {
                curg++;
                if (visited[i]) {
                    continue;
                }
                if (curg==(int)gs.size()-1) {
                    ans[i] = 'G';
                    cnt++;
                    continue;
                }
                int end = min(i+k*2, n-1); // max pos that cow will move to
                int fin = i; // last index of a cow within end range
                int ind = curg; // index in arrays of gs being accessed
                visited[i] = true;
                while (ind < (int)gs.size()-1) {
                    ind++;
                    if (gs[ind] > end) {
                        break;
                    }
                    fin = gs[ind];
                    visited[fin] = true;
                }
                int pos = max(fin-k, i);
                while (ans[pos]!=' ') {
                    pos++;
                }
                ans[pos] = 'G';
                cnt++;
            } else {
                curh++;
                if (visited[i]) {
                    continue;
                    }
                if (curh==(int)hs.size()-1) {
                    ans[i] = 'H';
                    cnt++;
                    continue;
                }
                int end = min(i+k*2, n-1); // max pos that cow will move to
                int fin = i; // last index of a cow within end range
                int ind = curh; // index in arrays of gs being accessed
                visited[i] = true;
                while (ind < (int)hs.size()-1) {
                    ind++;
                    if (hs[ind] > end) {
                        break;
                    }
                    fin = hs[ind];
                    visited[fin] = true;
                }
                int pos = max(fin-k, i);
                while (ans[pos]!=' ') {
                    pos++;
                }
                ans[pos] = 'H';
                cnt++;
            }   
        }
        cout << cnt << "\n";
        for (int i=0; i<n; i++) {
            if (ans[i] == ' ') {
                cout << '.';
            } else {
                cout << ans[i];
            }
        }
        cout << "\n";
    }
}