#include <bits/stdc++.h>
using namespace std;

void check(char a, char b, char c, vector<string> & pos1, vector<string> & pos2) {
    if (a==b && b==c) {
        if(find(begin(pos1), end(pos1), string(1, a)) == end(pos1)) {
            pos1.push_back(string(1, a));
        }
        return;
    }

    if (a==b) {
        if(find(begin(pos2), end(pos2), string(1, a)+string(1, c)) == end(pos2) && find(begin(pos2), end(pos2), string(1, c)+string(1, a)) == end(pos2)) {
            pos2.push_back(string(1, a)+string(1, c));
        }
        return;
    }
    if (b==c) {
        if(find(begin(pos2), end(pos2), string(1, b)+string(1, a)) == end(pos2) && find(begin(pos2), end(pos2), string(1, a)+string(1, b)) == end(pos2)) {
            pos2.push_back(string(1, b)+string(1, a));
        }
        return;
    }
    if (a==c) {
        if(find(begin(pos2), end(pos2), string(1, a)+string(1, b)) == end(pos2) && find(begin(pos2), end(pos2), string(1, b)+string(1, a)) == end(pos2)) {
            pos2.push_back(string(1, a)+string(1, b));
        }
        return;
    }
}

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    vector<string> board;
    string a, b, c; cin >> a >> b >> c;
    board.push_back(a);
    board.push_back(b);
    board.push_back(c);

    vector<string> pos1;
    vector<string> pos2;

    check(board[0][0], board[0][1], board[0][2], pos1, pos2);
    check(board[1][0], board[1][1], board[1][2], pos1, pos2);
    check(board[2][0], board[2][1], board[2][2], pos1, pos2);
    check(board[0][0], board[1][0], board[2][0], pos1, pos2);
    check(board[0][1], board[1][1], board[2][1], pos1, pos2);
    check(board[0][2], board[1][2], board[2][2], pos1, pos2);
    check(board[0][0], board[1][1], board[2][2], pos1, pos2);
    check(board[0][2], board[1][1], board[2][0], pos1, pos2);
    
    cout << pos1.size() << "\n" << pos2.size();
}