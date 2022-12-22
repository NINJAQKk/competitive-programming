#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int k, n; cin >> k >> n;
    int cows[k][n];
    for (int i=0; i<k; i++) {
        for (int j=0; j<n; j++) {
            int a; cin >> a;
            cows[i][a-1] = j;
        }
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            bool test = true;
            int mx = cows[0][j] > cows[0][i] ? j : i;
            int prev = mx;
            for (int l=0; l<k; l++) {
                mx = cows[l][j] > cows[l][i] ? j : i;
                if (mx != prev) {
                    test = false;
                }
                prev = mx;
            }
            cnt += test;
        }
    }
    cout << cnt;
}