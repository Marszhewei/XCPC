/**
 * @file dfs.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 深度优先搜索
 * @version 0.1
 * @date 2022-12-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
#include <bitset>
#include <iomanip>

// 数分解
int m = 3, arr[103]; // arr 用于记录方案
void dfs(int n, int i, int a)
{
    if (i > m) return ;
    if (n == 0 && i == m) {
        for (int j = 0; j < m; ++j)
            std::cout << arr[j] << ' ';
        std::cout << std::endl;
        return ;
    }
    for (int j = a; j <= n; ++j) {
        arr[i] = j;
        dfs(n - j, i + 1, j + 1);
    }
}


// 全排列
void dfs(int step, std::vector<int> &a, bool vis[], int n)
{
    if (step == n) {
        for (int i = 0; i < n; ++i)
            std::cout << std::setw(5) << a[i];
        std::cout << std::endl;
        return ;
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            vis[i] = true;
            a[step] = i;
            dfs(step + 1, a, vis, n);
            vis[i] = false;
        }
    }
}

int main(int argc, char **argv)
{
    // const int size = 50;
    // std::vector<int> a(50, 0);
    // bool vis[size];
    // std::fill(vis, vis+size, 0);
    // int n; std::cin >> n;
    // dfs(0, a, vis, n);

    dfs(6, 0, 1);

    return 0;
}