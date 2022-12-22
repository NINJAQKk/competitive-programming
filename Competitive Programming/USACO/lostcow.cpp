// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     // int a, b; cin >> a >> b;
//     // int dist = 0;
//     // int cur = 1;
//     // int sp = a;
//     // int runs = 1;
//     // while (true) {
//     //     a += cur;
//     //     dist += dist + runs;
//     //     cur = (abs(cur)+0.5)*-2*(cur/abs(cur));
//     //     cout << dist << " " << a << " " << cur << "\n";
//     //     if (sp > b) {
//     //         if (b>=a) {
//     //             cout << dist-(a-b);
//     //             break;
//     //         }
//     //     } else {
//     //         if (a-b>=0) {
//     //             cout << dist-(a-b);
//     //             break;
//     //                 }
//     //     }
//     //     runs *= 2;
//     // }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     freopen("lostcow.in", "r", stdin);
//     freopen("lostcow.out", "w", stdout);
//     int a, b; cin >> a >> b;
//     int count = 1;
//     int dist = 0;
//     bool done = false;
//     int sp = a;
//     while (true) {
//         if (a==b) {
//                 done = true;
//                 break;
//             }
//         if (count > 100) {
//             break;
//         }
//         if (done) {
//             break;
//         }
//         for (int i=0; i<count; i++) {
//             a++;
//             dist++;
//             if (a==b) {
//                 done = true;
//                 break;
//             }
//         }
//         if (done) {
//             break;
//         }
//         count *= 2;
//         dist += abs(a-sp);
//         a= sp;
//         for (int i=0; i<count; i++) {
//             a--;
//             dist++;
//             if (a==b) {
//                 done = true;
//                 break;
//             }
//         }
//         if (done) {
//             break;
//         }
//         dist += abs(a-sp);
//         count *= 2;
//         a = sp;
//     }
//     cout << dist;
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int a, b; cin >> a >> b;
    int count = 1;
    int sp = a;
    bool done = false;
    bool before = sp < b;
    int dist = 0;
    if (b==a) {
        cout << 0 << "\n";
        done = true;
    }
    while (!done) {
        a += count;
        dist += abs(count);
        if (before) {
            if (a > b) {
                cout << dist - abs(a-b) << "\n";
                done = true;
            }
        } else {
            if (b > a) {
                cout << dist - abs(a-b) << "\n";
                done = true;
            }
        }
        dist += abs(count);
        a = sp;
        count *= -2;
    }
}