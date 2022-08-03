#include <bits/stdc++.h>
using namespace std;

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, now, next, sub = 0;
    cin >> n;
    cin >> now >> next;
    sub = max(sub, abs(next - now));
    n -= 2;
    while (n--)    {
        now = next;
        cin >> next;
        sub = max(sub, abs(next - now));
    }
    cout << sub << '\n';
    return 0;
}