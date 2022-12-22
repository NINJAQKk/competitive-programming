#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("diamond.out", "w", stdout);

    int n; cin >> n;
    vector<vector<int>> cows;

    for (int i=0; i<n; i++) {
        string a; cin >> a;
        int b; cin >> b;
        vector<int> temp;
        if (a=="G") {
            temp.push_back(0);
        } else {
            temp.push_back(1);
        }
        temp.push_back(b);
        cows.push_back(temp);
    }

    int mn = INT_MAX;
    for (vector<int> cow : cows) {
        int cnt = 0;
        int pos = cow[1];
        for (vector<int> other : cows) {
            if (other[0] == 0) {
                if (pos < other[1]) {
                    cnt++;
                }
            } else {
                if (pos > other[1]) {
                    cnt++;
                }
            }
        }
        mn = min(mn, cnt);
    }
    cout << mn;
}