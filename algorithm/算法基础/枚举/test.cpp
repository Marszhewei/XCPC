/*
一个数组中的数互不相同，求其中和为  的数对的个数。
*/

#include <bits/stdc++.h>
using namespace std;

#define _fn(i, a, b) for(int i = (a), __ = (b); i < __; ++i)
const int MAXSIZE = 105, MAXN = (1<<16);
int a[MAXSIZE], n;
// 朴素写法
inline int solve_1()    {
    int ans = 0;
    _fn(i, 0, n)    
        _fn(j, 0, n)
            if (a[i] + a[j] == 0)    ++ans;
    return ans;
}

// 小优化
inline int solve_2()     {
    int ans = 0;
    _fn(i, 0, n)
        _fn(j, 0, i)
            if (a[i] + a[j] == 0)    ++ans;
    return ans/2;
}

// 最终优化
bool bkt[MAXN * 2];
inline int solve()    {
    int ans = 0;
    memset(bkt, false, sizeof(bkt));
    _fn(i, 0, n)    {
        if (bkt[MAXN - a[i]])    ++ans;
        bkt[MAXN + a[i]] = true;
    }
    return ans;
}

int main(void)    {
    cin >> n;
    _fn(i, 0, n) cin >> a[i];
    cout << solve_1() << '\n';
    cout << solve_2() << '\n';
    cout << solve() << '\n';
    return 0;
}