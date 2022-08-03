#include <bits/stdc++.h>
using namespace std;

long long b[6000005], ct = 0;
bool vis[100000005];
void euler_sieve(long long n)    {
    memset(b, 0, sizeof(b));
    memset(vis, true, sizeof(vis));
    for (int i = 2; i <= n; ++i)    {
        if (vis[i])    b[++ct] = i;
        for (int j = 1; j <= ct; ++j)    {
            if (b[j] * i > n) break;
            vis[b[j] * i] = false;
            if (i % b[j] == 0) break;
        }
    }
}

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    euler_sieve(n);
    while (k--)    {
        int t;
        cin >> t;
        cout << b[t] << '\n';
    }

    return 0;
}