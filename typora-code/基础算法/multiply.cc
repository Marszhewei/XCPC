/**
 * @file multiply.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 倍增算法
 * @version 0.1
 * @date 2022-12-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <cstdio>
using namespace std;

const int mod = 1000000007;

int modadd(int a, int b)
{
    if (a + b >= mod)
        return a + b - mod; // 减法代替取模，加快运算
    return a + b;
}

int vi[1000005];

int go[75][1000005]; // 将数组稍微开大以避免越界，小的一维尽量定义在前面
int sum[75][1000005];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", vi + i);

    for (int i = 1; i <= n; ++i) {
        go[0][i] = (i + k) % n + 1;
        sum[0][i] = vi[i];
    }

    int logn = 31 - __builtin_clz(n); // 一个快捷的取对数的方法
    for (int i = 1; i <= logn; ++i)
        for (int j = 1; j <= n; ++j) {
            go[i][j] = go[i - 1][go[i - 1][j]];
            sum[i][j] = modadd(sum[i - 1][j], sum[i - 1][go[i - 1][j]]);
        }

    long long m;
    scanf("%lld", &m);

    int ans = 0;
    int curx = 1;
    for (int i = 0; m; ++i) {
        if (m & (1ll << i)) { // 参见位运算的相关内容，意为 m 的第 i 位是否为 1
            ans = modadd(ans, sum[i][curx]);
            curx = go[i][curx];
            m ^= 1ll << i; // 将第 i 位置零
        }
    }

    printf("%d\n", ans);
}