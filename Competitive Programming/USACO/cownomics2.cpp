// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     freopen("cownomics.in", "r", stdin);
//     freopen("cownomics.out", "w", stdout);
//     int n, m; cin >> n >> m;

//     vector<string> dna;
//     for(int i=0;i<n*2;i++) {
//         string a; cin >> a;
//         dna.push_back(a);
//     }

//     int cnt=0;
//     for (int i=0; i<m; i++) {
//         for (int j=i+1; j<m; j++) {
//             for (int k=j+1; k<m; k++) {
//                 vector<string> cur;
//                 for (int l=0; l<n; l++) {
//                     string pos = "";
//                     pos = pos + dna[l][i] + dna[l][j] + dna[l][k];
//                     cur.push_back(pos);
//                 }

//                 for (int l=n; l<n*2; l++) {
//                     string pos = "";
//                     pos = pos + dna[l][i] + dna[l][j] + dna[l][k];
//                     if (find(cur.begin(), cur.end(), pos) != cur.end())
//                     {
//                         cnt--;
//                         break;
//                     }
//                 }
//                 cnt++;
//             }
//         }
//     }
//     cout << cnt;
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    vector<string> dna;
    for(int i=0;i<n*2;i++) {
        string a; cin >> a;
        dna.push_back(a);
    }

    int cnt=0;
    for (int i=0; i<m; i++) {
        for (int j=i+1; j<m; j++) {
            for (int k=j+1; k<m; k++) {
                unordered_map<string, int> cur;
                for (int l=0; l<n; l++) {
                    string pos = "";
                    pos = pos + dna[l][i] + dna[l][j] + dna[l][k];
                    cur[pos] = l;
                }

                for (int l=n; l<n*2; l++) {
                    string pos = "";
                    pos = pos + dna[l][i] + dna[l][j] + dna[l][k];
                    if (cur.count(pos))
                    {
                        cnt--;
                        break;
                    }
                }
                cnt++;
            }
        }
    }
    cout << cnt;
}