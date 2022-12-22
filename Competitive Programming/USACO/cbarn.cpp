#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n; cin >> n;

    int max = INT_MAX;
    int sum = 0;
    vector<int> rooms;
    
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        rooms.push_back(a);
        sum += a;
    }

    for (int i=0; i<n; i++) {
        int temp = 0;
        int tempsum = sum;
        for (int j=i; j<n+i; j++) {
            temp += (tempsum - rooms[j%n]);
            tempsum -= rooms[j%n];
        }
        max = min(max, temp);
    }

    cout << max << "\n";
}