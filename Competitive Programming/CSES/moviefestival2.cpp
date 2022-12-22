#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("test.in", "r", stdin);
    // freopen("diamond.out", "w", stdout);
    cin.tie(0);

    int N, k; cin >> N >> k;

    pair<int,int> times[N]; //first=end second=start
    fr(i, N) {
        int s, e; cin >> s >> e;
        pair<int,int> temp = make_pair(e, s);
        times[i] = temp;
    }

    sort(times, times+N);
    int aval[k] = {};
    int ans = 0;

    fr(i, N) {
        fr(j, k) {
            if (times[i].second >= aval[j]) {
                aval[j] = times[i].first;
                ans++;
                break;
            } 
        }
    }
    cout << ans;
}