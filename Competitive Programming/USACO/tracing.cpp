//INCOMPLETE

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    freopen("test.in", "r", stdin);
    // freopen("tracing.out", "w", stdout);
    cin.tie(0);

    int n, t; cin >> n >> t;
    string st; cin >> st;

    vector<int> cows;
    for (int i=0; i<n; i++) {
        cows.pb(st[i]);
    }

    vector<vector<int>> icts;
    for (int i=0; i<t; i++) {
        int a, b, c; cin >> a >> b >> c;
        vector<int> temp;
        temp.pb(a);
        temp.pb(b);
        temp.pb(c);
        icts.pb(temp);
    }

    sort(icts.begin(), icts.end(), [](vector<int>&a, vector<int>&b) {return a[0] < b[0];});


    int pos = 0;
    int mn = INT_MAX;
    int mx = -1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            bitset<100> beg;
            beg[i] = true;
            int ks[n] = {j};

            for (vector<int> ict: icts) {
                bool t = false;
                int a = ict[1];
                int b = ict[2];
                t |= (ks[a] || ks[b]);
                t &= beg[a] || beg[b];
                beg[a] = beg[a] || t;
                beg[b] = beg[b] || t;
                ks[a] += !beg[a];
                ks[b] += !beg[b];
                ks[a] = max(0, --ks[a]);
                ks[b] = max(0, --ks[b]);
            }
            if (beg.to_string().substr(100-n)==st) {
                cout << beg.to_string().substr(100-n) << "\n";
                pos++;
            }
        }

    }
    cout << pos;
}