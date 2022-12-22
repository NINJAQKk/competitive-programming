#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    
    int N; cin >> N;

    vector<vector<int>> cows;

    for (int i=0; i<N; i++) {
        string dir;
        int x, y;
        cin >> dir >> x >> y;
        vector<int> temp;
        if (dir == "N") {
            temp.push_back(0);
        } else {
            temp.push_back(1);
        }
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(INT_MAX);
        cows.push_back(temp);
    }
    // vector<int> cow = {dir, x, y, dist}
    for (int i = 0; i < N/2; i++) {
        for (vector<int>& cow : cows) {
            int dist = INT_MAX;
            for (vector<int> other : cows) {
                if (cow[0] != other[0]) {
                    if (cow[0] == 0) {
                        if (abs(other[1] - cow[1]) < abs(other[2] - cow[2]) && cow[1] - other[1] >= 0 && other[2] - cow[2] > 0) {
                            if (other[3] < abs(cow[1] - other[1])) {continue;}
                            dist = min(dist, other[2] - cow[2]);
                        }
                    } else {
                        if (abs(other[2] - cow[2]) < abs(other[1] - cow[1]) && cow[2] - other[2] >= 0 && other[1] - cow[1] > 0) {
                            if (other[3] < abs(cow[2] - other[2])) {continue;}
                            dist = min(dist, other[1] - cow[1]);
                        }
                    }
                }
            }
            cow[3] = dist;
        }
    }

    for (vector<int> cow : cows) {
        if (cow[3] == INT_MAX) {
            cout << "Infinity\n";
        } else {
            cout << cow[3] << "\n";
        }
    }
}