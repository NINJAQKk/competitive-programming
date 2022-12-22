#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n; cin >> n;
    vector<int> order;
    vector<string> ids;
    vector<string> temp;
    vector<string> empty;

    for (int i=0; i<n; i++) {
        int cur;
        cin >> cur;
        order.push_back(cur);
    }

    for (int i=0; i<n; i++) {
        string cur;
        cin >> cur;
        ids.push_back(cur);
    }

    for (int y=0; y<3; y++){
        int count = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (order[j] == count) {
                    temp.push_back(ids[j]);
                }
            }
            count++;
        }
        ids = temp;
        temp = empty;
    }

    for (string item : ids) {
        cout << item << "\n";
    }
}