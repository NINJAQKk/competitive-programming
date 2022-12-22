// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     ios_base::sync_with_stdio(false);
//     freopen("balancing.in", "r", stdin);
//     freopen("balancing.out", "w", stdout);
//     cin.tie(NULL);

//     int n, b; cin >> n >> b;

//     vector<vector<int>> cowx;
//     vector<vector<int>> cowy;
//     for (int i=0; i<n; i++) {
//         vector<int> temp;
//         int a, b; cin >> a >> b;
//         temp.push_back(a);
//         temp.push_back(b);
//         cowx.push_back(temp);
//         cowy.push_back(temp);
//     }

//     sort(cowx.begin(), cowx.end(), [](vector<int>&a, vector<int>&b) {return a[0] < b[0];});
//     sort(cowy.begin(), cowy.end(), [](vector<int>&a, vector<int>&b) {return a[1] < b[1];});

//     int mn = INT_MAX;
//     for (vector<int> itemx : cowx) {
//         int x = itemx[0] + 1;
//         for (vector<int> itemy : cowy) {
//             int y = itemy[1] + 1;
//             int ar[4] = {};
//             for (vector<int> cow : cowx) {
//                 if (cow[0] < x && cow[1] < y) {
//                     ar[0]++;
//                 } else if (cow[0] > x && cow[1] < y) {
//                     ar[1]++;
//                 } else if (cow[0] < x && cow[1] > y) {
//                     ar[2]++;
//                 } else {
//                     ar[3]++;
//                 }
//             }
//             mn = min(mn, max(ar[0], max(ar[1], max(ar[2], ar[3]))));
//             // cout << x << " " << y << " " << ar[0] << " " << ar[1] << " " << ar[2] << " " << ar[3] << " " << "\n";
//         }
//     }
//     cout << mn;
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    cin.tie(NULL);

    int n, b; cin >> n >> b;

    vector<int> cowx;
    vector<int> cowy;
    vector<vector<int>> cows;
    for (int i=0; i<n; i++) {
        vector<int> temp;
        int a, b; cin >> a >> b;
        temp.push_back(a);
        temp.push_back(b);
        cowx.push_back(a);
        cowy.push_back(b);
        cows.push_back(temp);
    }

    int mn = INT_MAX;
    for (int itemx : cowx) {
        int x = itemx + 1;
        for (int itemy : cowy) {
            int y = itemy + 1;
            int ar[4] = {};
            for (vector<int> cow : cows) {
                if (cow[0] < x && cow[1] < y) {
                    ar[0]++;
                } else if (cow[0] > x && cow[1] < y) {
                    ar[1]++;
                } else if (cow[0] < x && cow[1] > y) {
                    ar[2]++;
                } else {
                    ar[3]++;
                }
            }
            mn = min(mn, max(ar[0], max(ar[1], max(ar[2], ar[3]))));
            // cout << x << " " << y << " " << ar[0] << " " << ar[1] << " " << ar[2] << " " << ar[3] << " " << "\n";
        }
    }
    cout << mn;
}