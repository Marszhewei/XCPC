/**
 * @file dp.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 基础动态规划
 * @version 0.1
 * @date 2022-12-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 数字三角形
int ans = 0;
void dfs(int level, int tans, int pos, vector<vector<int>> &a, int r)
{
    if (level == r-1) {
        ans = max(ans, tans);
        return ;
    }
    dfs(level+1, tans+a[level+1][pos], pos, a, r);
    dfs(level+1, tans+a[level+1][pos+1], pos+1, a, r);
}

int dfs(int level, int pos, vector<vector<int>> &a, int r)
{
    if (level < r-1) {
        auto ans1 = dfs(level+1, pos, a, r) + a[level+1][pos];
        auto ans2 = dfs(level+1, pos+1, a, r) + a[level+1][pos+1];
        return max(ans1, ans2);
    }
    return 0;
}

int heuristic_dfs(int level, int pos, vector<vector<int>> &a, int r, vector<int> &mem)
{
    if (mem[level] != -1) return mem[level];
    if (level < r-1) {
        auto ans1 = dfs(level+1, pos, a, r) + a[level+1][pos];
        auto ans2 = dfs(level+1, pos+1, a, r) + a[level+1][pos+1];
        return mem[level] = max(ans1, ans2);
    }
    return mem[level] = 0;
}

void solve()
{
    int r; cin >> r;
    vector<vector<int>> a;
    vector<int> mem(r+1, -1);
    for (int i = 1; i <= r; ++i) {
        vector<int> tmp(i);
        for (int j = 0; j < i; ++j) {
            cin >> tmp[j];
        }
        a.push_back(tmp);
    }

    // dfs(0, a[0][0], 0, a, r);
    // cout << ans << endl;
    // cout << dfs(0, 0, a, r) + a[0][0] << endl;
    cout << heuristic_dfs(0, 0, a, r, mem) + a[0][0] << endl;

    vector<int> dp
}

int main(int argc, char **argv)
{
    solve();

    return 0;
}