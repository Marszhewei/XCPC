#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define rep(i, a, b) for(int i = (a), __ = (b); i <= __; ++i)
#define PRIME_SIZE 7100

set<LL> s;

LL b[PRIME_SIZE], ct = 0;
bool vis[PRIME_SIZE];
void euler_sieve(LL n)    {
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
    cin.tie(0);
    
    LL n;
    cin >> n;
    euler_sieve((LL)sqrt(n));
    rep(i, 1, ct) 
        rep(j, 1, ct) 
            rep(k, 1, ct)     {
                LL val = b[i]*b[i] + b[j]*b[j]*b[j] + b[k]*b[k]*b[k]*b[k];
                if (val > n) break;
                s.insert(val);
            }
    cout << s.size() << '\n';
    return 0;
}