#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MOD 1e9+7
#define i64 long long
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define rep(i, a, b) for(int i = (a), __ = (b); i < __; ++i)

void solve() {
    string s; cin >> s;
    if (s.length() <= 1 || s.front() == '0' || s.back() == '1') cout << 1 << '\n';
    else {
        if (s.find('1') == -1 && s.find('0') == -1) cout << s.length() << '\n';
        else {
            int cnt = 0;
            forn(i, s.length()) {
                if (s.length()-1 == i) {cout << cnt+1 << '\n'; return;}
                else if (s[i] == '1') cnt = 1;
                else if (s[i] == '?') cnt++;
                else {cout << cnt+1 << '\n'; return;}
            }
        }
    }
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