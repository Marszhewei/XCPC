#include <bits/stdc++.h>
using namespace std;
#define i64 long long

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, kk, k, t, cnt = 0;
    cin >> n >> kk;
    k = kk;
    while (n--) {
        if (k <= 0) k = kk;
        cin >> t;
        if (t >= k) cnt++;
        k -= t;
    }
    if (k > 0) cnt++;
    cout << cnt << '\n';

    return 0;
}