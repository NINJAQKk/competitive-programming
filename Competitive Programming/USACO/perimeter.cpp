#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

const int MAX = 1000;
string grid[MAX][MAX];
bool visited[MAX][MAX] = {false};
int rows, cols, cnt1, cnt2;

void floodfill (int row, int col, string type) {
    
    if (visited[row][col]) {return;}
    if (grid[row][col] != type || row<0 || row>rows || col<0 || col>cols) {
        cnt2++;
        return;
    }
    visited[row][col] = true;
    cnt1++;

    floodfill(row+1,col,type);
    floodfill(row-1,col,type);
    floodfill(row,col+1,type);
    floodfill(row,col-1,type);
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin.tie(0);

    cin >> rows;
    cols = rows;

    fr(r, rows) {
        string temp; cin >> temp;
        fr(c, cols) {
            grid[r][c] = temp[c];
        }
    }

    int area=0, peri=0;
    fr(r, rows) {
        fr(c, cols) {
            if (!visited[r][c] && grid[r][c]=="#") {
                cnt1 = 0;
                cnt2 = 0;
                floodfill(r, c, grid[r][c]);
                if (cnt1 == area) {
                    area = cnt1;
                    peri = min(peri, cnt2);
                } else if (cnt1 > area) {
                    area = cnt1;
                    peri = cnt2;
                }
            }
        }
    }
    cout << area << " " << peri;
}