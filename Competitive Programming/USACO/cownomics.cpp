#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);   int n, m; cin >> n >> m;

    vector<string> dna;
    for(int i=0;i<n*2;i++) {
        string a; cin >> a;
        dna.push_back(a);
    }

    int cnt=0;
    for(int i=0;i<m;i++) {
        vector<char> a, b;
        for(int j=0;j<n;j++) {
            a.push_back(dna[j][i]);
            b.push_back(dna[j+n][i]);
        }
        if((find(a.begin(),a.end(),'A')!=a.end()&&find(b.begin(),b.end(),'A')!=b.end())||(find(a.begin(),a.end(),'T')!=a.end()&&find(b.begin(),b.end(),'T')!=b.end())||(find(a.begin(),a.end(),'C')!=a.end()&&find(b.begin(),b.end(),'C')!=b.end())||(find(a.begin(),a.end(),'G')!=a.end()&&find(b.begin(),b.end(),'G')!=b.end())) {
            continue;
        }
        cnt++;
    }
    cout << cnt;
}