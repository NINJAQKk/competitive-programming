#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n; cin >> n;

    vector<string> words;
    for (int i=0; i<n*2; i++) {
        string a; cin >> a;
        words.push_back(a);
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        int cnt = 0;
        for (int i=0; i<words.size(); i+=2) {
            int a = count(words[i].begin(), words[i].end(), ch);
            int b = count(words[i+1].begin(), words[i+1].end(), ch);
            cnt += max(a,b);
        }
        cout << cnt << "\n";
    }
}