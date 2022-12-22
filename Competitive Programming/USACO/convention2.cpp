#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

int main() {
    ios_base::sync_with_stdio(false);
    freopen("test.in", "r", stdin);
    // freopen("diamond.out", "w", stdout);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> cows;
    int ord[n][3];
    fr(i, n) {
        int a, t; cin >> a >> t;
        vector<int> temp;
        temp.pb(a);
        temp.pb(t);
        temp.pb(i);
        cows.pb(temp);
        ord[i][0] = a;
        ord[i][1] = t;
        ord[i][2] = i;
    }

    sort(all(cows), [](vector<int> a, vector<int> b){return a[0]<b[0];});

    priority_queue<int, vector<int>, greater<int>> aval;
    int ans = 0;
    int it = 0;
    int cur = cows[0][1];

    while (it < n) {
        bool done = true;
        while (cur <= cows[it][0]) {
            aval.push(cows[it][0]);
            it++;
            done = false;
        }
        if (done) {aval.push(cows[it][0]); it++;}
        cur += ord[aval.top()][1];
        aval.pop();
        cout << cur << '\n';
        it++;
    }
}