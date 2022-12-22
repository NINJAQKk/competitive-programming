#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("diamond.out", "w", stdout);

    int n; cin >> n;

    vector<int> daisies;

    for (int i=0; i<n; i++) {
        int a; cin >> a;
        daisies.push_back(a);
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
        int sum=0, sz=0;
        vector<int> temp;
        for (int j=i; j<n; j++) {
            int d = daisies[j];
            temp.push_back(d);
            sz++;
            sum += d;
            if (find(temp.begin(), temp.end(), (double)sum/sz) != temp.end()) {
                cnt++;
            }
        }
    }

    cout << cnt;
}