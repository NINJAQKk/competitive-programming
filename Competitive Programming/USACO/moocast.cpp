#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

int main() {
    ios_base::sync_with_stdio(false);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin.tie(0);

    int n; cin >> n;

    vector<array<int, 3>> cows;
    fr(i, n) {
        array<int, 3> temp;
        cin >> temp[0] >> temp[1] >> temp[2];
        cows.pb(temp);
    }

    vector<unordered_set<int>> adj;
    fr(i, n) {
        unordered_set<int> temp;
        fr(j, n) {
            if (sqrt(pow(cows[i][0]-cows[j][0], 2) + pow(cows[i][1]-cows[j][1], 2)) <= cows[i][2]) {
                temp.insert(j);
            }
        }
        adj.pb(temp);
    }

    int ans=0;
    fr(aosuidjasiojdfsaod, n) {
        fr(i, n) {
            unordered_set<int> temp = adj[i];
            for (int item : temp) {
                if (item==i) {continue;}
                for(int ite : adj[item]) {
                    adj[i].insert(ite);
                }
            }
            ans = max(ans, (int)adj[i].size());
        }
    }

    cout << ans;
}