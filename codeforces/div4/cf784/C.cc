#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MOD 1e9+7
#define i64 long long
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define rep(i, a, b) for(int i = (a), __ = (b); i <= __; ++i)

void solve() {
    int n, t1, t2;
    cin >> n >> t1 >> t2;
    bool f1 = (t1%2==1) ? true : false, f2 = (t2%2==1) ? true : false, f = true;
    rep(i, 3, n) {
        int tt; cin >> tt;
        if (f) {
            if (i%2==1) {
                if (f1 && tt%2==0 || (!f1) && tt%2) {cout << "NO\n"; f = false;}
            }
            else {
                if (f2 && tt%2==0 || (!f2) && tt%2) {cout << "NO\n"; f = false;}
            }
        }
    }
    if (f) cout << "YES\n";
    return;
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