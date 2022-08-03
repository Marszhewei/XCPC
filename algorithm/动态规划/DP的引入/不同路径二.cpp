#include <bits/stdc++.h>

using namespace std;
int main(int argc, char** argv)    {
    int base[105][105];
    int dp[105][105];

    int m, n;
    cin >> m >> n;
    // 输入地图
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> base[i][j];

    // 行初始化
    for (int i = 1; i < n; ++i)     {
        if (base[0][i-1] == 1)    {
            if (i != n-1)
                base[0][i] = 1;
            dp[0][i-1] = 0;
        }
        else    dp[0][i-1] = 1;
    }
    dp[0][n-1] = !base[0][n-1];
    // 列初始化
    for (int i = 0; i < m; ++i)    {
        if (base[i-1][0] == 1)    {
            base[i][0] = 1;
            dp[i-1][0] = 0;
        }
        else    dp[i-1][0] = 1;
    }
    dp[m-1][0] = !base[m-1][0];
    
    for (int i = 1; i < m; ++i)    {
        for (int j = 1; j < n; ++j)    {
            if (base[i][j] == 0)
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            else    dp[i][j] = 0;
        }
    }

    for (int i = 0; i < m; ++i)    {
        for (int j = 0; j < n; ++j)    {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << "res: " << dp[m-1][n-1] << '\n';
    return 0;
}