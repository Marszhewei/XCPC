#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[10010], b[10010];
void sm() {
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i] + b[i-1];
    }
}

int main(void) {
    freopen("data.txt", "r", stdin);
    freopen("bout.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sm();
    for (int i = 1; i <= m; ++i) {
        long long op, x, y; cin >> op >> x >> y;
        if (op == 1) {
            a[x] = y;
            sm();
        }
        else {
            long long ans = 0;
            for (int i = x; i <= y; ++i) {
                ans += b[i];
            }
            cout << ans << '\n';
        }
    }
}