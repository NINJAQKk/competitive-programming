#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr);
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string word, sub; cin >> word >> sub;
    int pos = word.find(sub);
    while(pos >= 0) {
        word.erase(pos, (int)sub.size());
        pos = word.find(sub);
    }
    // bool done = false;
    // int hold = 0;
    //         int pos = 0;
    // while (!done) {
    //     int j = 0;
    //     for (int i = max(0, hold-(int)sub.size()); i < (int) word.size(); i++) {
    //         if (word[i] == sub[j]) {
    //             j++;
    //             if (j==1) {
    //                 hold = i;
    //             }
    //             if (j == (int) sub.size()) {
    //                 pos = ++i-j;
    //                 break;
    //             }
    //         }
    //         else {
    //             if (j > 0) {
    //                 i = hold;
    //                 j = 0;
    //             }
    //         }
    //         if (i == (int) word.size()-1) {
    //             done = true;
    //         }
    //     }
    //     if (!done){
    //         word = word.substr(0, pos) + word.substr(pos + sub.size(), word.size() - (pos + sub.size()));
    //     }
    // }
    std::cout << word;
}