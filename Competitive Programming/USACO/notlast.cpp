#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    cin.tie(0);

    int n; cin >> n;
    unordered_map<string, int> cows;
    cows.insert(pair<string, int>("Bessie", 0));
    cows.insert(pair<string, int>("Elsie", 0));
    cows.insert(pair<string, int>("Daisy", 0));
    cows.insert(pair<string, int>("Gertie", 0));
    cows.insert(pair<string, int>("Annabelle", 0));
    cows.insert(pair<string, int>("Maggie", 0));
    cows.insert(pair<string, int>("Henrietta", 0));

    for (int i=0; i<n; i++) {
        string cow; cin >> cow;
        int amt; cin >> amt;
        cows[cow] += amt;
    }

    int mn=INT_MAX, snd=INT_MAX;
    string mnn="Tie", sndn="Tie";
    for (pair<string, int> cow : cows) {
        if (cow.second<mn) {
            snd = mn;
            mn = cow.second;
            sndn = mnn;
            mnn = cow.first;
        } else if(cow.second<snd && cow.second>mn) {
            snd = cow.second;
            sndn = cow.first;
        } else if(cow.second==snd) {
            sndn = "Tie";
        }
    }
    cout << sndn;

}