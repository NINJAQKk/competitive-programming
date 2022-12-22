#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

int main() {
    ios_base::sync_with_stdio(false);
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<pair<int, int>> cows;
    fr(i, n) {
        int a, b; cin >> a >> b;
        cows.pb(make_pair(a, b));
    }

    vector<unordered_set<int>> cons;
    vector<array<int, 4>> sizes;
    unordered_map<int, int> done;
    unordered_map<int, int> shift;
    fr(i, m) {
        int a, b; cin >> a >> b;
        int ap=-1, bp=-1;
        if (done.count(a)!=0) {ap = done.at(a);}
        if (done.count(b)!=0) {bp = done.at(b);}
        if (shift.count(ap)!=0) {ap = shift.at(ap);}
        if (shift.count(bp)!=0) {bp = shift.at(bp);}
        if (ap==-1&&bp==-1) {
            unordered_set<int> temp = {a, b};
            cons.pb(temp);
            sizes.pb({min(cows[a-1].first, cows[b-1].first), max(cows[a-1].first, cows[b-1].first), min(cows[a-1].second, cows[b-1].second), max(cows[a-1].second, cows[b-1].second)});
            done.insert({a, cons.size()-1});
            done.insert({b, cons.size()-1});
        } else if (ap==bp) {
            continue;
        } else if (ap==-1 && bp!=-1) {
            cons[bp].insert(a);
            sizes[bp] = {min(sizes[bp][0], cows[a-1].first), max(sizes[bp][1], cows[a-1].first), min(sizes[bp][2], cows[a-1].second), max(sizes[bp][3], cows[a-1].second)};
            done.insert({a, cons.size()-1});
        } else if (ap!=-1 && bp==-1) {
            cons[ap].insert(b);
            sizes[ap] = {min(sizes[ap][0], cows[b-1].first), max(sizes[ap][1], cows[b-1].first), min(sizes[ap][2], cows[b-1].second), max(sizes[ap][3], cows[b-1].second)};
            done.insert({b, cons.size()-1});
        } else {
            cons[ap].insert(cons[bp].begin(), cons[bp].end());
            // cons.erase(cons.begin()+bp);
            cons[bp] = {};
            sizes[ap] = {min(sizes[ap][0], sizes[bp][0]), max(sizes[ap][1], sizes[bp][1]), min(sizes[ap][2], sizes[bp][2]), max(sizes[ap][3], sizes[bp][3])};
            // sizes.erase(sizes.begin()+bp);
            shift[bp] = {};
            shift.insert({bp, ap});
        }
        
    }
    int ans=INT_MAX;
    for (int i=0; i<(int)sizes.size(); i++) {
        if (shift.count(i)) {continue;}
        ans = min(ans, ((sizes[i][1]-sizes[i][0])*2+(sizes[i][3]-sizes[i][2])*2));
    }

    cout << ans;
}