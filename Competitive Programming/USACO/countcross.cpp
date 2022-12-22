#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define fr(i, x) for (int i = 0; i < x; i++)

const int MAX = 100;
int grid[MAX][MAX];
bool visited[MAX][MAX] = {false};
int rows, cols;
unordered_set<string> cowset;

struct Road {
    int r1, c1, r2, c2;
    Road(int r1, int c1, int r2, int c2) : r1(r1), c1(c1), r2(r2), c2(c2) {}
    bool operator==(const Road& other) const {
        return (r1 == other.r1 && c1 == other.c1 && r2 == other.r2 && c2 == other.c2)
            || (r1 == other.r2 && c1 == other.c2 && r2 == other.r1 && c2 == other.c1);
    }
};

int floodfill(int row, int col, int type, bool visited[MAX][MAX], int group[MAX][MAX], int rp, int cp, vector<Road>& roads) {
    if (visited[row][col]) {return 0;}
    if ((grid[row][col] != type && grid[row][col] > 0) || row<0 || row>rows || col<0 || col>cols) {
        return 0;
    }
    for (const Road& road : roads) {
        if ((row == road.r1 && col == road.c1 && rp == road.r2 && cp == road.c2) ||
            (row == road.r2 && col == road.c2 && rp == road.r1 && cp == road.c1)) {
            return 0;
        }
    }
    visited[row][col] = true;
    grid[row][col] = type;

    int cows = 0;
    if (cowset.count(to_string(row) + " " + to_string(col))) {cows = 1;}
    return cows + floodfill(row+1,col,type, visited, group, row, col, roads) +
               floodfill(row-1,col,type, visited, group, row, col, roads) +
               floodfill(row,col+1,type, visited, group, row, col, roads) +
               floodfill(row,col-1,type, visited, group, row, col, roads);
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    cin.tie(0);

    int n, k, r; cin >> n >> k >> r;
    rows = n-1;
    cols = n-1;

    vector<Road> roads;
    fr(i, r) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        roads.emplace_back(--a, --b, --c, --d);
    }

    fr(i, k) {
        int a, b; cin >> a >> b;
        cowset.insert(to_string(--a) + " " + to_string(--b));
    }

    int groups[MAX*MAX] = {0};
    int cur = 1;
    fr(i, n) {
        fr(j, n) {
            if (grid[i][j]==0) {
                int cows = floodfill(i, j, cur, visited, grid, -1, -1, roads);
                groups[cur-1] = cows;
                cur++;
            }
        }
    }

    int ans = 0;
    fr(i, cur-1) {
        for(int j=i+1; j<cur-1; j++) {
            ans += groups[i] * groups[j];
        }
    }

    cout << ans;
}
