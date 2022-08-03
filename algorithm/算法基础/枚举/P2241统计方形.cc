#include <bits/stdc++.h>
using namespace std;
#define i64 long long

void solve() {
    int m, n; cin >> m >> n;
    i64 cnt_sq = 0, cnt_re = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) cnt_sq += (m-i)*(n-j);
            else cnt_re += (m-i)*(n-j);
        }
    }
    cout << cnt_sq << ' ' << cnt_re << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}