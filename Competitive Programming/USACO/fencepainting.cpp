#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(b, d) - min(a, c);
}