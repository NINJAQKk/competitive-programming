#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

const int MAX = 1000;
string grid[MAX][MAX];
bool visited[MAX][MAX] = {false};
int rows, cols;

void floodfill (int row, int col, string type) {
    if (visited[row][col] || grid[row][col] != type || row<0 || row>rows || col<0 || col>cols) {
        return;
    }

    visited[row][col] = true;

    floodfill(row+1,col,type);
    floodfill(row-1,col,type);
    floodfill(row,col+1,type);
    floodfill(row,col-1,type);
}

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("test.in", "r", stdin);
    cin.tie(0);

    cin >> rows >> cols;

    fr(r, rows) {
        string temp; cin >> temp;
        fr(c, cols) {
            grid[r][c] = temp[c];
        }
    }

    int ans=0;
    fr(r, rows) {
        fr(c, cols) {
            if (!visited[r][c] && grid[r][c]==".") {
                floodfill(r, c, grid[r][c]);
                ans++;
            }
        }
    }
    cout << ans;
}