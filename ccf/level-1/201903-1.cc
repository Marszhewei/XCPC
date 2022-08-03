#include <bits/stdc++.h>
using namespace std;
#define i64 long long 

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    i64 n, minn, maxn, m1 = 0, m2 = 0, mid;
    cin >> n;
    bool flag = (n % 2 == 1) ? true : false;
    for (int i = 0; i < n; ++i) {
        i64 t; cin >> t;
        if (i == 0) maxn = t;
        if (i == n-1) minn = t;
        if (flag && i == n/2) mid = t;
        if (!flag && i == n/2-1) m1 = t;
        if (!flag && i == n/2) m2 = t;
    }
    cout.setf(ios::fixed,ios::floatfield);
    if (flag) cout << max(maxn, minn) << ' ' << mid << ' ' << min(maxn, minn) << '\n';
    else if (!flag && (m1+m2)%2==0) cout << max(maxn, minn) << ' ' << (m1+m2)/2 << ' ' << min(maxn, minn) << '\n';
    else cout <<  setprecision(1) << max(maxn, minn) << ' ' << (m1+m2)/2.0 << ' ' << min(maxn, minn) << '\n';
    return 0;
}