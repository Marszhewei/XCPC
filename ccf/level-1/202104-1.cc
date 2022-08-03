#include <bits/stdc++.h>
using namespace std;
#define i64 long long

i64 hashmp[256];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(hashmp, 0, sizeof(hashmp));
    i64 n, m, L, t;
    cin >> n >> m >> L;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            {cin >> t; hashmp[t]++;}
    for (int i = 0; i < L; ++i) cout << hashmp[i] << ' ';
    cout << '\n';
    return 0;
}