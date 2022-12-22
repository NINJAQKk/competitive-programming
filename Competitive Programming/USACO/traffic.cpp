// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     freopen("traffic.in", "r", stdin);
//     freopen("traffic.out", "w", stdout);

//     int n; cin >> n;

//     int low = 0;
//     int high = 0;
//     int ll = 0;
//     int hh = 0;
//     bool done = false;
//     bool finish = false;

//     for (int i=0; i<n; i++) {
//         string act; cin >> act;
//         int a, b; cin >> a >> b;

//         if (!(act=="none") && !done) {
//             if (act=="on") {
//                 ll += b;
//                 hh += a;
//             } else {
//                 ll -= a;
//                 hh -= b;
//             }
//             continue;
//         }

//         if (act=="none" && !done) {
//             low = a;
//             high = b;
//             done = true;
//             continue;
//         }

//         if (act=="none") {
//             low = max(low, a);
//             high = min(high, b);
//         }

//         if (act!="none" && !finish) {
//             finish = true;
//             cout << low - ll << " " << high - hh << "\n";
//         }

//         if (act=="on") {
//             low += a;
//             high += b;
//         }

//         if (act=="off") {
//             low -= b;
//             high -= a;
//         }
//     }
//     cout << low << " " << high << "\n";
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int n; cin >> n;

    int sl = 0; // start low
    int sh = 0; // start high
    int el = 0; // end low
    int eh = 0; // end high
    bool first = true; // first segment with none

    vector<string> acts;
    vector<int> as;
    vector<int> bs;

    for (int i=0; i<n; i++) {
        string act; cin >> act;
        int a, b; cin >> a >> b;

        acts.push_back(act);
        as.push_back(a);
        bs.push_back(b);
    }

    for (int i=0; i<n; i++) {
        string act = acts[i];
        int a = as[i];
        int b = bs[i];

        if (act == "none") {
            if (first) {
                el = a;
                eh = b;
                first = false;
            } else {
                el = max(el, a);
                eh = min(eh, b);
            }
        }

        if (act != "none" && first) {
            continue;
        }

        if (act == "on") {
            el += a;
            eh += b;
        }

        if (act == "off") {
            el -= b;
            eh -= a;
        }
    }

    first = true;
    for (int i=n-1; i>=0; i--) {
        string act = acts[i];
        int a = as[i];
        int b = bs[i];

        if (act == "none") {
            if (first) {
                sl = a;
                sh = b;
                first = false;
            } else {
                sl = max(sl, a);
                sh = min(sh, b);
            }
        }

        if (act != "none" && first) {
            continue;
        }

        if (act == "on") {
            sl -= b;
            sh -= a;
        }

        if (act == "off") {
            sl += a;
            sh += b;
        }
    }

    cout << max(sl, 0) << " " << sh << "\n";
    cout << max(el, 0) << " " << eh << "\n";

}