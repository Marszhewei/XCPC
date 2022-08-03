#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MOD 1e9+7
#define i64 long long
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define rep(i, a, b) for(int i = (a), __ = (b); i <= __; ++i)

void solve() {
    i64 a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (x+y>a+b+c) cout << "NO\n";
    else if (x>a+c || y>b+c) cout << "NO\n";
    else cout << "YES\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}