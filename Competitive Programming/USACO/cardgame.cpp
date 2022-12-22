#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

int main() {
    ios_base::sync_with_stdio(false);
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    cin.tie(0);
    
    int n; cin >> n;
    set<int> bes1;
    set<int,greater<int>> bes2;
    int opp1[n/2];
    int opp2[n/2];
    fr(i, n/2) {
        cin >> opp1[i];
        bes1.insert(i*2+1);
        bes1.insert(i*2+2);
    }
    fr(i,n/2) {
        cin >> opp2[i];
        bes1.insert(i*2+1+n);
        bes1.insert(i*2+2+n);
    }

    for (int item : opp1) {
        bes1.erase(bes1.find(item));
    }
    for (int item : opp2) {
        bes1.erase(bes1.find(item));
    }

    auto it = bes1.begin();
    fr(i, n/2) {
        bes2.insert(*it);
        it = bes1.erase(it);
    }

    sort(opp1, opp1+n/2);
    sort(opp2, opp2+n/2, greater<int>());
    
    int ans = 0;
    fr(i, n/2) {
        auto it = bes1.lower_bound(opp1[i]);
        if (it != bes1.end()) {
            ans++;
            bes1.erase(it);
        }
        auto it2 = bes2.lower_bound(opp2[i]);
        if (it2 != bes2.end()) {
            ans++;
            bes2.erase(it2);
        }
    }
    cout << ans;
}