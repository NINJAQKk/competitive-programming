// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     freopen("test.in", "r", stdin);
//     // freopen("circlecross.out", "w", stdout);

//     string n; cin >> n;
//     vector<int> cows;
//     vector<bool> vals;
//     for (int i=0; i<52; i+=2) {
//         cows.push_back(n[i]-'A');
//         cows.push_back(n[i+1]-'A');
//         vals.push_back(false);
//     }

//     int cnt = 0;
//     int cur = 0;
//     for (int cow:cows) {
//         vals[cow] = !vals[cow];
//         if (vals[cow]) {cur++;}
//         else {cur--; cnt+=cur;}
//     }
//     cout << cnt;
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string n; cin >> n;
    vector<char> cows;
    for (int i=0; i<52; i++) {
        cows.push_back(n[i]);
    }

    int cnt = 0;
    for (char i='A'; i<='Z'; i++) {
        auto start = find(cows.begin(), cows.end(), i);
        auto end = find(start+1, cows.end(), i);
        vector<char> found;
        for (auto it = start; it != end; it++) {
            auto loc = find(found.begin(), found.end(), *it);
            if (loc == found.end()) {
                found.push_back(*it);
            } else {
                found.erase(loc);
            }
        }
        cnt += found.size() - 1;
    }
    cout << cnt/2;
}