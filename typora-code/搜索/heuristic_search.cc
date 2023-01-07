/**
 * @file heuristic_search.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 启发式搜索
 * @version 0.1
 * @date 2022-12-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


// NOIP2005 采药
// dp解法: dp[i][j] j容量背包放入i件物品的最大价值
void solve_dp()
{
    int t, m; cin >> t >> m;
    vector<int> w(m+1, 0), v(m+1, 0);
    for (int i = 1; i <= m; ++i)
        cin >> w[i] >> v[i];
    vector<int> dp(t+1, 0);
    for (int i = 1; i <= m; ++i) {
        for (int j = t; j >= 0; --j) {
            if (j >= w[i]) {
                dp[j] = max(dp[j-w[i]]+v[i], dp[j]);
            }
        }
    }
    cout << dp[t] << endl;
}

int n,t;
int tcost[103],mget[103];
int ans = 0;
void dfs1(int tleft, int tans, int pos)
{
    if (tleft < 0) return ;
    if (pos == n + 1) {
        ans = std::max(ans, tans);
        return ;
    }
    dfs1(tleft, tans, pos+1); // dp[i][j] = dp[i-1][j]
    dfs1(tleft-tcost[pos], tans+mget[pos], pos+1); // dp[i][j] = dp[i-1][j-w[i]]+v[i]
}

int dfs2(int pos, int tleft)
{
    if (pos = n+1)
        return 0;
    int dfs_1, dfs_2 = -1;
    dfs_1 = dfs2(pos+1, tleft);
    if (tleft >= tcost[pos])
        dfs_2 = dfs2(pos+1, tleft-tcost[pos]) + mget[pos];
    return std::max(dfs_1, dfs_2);
}

int mem[1003];
int dfs3(int pos, int tleft)
{
    if (mem[tleft] != -1) return mem[tleft];
    if (pos == n+1)
        return mem[tleft] = 0;
    int dfs_1, dfs_2 = -1;
    dfs_1 = dfs3(pos+1, tleft);
    if (tleft >= tcost[pos])
        dfs_2 = dfs3(pos+1, tleft-tcost[pos]) + mget[pos];
    return mem[tleft] = std::max(dfs_1, dfs_2);
}

void solve_dfs()
{
    memset(mem, -1, sizeof(mem));
    cin >> t >> n;
    for (int i = 1; i <= n; ++i)
        cin >> tcost[i] >> mget[i];
    cout << dfs2(1, t) << endl;
}

int main(int argc, char **argv)
{
    // solve_dp();
    solve_dfs();
}