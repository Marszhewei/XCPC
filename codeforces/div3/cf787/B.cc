#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MOD 1e9+7
#define i64 long long
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define rep(i, a, b) for(int i = (a), __ = (b); i < __; ++i)

void solve() {
    int n, cnt = 0; cin >> n;
    vector<i64> v(n);
    forn(i, n) cin >> v[i];
    for (int i = n-1; i > 0; --i) {
        if (v[i] == 0) {cout << -1 << '\n'; return;}
        if (v[i] <= v[i-1]) {
            while (v[i] <= v[i-1]) {
                v[i-1] /= 2;
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}