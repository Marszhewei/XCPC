#include <bits/stdc++.h>

using namespace std;
int main(int argc, char** argv)    {
    // int dp[105][105];
    // 空间优化项
    int dp[105];

    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; ++i)     dp[i] = 1;
    
    // for (int i = 1; i < m; ++i)    {
    //     for (int j = 1; j < n; ++j)    {
    //         dp[i][j] = dp[i][j-1] + dp[i-1][j];
    //     }
    // }
    for (int i = 1; i < m; ++i)    {
        for (int j = 1; j < n; ++j)    {
            dp[j] += dp[j-1];
        }
    }
    cout << "res: " << dp[n-1] << '\n';
    return 0;
}