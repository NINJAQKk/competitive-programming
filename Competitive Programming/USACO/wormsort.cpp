#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

int main() {
    ios_base::sync_with_stdio(false);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin.tie(0);

    int n, m; cin >> n >> m;

    // int cows[n];
    unordered_set<int> ooo;

    fr (i, n) {
        int a; cin >> a;
        // cows[i] = a;
        if (i+1!=a) {
            ooo.insert(a);
        }
    }
    if (ooo.size()==0) {
        cout << -1;
        return 0;
    }

    vector<int> holes[m];
    fr (i, m) {
        int a, b, w; cin >> a >> b >> w;
        holes[i].pb(a);
        holes[i].pb(b);
        holes[i].pb(w);
    }

    sort(holes, holes+m, [](vector<int> a, vector<int> b){return a[2]>b[2];}); // Sorts holes descending by weight

    int cnt = ooo.size();
    unordered_set<int> done;
    fr (i, m) {
        if (ooo.count(holes[i][0])!=0 && done.count(holes[i][0])==0) {
            done.insert(holes[i][0]);
            cnt--;
        }
        if (ooo.count(holes[i][1])!=0 && done.count(holes[i][1])==0) {
            done.insert(holes[i][1]);
            cnt--;
        }
        if (cnt==0) {
            cout << holes[i][2];
            return 0;
        }
    }
}