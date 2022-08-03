#include <bits/stdc++.h>

using namespace std;
int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k, s = 0, i = 1, n = 1;
    cin >> k;
    for ( ; i <= k; n++, i += n)    {
        s += n * n;
    }
    cout << s + abs(k - i + n) * n << "\n";
    return 0;
}