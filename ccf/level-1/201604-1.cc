#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int now, next, n, cnt = 0;
    bool status = false;
    cin >> n;
    cin >> now;
    cin >> next;
    n -= 2;
    if (n <= 2) {cout << 0 << '\n'; return 0;}
    if (next > now) status = true;
    while (n--)    {
        now = next;
        cin >> next;
        if (next > now && !status) {cnt++; status = true;}
        else if (next < now && status) {cnt++; status = false;}
    }
    cout << cnt << '\n';
    return 0;
}