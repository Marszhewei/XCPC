#include <bits/stdc++.h>

using namespace std;

const long long MAXN = int(1e7) + 10;
int cnt = 0;
bool vis[MAXN];

bool is_palindrome(int n)    {
    stringstream ss;
    ss << n;
    string s, s1;
    ss >> s;
    s1 = s;
    reverse(s.begin(), s.end());
    if (s1 == s) return true;
    return false;
}

// void euler_sieve(int m, int n)    {
//     n = (n > int(1e7)) ? int(1e7) : n;
//     memset(b, 0, sizeof(b));
//     memset(vis, true, sizeof(vis));
//     for (int i = 2; i <= n; ++i)    {
//         if (vis[i])    b[++cnt] = i;
//         for (int j = 1; j <= cnt; ++j)    {
//             if (b[j] * i > n) break;
//             vis[b[j] * i] = false;
//             if (i % b[j] == 0) break;
//         }
//     }
//     for (int i = 1; i <= cnt; ++i)    
//         if (is_palindrome(b[i]) && b[i] >= m) cout << b[i] << "\n";
// }


void angstrom_sieve(long long m, long long n)    {
    n = (n > int(1e7)) ? int(1e7) : n;
    memset(vis, true, sizeof(vis));
    for (int i = 2; i <= n; ++i)    {
        if (vis[i])    {
            if (is_palindrome(i) && i >= m) cout << i << "\n";
            for (long long j = (i << 1); j <= n; j += i)    {
                vis[j] = false;
            }
        }
    }
}

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    // euler_sieve(m ,n);
    angstrom_sieve(m, n);
    
    return 0;
}