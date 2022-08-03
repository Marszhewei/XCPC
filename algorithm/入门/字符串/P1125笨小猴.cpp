#include <bits/stdc++.h>
#define INF 1 << 8

using namespace std;

bool is_prime(int n)    {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)    {
        if (n % i == 0)    return false;
    }
    return true;
}

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int maxn = -INF, minn = INF;
    cin >> s;
    for (int i = 0; i < s.size(); ++i)    {
        int t = count(s.begin(), s.end(), s[i]);
        maxn = max(t, maxn);
        minn = min(t, minn);
    }
    if (is_prime(maxn-minn))    cout << "Lucky Word\n" << maxn - minn << '\n';
    else    cout << "No Answer\n0\n";
}