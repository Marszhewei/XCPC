/**
 * @file lcs.cc
 * @author fetch150zy (Mars_zhewei@Outlook.com)
 * @brief 最长公共子序列
 * @version 0.1
 * @date 2022-12-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>

using std::cin, std::cout, std::endl;
using std::vector;

void solve()
{
    int n; cin >> n;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    vector<int> A(n+1);
    vector<int> B(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    for (int i = 1; i <= n; ++i)
        cin >> B[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (A[i] == B[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
    cout << dp[n][n] << endl;
}

int main(int argc, char **argv)
{
    solve();

    return 0;
}