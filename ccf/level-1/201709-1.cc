#include <bits/stdc++.h>
using namespace std;
#define i64 long long

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(0);

    i64 n, cnt = 0; cin >> n;
    if (n >= 50) cnt += (n/50)*7;
    n %= 50;
    if (n >= 30) cnt += (n/30)*4;
    n %= 30;
    if (n >= 10) cnt += (n/10);
    cout << cnt << '\n';
    return 0;
}