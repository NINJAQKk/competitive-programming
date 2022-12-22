#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    freopen("test.in", "r", stdin);
    // freopen("tracing.out", "w", stdout);
    cin.tie(0);
    int t; cin >> t;
    for (int i=0; i<t; i++) {
        int n; cin >> n;
        string word; cin >> word;

        string ans = "";
        for (int i=1; i<n; i++) {
            string beg = word.substr(0, ceil((i+n)/2.0));
            string nd = word.substr(floor((i+n)/2.0));
            string ndrev = nd;
            reverse(nd.begin(), nd.end());
            string test = beg.substr(0, beg.size()-nd.size());
            string temp = test.substr(floor(test.length()/2.0));
            reverse(temp.begin(), temp.end());
            if (nd == beg.substr(beg.size() - nd.size()) && test.substr(0, ceil(test.length()/2.0)) == temp) {
                ans += test;
                reverse(ans.begin(), ans.end());
                break;
            }
        }
        if (ans=="") {
            ans = word;
        }

        cout << "Case #" << i+1 << ": " << ans << "\n";


        // bool done = false;
        // for (int i=0; i<n; i++) {
        //     if (done) break;
        //     for (int j=i+1; j<=n; j++) {
        //         if (done) break;
        //         string temp = word + word.substr(i, j);
        //         string snd = temp.substr(temp.length()/2);
        //         reverse(snd.begin(), snd.end());
        //         if (temp.substr(0, ceil(temp.length()/2.0)) == snd) {
        //             cout << temp.substr(n) << "\n";
        //             done = true;
        //         }
        //     }
        // }
    }
}