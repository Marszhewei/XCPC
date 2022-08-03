#include <bits/stdc++.h>

using namespace std;

long long dp[1<<16];
void solve(long long n)    {
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)    {
        dp[i] = dp[i-1] + dp[i-2];
    }
}

int main(void)    {

    // by dp 
    // F(0) = 0,  F(1) = 1
    // F(N) = F(N-1) + F(N-2) N>1
    long long n;
    cin >> n;
    solve(n);
    for (int i = 1; i <= n; ++i)    {
        cout << dp[i] << ' ';
    }
    cout << '\n';

    return 0;
}