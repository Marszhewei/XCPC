#include <bits/stdc++.h>
using namespace std;
#define i64 long long

i64 T[300005];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(T, 0, sizeof(T));
    i64 n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        i64 tt, nn; cin >> tt >> nn;
        i64 sidx = (tt-nn)<0?1LL:(tt-nn+1), eidx = tt+1;
        T[sidx]++, T[eidx]--;
    }
    for (int i = 1; i <= 300005; ++i) T[i] += T[i-1];
    for (int i = 1; i <= m; ++i) {
        i64 t; cin >> t;
        cout << T[t+k] << '\n';
    }
    return 0;
}