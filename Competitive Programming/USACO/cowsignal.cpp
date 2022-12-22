#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int l, w, x; cin >> l >> w >> x;
    vector<string> msg;
    for (int i=0; i<l; i++) {
        string l;
        cin >> l;
        string rs = "";
        for (int j=0; j<w; j++) {
            for (int k=0; k<x; k++) {
                rs+= l[j];
            }
        }
        for (int k=0; k<x; k++) {
            msg.push_back(rs);
        }
    }
    for (string item: msg) {
        cout << item << "\n";
    }
}