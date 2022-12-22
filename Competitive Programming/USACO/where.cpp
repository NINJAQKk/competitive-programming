#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

const int MAX = 20;
string grid[MAX][MAX];
int rows, cols;

void floodfill (int row, int col, string type, bool visited[MAX][MAX]) {
    
    if (visited[row][col]) {return;}
    if (grid[row][col] != type || row<0 || row>rows || col<0 || col>cols) {
        return;
    }
    visited[row][col] = true;

    floodfill(row+1,col,type, visited);
    floodfill(row-1,col,type, visited);
    floodfill(row,col+1,type, visited);
    floodfill(row,col-1,type, visited);
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("test.in", "r", stdin);
    // freopen("where.out", "w", stdout);
    cin.tie(0);

    cin >> rows;
    cols = rows;

    fr(r, rows) {
        string temp; cin >> temp;
        fr(c, cols) {
            grid[r][c] = temp[c];
        }
    }

    vector<array<int, 4>> done;
    for (int rb=0; rb<rows; rb++) {
        for (int cb=0; cb<cols; cb++) {
            for (int re=rb; re<rows; re++) {
                for (int ce=cb; ce<cols; ce++) {
                    bool temp[MAX][MAX] = {false};
                    vector<string> visited;
                    unordered_set<string> unique;
                    for (int r=rb; r<re+1; r++) {
                        for (int c=cb; c<ce+1; c++) {
                            if (!temp[r][c]) {
                                visited.pb(grid[r][c]);
                                unique.insert(grid[r][c]);
                                floodfill(r, c, grid[r][c], temp);
                            }
                        }
                    }
                    sort(all(visited));
                    if (visited.size()>=3) {
                        if (unique.size()==2 && (visited[0]!=visited[1] || visited[(int)visited.size()-1]!=visited[(int)visited.size()-2])) {
                            bool run = true;
                            for (int i=0; i<(int)done.size(); i++) {
                                if (rb>=done[i][0] && re<=done[i][1] && cb>=done[i][2] && ce<=done[i][3]) {
                                    run = false;
                                }
                                if (rb<=done[i][0] && re>=done[i][1] && cb<=done[i][2] && ce>=done[i][3]) {
                                    done.erase(done.begin()+i);
                                    i--;
                                }
                            }
                            if (run) {
                                done.pb({rb, re, cb, ce});
                                
                            }
                        }
                    }
                }
            }
        }
    }

    cout << done.size() << endl;
    cout << done[0][0] << " " << done[0][1] << " " << done[0][2] << " " << done[0][3] << " ";
}