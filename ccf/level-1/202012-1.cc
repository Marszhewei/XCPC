#include <bits/stdc++.h>
using namespace std;
#define i64 long long 

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, wi, si, s = 0;
    cin >> n;
    while (n--) {
        cin >> wi >> si;
        s += wi * si;
    }
    cout << max(0LL, s) << '\n';
    return 0;
}