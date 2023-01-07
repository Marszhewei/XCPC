/**
 * @file lis.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 最长不下降子序列
 * @version 0.1
 * @date 2022-12-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> A(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    int ans = 1;
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = 1;
        for (int j = 1; j < i; ++j)
            if (A[j] <= A[i]) {
                dp[i] = std::max(dp[i], dp[j]+1);
                ans = std::max(ans, dp[i]);
            }
    }
    cout << ans << endl;
}

int main(int argc, char **argv)
{
    solve();

    return 0;
}