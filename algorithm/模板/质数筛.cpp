#include <bits/stdc++.h>

using namespace std;

// 朴素质数筛
bool simple_prime_sieve(long long n)     {
    if (n <= 1)   return false;
    for (int i = 2; i * i <= n; ++i)     {
        if (n % i == 0) return false;
    }
    return true;
}

// 埃式筛
long long a[1 << 8];
bool v[1 << 8];
void angstrom_sieve(long long n)    {
    long long cnt = 0;
    memset(v, true, sizeof(a));
    for (int i = 2; i <= n; ++i)    {
        if (v[i])    {
            a[cnt++] = i;
            for (long long j = (i << 1); j <= n; j += i)    {
                v[j] = false;
            }
        }
    }
    // 打印
    for (int i = 0; i < cnt; ++i)    cout << a[i] << " ";
    cout << "\n";
}

// 欧拉筛
long long b[1 << 8], ct = 0;
bool vis[1 << 8];
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
    for (int i = 1; i <= ct; ++i)    cout << b[i] << " ";
    cout << "\n";
}

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << boolalpha << simple_prime_sieve(8) << "\n";
    // angstrom_sieve(50);
    euler_sieve(50);

    return 0;
}