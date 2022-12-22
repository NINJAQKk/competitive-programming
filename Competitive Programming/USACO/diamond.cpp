#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k; cin >> n >> k;
    vector<int> dias;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        dias.push_back(a);
    }
    sort(dias.begin(), dias.end());

    int mx = 1;
    for (int i=0; i<n; i++) {
        int temp = 1;
        int test = dias[i]+k;
        for (int j=i+1; j<n; j++) {
            if (dias[j]>test) {break;}
            temp++;
        }
        mx = max(mx, temp);
    }
    cout << mx;
}