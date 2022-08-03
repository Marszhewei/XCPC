#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL N = 110;
const LL mod = LL(1e9+7);
struct matrix {
    LL a[N][N];
    matrix(){memset(a, 0, sizeof(a));}
};
LL n;
matrix res;


matrix multi(matrix a, matrix b)    {
    matrix c;
    for (int i = 0; i < n; ++i)    {
        for (int j = 0; j < n; ++j)    {
            for (int k = 0; k < n; ++k)    {
                c.a[i][j] = ((a.a[i][k] * b.a[k][j]) % mod + c.a[i][j]) % mod;
            }
        }
    }
    return c;
}

void quick_pow(matrix& a, LL k)    {
    for (int i = 0; i < n; ++i)    res.a[i][i] = 1; // 单位矩阵
    while (k)    {
        if (k & 1)    res = multi(res, a);
        k >>= 1;
        a = multi(a, a);
    }
    return;
}

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL k;
    matrix a;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a.a[i][j];

    quick_pow(a, k);
    for (int i = 0; i < n; ++i)    {
        for (int j = 0; j < n; ++j) 
            cout << res.a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}