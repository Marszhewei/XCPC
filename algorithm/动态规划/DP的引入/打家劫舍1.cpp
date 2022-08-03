// dp 四要素
// 1、定义dp数组含义
// 2、定义状态转移方程
// 3、初始化过程转移的初始值
// 4、可优化点

#include <bits/stdc++.h>

int dp[1<<8];
using namespace std;
int main(int argc, char** argv)    {
    int nums[1<<8];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)    {
        cin >> nums[i];
    }
    // 初始化过程转移的初始值
    dp[0] = 0;
    dp[1] = nums[0];
    // 偷：dp[i] = dp[i-2] + nums[i-1]
    // 不偷：dp[i] = dp[i-1]
    for (int i = 2; i <= n; ++i)    {
        dp[i] = max(dp[i-1], nums[i-1]+dp[i-2]);
    }
    cout << "res: " << dp[n] << '\n';

    return 0;
}