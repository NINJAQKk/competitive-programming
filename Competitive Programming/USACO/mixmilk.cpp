#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, d, e, f; cin >> d >> a >> e >> b >> f >> c;
    vector<int> all = {a, b, c, d, e, f};
    for (int i=0; i<4; i++) {
        int f1 = all[i%3];
        int f2 = all[i%3+1];
        int m = all[i%3+4];
        if (i%3==2) {
            f2 = all[0];
            m = all[3];
        }
        f2 += f1;
        f1 = max(0, f2-m);
        f2 = min(m, f2);
        all[i%3] = f1; 
        if (i%3==2) {
            all[0] = f2;
            continue;
        }
        all[i%3+1] = f2;
    }
    cout << all[0] << "\n" << all[1] << "\n" << all[2];
}