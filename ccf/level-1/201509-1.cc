#include <bits/stdc++.h>
using namespace std;

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cnt = 1, t; cin >> n;
    n--;
    cin >> t;
    while (n--) {
        int tt; cin >> tt;
        if (tt != t) cnt++, t = tt;
    }
    cout << cnt << '\n';
    return 0;
}