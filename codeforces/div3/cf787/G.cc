#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MOD 1e9+7
#define i64 long long
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define rep(i, a, b) for(int i = (a), __ = (b); i < __; ++i)

void solve() {
    int n, m, mm, cnt = 0; cin >> n >> m;
    vector<int> v(n);
    mm = m;
    forn(i, n) cin >> v[i];
    for (int i = n-1; i > 0; --i) {
        if (v[i]*i <= (m-v[i])) m -= v[i];
        else {
            cnt += v[i]*i - (m-v[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}