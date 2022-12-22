#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("test.in", "r", stdin);
    cin.tie(0);

    int t; cin >> t;

    fr (T, t) {
        int n, m; cin >> n >> m;

        vector<string> grid;
        vector<int> results;
        unordered_set<int> ignore;

        fr(i, m) {
            string a;
            int b; cin >> a >> b;
            grid.pb(a);
            results.pb(b);
        }

        bool done;
        bool finish = false;
        fr(l, m) {
            if(finish) break;
            fr(i, n) {
                int pos = 0;
                done = false;
                fr(j, m) {
                    if(ignore.count(j)) continue;
                    if (grid[j][i]=='0') {
                        done = true;
                    }
                    if (grid[j][i]=='0'&&results[j]!=0) {
                        pos--;
                        break;
                    }
                }
                if (done) pos++;
                fr(j, m) {
                    if(ignore.count(j)) continue;
                    if (grid[j][i]=='0'&&results[j]!=1) {
                        pos--;
                        break;
                    }
                }
                if (done) pos++;
                done = false;
                fr(j, m) {
                    if(ignore.count(j)) continue;
                    if (grid[j][i]=='1') {
                        done = true;
                    }
                    if (grid[j][i]=='1'&&results[j]!=0) {
                        pos-=10;
                        break;
                    }
                }
                if (done) pos+=10;
                fr(j, m) {
                    if(ignore.count(j)) continue;
                    if (grid[j][i]=='1'&&results[j]!=1) {
                        pos-=10;
                        break;
                    }
                }
                if (done) pos+=10;
                if  (pos==11) {
                    cout << "OK" << "\n";
                    finish = true;
                    break;
                }
                if (pos==1) {
                    fr(k, m) {
                        if (grid[k][i]=='0') {
                            ignore.insert(k);
                        }
                    }
                }
                if (pos==10) {
                    fr(k, m) {
                        if (grid[k][i]=='1') {
                            ignore.insert(k);
                        }
                    }
                }
                if ((int)grid.size()==0) {
                    finish = true;
                    cout << "OK" << "\n";
                    break;
                }
            }
            if(finish) break;
        }
        if(finish) continue;
        int ref = 0;
        fr(i, m) {
            if (!ignore.count(i)) {
                ref = i;
            }
        }
        fr(i, m) {
            if (!ignore.count(i)&&results[i]!=ref) {
                cout << "LIE" << "\n";
                finish = true;
                break;
            }
        }
        if (!finish) {cout << "OK" << "\n";}
    }
}