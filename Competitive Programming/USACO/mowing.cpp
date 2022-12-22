#include <bits/stdc++.h>
using namespace std;

template <typename Iter>
Iter next(Iter iter)
{
    return ++iter;
}

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int N; cin >> N;
    int spx = 0;
    int spy = 0;
    int dist = INT_MAX;
    vector<string> lawn;

    for (int i=0; i<N; i++) {
        string dir; cin >> dir;
        int amt; cin >> amt;

        for (int j=0; j<amt; j++) {
            if (dir=="N") {
                spy += 1;
            } else if (dir=="S") {
                spy -= 1;
            } else if (dir=="E") {
                spx += 1;
            } else if (dir=="W") {
                spx -= 1;
            }
            string check = to_string(spx) + " " + to_string(spy);
            for (int i=lawn.size()-1; i>=0; i--) {
                if (lawn[i]==check) {
                    dist = min(dist, (int) lawn.size()-i);
                }
            }
            lawn.push_back(check);
        }
    }

    if (dist == INT_MAX) {
        dist = -1;
    }
    cout << dist;
}