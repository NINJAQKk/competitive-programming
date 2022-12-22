#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int sp;
    vector<int> total;
    vector<vector<int>> vals;
    for (int i=0; i<n; i++) {
        vector<int> temp;
        int a, b, c; cin >> a >> b >> c;
        temp.push_back(a);
        temp.push_back(b);
        temp.push_back(c);
        vals.push_back(temp);
    }
    for (int x=0; x<3; x++) {
        sp = x+1;
        int count = 0;
        for (int i=0; i<n; i++) {
            int a = vals[i][0];
            int b = vals[i][1];
            int guess = vals[i][2];
            if (sp == a) {
                sp = b;
            } else if (sp == b) {
                sp = a;
            }

            if (sp == guess) {
                count++;
            }
        }
        total.push_back(count);
    }
    cout << *max_element(total.begin(), total.end());
}