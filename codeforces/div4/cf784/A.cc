#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MOD 1e9+7
#define i64 long long
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define rep(i, a, b) for(int i = (a), __ = (b); i < __; ++i)

void solve() {
    int n; cin >> n;
    if (n <= 1399) cout << "Division 4\n";
    else if (n <= 1599) cout << "Division 3\n";
    else if (n <= 1899) cout << "Division 2\n";
    else cout << "Division 1\n";
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