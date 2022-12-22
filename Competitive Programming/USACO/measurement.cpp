#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);

    int N; cin >> N;

    vector<vector<int>> change; // day, cow, change

    for (int i=0; i<N; i++) {
        int day, num;
        string name;
        cin >> day >> name >> num;
        vector<int> vec;
        vec.push_back(day);
        if (name == "Bessie") {
            vec.push_back(0);
        }
        if (name == "Elsie") {
            vec.push_back(1);
        }
        if (name == "Mildred") {
            vec.push_back(2);
        }
        vec.push_back(num);
    }

    sort(change.begin(), change.end(), [](vector<int>&a, vector<int>&b) {return a[1] < b[1];});

    vector<vector<int>> cows;
    int b = 7;
    int e = 7;
    int m = 7;
    int cur = 0;
    int prev = 0;
    int cnt = 0;
    for (int i=1; i<=100; i++) {
        if (change[0][0] == i) {
            prev = cur;

            switch (change[0][1]) {
                case 0:
                    b += change[0][2];
                    break;
                case 1:
                    e += change[0][2];
                    break;
                case 2:
                    m += change[0][2];
                    break;
                
            }

            int largest = b;
            // std::cout << "test\n";
            if (b == e && e == m) {
                cur = 0;
            } else if (b==largest && e == largest) {
                cur = 1;
            } else if (b==largest && m == largest) {
                cur = 2;
            } else if (m==largest && e == largest) {
                cur = 3;
            } else if (b==largest) {
                cur = 4;
            } else if (e==largest) {
                cur = 5;
            } else if (m==largest) {
                cur = 6;
            }

            if (prev != cur) {
                cnt++;
            }
            change.erase(change.begin());
        }
    }
    cout << "run " << cnt;
}