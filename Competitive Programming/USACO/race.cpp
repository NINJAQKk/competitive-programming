#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

int main() {
    ios_base::sync_with_stdio(false);
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    cin.tie(0);

    int k, n; cin >> k >> n;

    for (int runs=0; runs<n; runs++) {
        int x; cin >> x;
        int time=x, speed=x, dist=k-((x*(x+1))/2);
        if(dist<0) {
            time=ceil(1+sqrt(1+8*x))/2; dist=0;
        }
        while (dist>0) {
            // cout << k-dist << " " << speed << "\n";
            time++;
            speed++;
            if (dist-x<=0) break;
            int temp = dist-speed;
            if (temp>=((speed-x)*(speed+x-1))/2) {
                dist-=speed;
                continue;
            }
            speed--;
            temp++;
            if (temp>=((speed-x)*(speed+x-1))/2) {
                dist-=speed;
                continue;
            }
            speed--;
            dist-=speed;
        }
        cout << time << "\n";
    }
}