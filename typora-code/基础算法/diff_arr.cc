/**
 * @file diff_arr.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 差分数组和前缀和
 * @version 0.1
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <cstdlib>

using std::cin, std::cout, std::endl;
using std::vector;

void prefix_sum();
void solve();
void diff_arr();

int main(int argc, char **argv)
{
    prefix_sum();
    // solve();
    diff_arr();

    return 0;
}

void prefix_sum()
{
    vector<int> arr {1, 2, 3, 4, 5};
    vector<int> res(arr.size());
    std::partial_sum(arr.begin(), arr.end(), res.begin());
    for (auto x: res)
        cout << x << ' ';
    cout << endl;

    // 2d prefix sum
    std::srand(std::time(0));
    vector<vector<int>> arr2d(5, vector<int>(6, 0));

    vector<vector<int>> arr2d_res(arr2d);
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 6; ++j)
            arr2d[i][j] = std::rand() % 97;
    for (auto &ar: arr2d) {
        for (auto x: ar)
            cout << x << ' ';
        cout << endl;
    }
    // sum(i,j) = sum(i-1,j)+sum(i,j-1)-sum(i-1,j-1)+arr2d(i,j)
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            arr2d_res[i][j] = arr2d[i][j];
            if (i != 0 && j != 0)
                arr2d_res[i][j] -= arr2d_res[i-1][j-1];
            if (i > 0)
                arr2d_res[i][j] += arr2d_res[i-1][j];
            if (j > 0)
                arr2d_res[i][j] += arr2d_res[i][j-1];
        }
    }
    cout << endl;
    for (auto &ar: arr2d_res) {
        for (auto x: ar)
            cout << x << ' ';
        cout << endl;
    }
}

// luogu P1387
void solve()
{
    int m, n; cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n, 0));
    vector<vector<int>> b(a);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    // prefix sum
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            b[i][j] = a[i][j];
            if (i != 0 && j != 0)
                b[i][j] -= b[i-1][j-1];
            if (j > 0)
                b[i][j] += b[i][j-1];
            if (i > 0)
                b[i][j] += b[i-1][j];
        }
    int ans = 0, len = 1;
    while (len <= std::min(m, n)) {
        for (int i = len; i < m; ++i)
            for (int j = len; j < n; ++j)
                if (b[i][j] - b[i-len][j] - b[i][j-len] + b[i-len][j-len] == len*len)
                    ans = std::max(ans, len);
        ++len;
    }
    cout << ans << endl;
}

void diff_arr()
{
    vector<int> arr {1, 2, 3, 4, 5};
    vector<int> res(arr.size(), 0);
    vector<int> arr_copy(arr.size(), 0);
    for (auto x: arr)
        cout << x << ' ';
    cout << endl;
    std::partial_sum(arr.begin(), arr.end(), res.begin());
    for (auto x: res)
        cout << x << ' ';
    cout << endl;
    std::adjacent_difference(res.begin(), res.end(), arr_copy.begin());
    for (auto x: arr_copy)
        cout << x << ' ';
    cout << endl;
}
