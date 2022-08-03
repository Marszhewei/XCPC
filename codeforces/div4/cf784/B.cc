#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MOD 1e9+7
#define i64 long long
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define rep(i, a, b) for(int i = (a), __ = (b); i < __; ++i)

void solve() {
    int n, cnt = 1; cin >> n;
    vector<int> v;
    forn(i, n) {int tt; cin >> tt; v.push_back(tt);}
    sort(v.begin(), v.end());
    rep(i, 1, n) {
        if (v[i] == v[i-1]) cnt++;
        else cnt = 1;
        if (cnt >= 3) {cout << v[i] << '\n'; return;}
    }
    cout << -1 << '\n';
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