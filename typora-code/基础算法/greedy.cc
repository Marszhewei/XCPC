/**
 * @file greedy.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 贪心算法
 * @version 0.1
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::cin, std::cout, std::endl;
using std::vector, std::priority_queue;

// NOIP 2012 国王游戏  60分，100分需要高精
struct uv {
    long long l, r;
    bool operator<(const uv &x) const {
        return std::max(x.r, l*r) < std::max(r, x.l*x.r);
    }
};

void solve_noip2012_kinggame()
{
    int n;
    cin >> n;
    vector<uv> v(n);
    long long int kl, kr;
    cin >> kl >> kr;
    for (int i = 0; i < n ;++i)
        cin >> v[i].l >> v[i].r;
    std::sort(v.begin(), v.end());
    long long max_coins = -1;
    for (int i = 0; i < n; ++i) {
        if (kl / v[i].r > max_coins) max_coins = kl / v[i].r;
        kl *= v[i].l;
    }
    cout << max_coins << endl;
}

// 「USACO09OPEN」工作调度 Work Scheduling
struct f {
    long long d;
    long long p;
} a[100005];

bool cmp(f A, f B) { return A.d < B.d; }

priority_queue<long long, vector<long long>, std::greater<long long>> q;

void solve_USACO09OPEN() {
    long long n, i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i].d >> a[i].p; 
    std::sort(a + 1, a + n + 1, cmp);
    long long ans = 0;
    for (i = 1; i <= n; i++) {
        if (a[i].d <= (int)q.size()) {  // 超过截止时间
            if (q.top() < a[i].p) {       // 后悔
                ans += a[i].p - q.top();
                q.pop();
                q.push(a[i].p);
            }
        } else {  // 直接加入队列
            ans += a[i].p;
            q.push(a[i].p);
        }
    }
    cout << ans << endl;
}

int main(int argc, char **argv)
{
    // solve_noip2012_kinggame();
    solve_USACO09OPEN();
    return 0;
}