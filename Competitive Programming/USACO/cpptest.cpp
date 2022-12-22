#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[] = {3, 1, 7, 2, 9, 8, 4};
    sort(a, a+2);
    for (int item : a) {
        cout << item << " ";
    }
    cout << endl << *(a+5);
}