#include <bits/stdc++.h>

using namespace std;

// 快速幂
long long quick_pow(long long x, long long n, long long mod)    {
    long long res = 1LL;
    while (n)    {
        if (n & 1)    res = res * x % mod;
        n >>= 1;
        x = x * x % mod;
    }
    return res;
}

// 快排
void quick_sort(long long a[], long long left, long long right)    {
    if (left > right)    return;
    long long l = left, r = right, mid = a[l];
    do    {
        while (a[l] < mid)    l++;
        while (a[r] > mid)    r--;
        if (l <= r)    {
            swap(a[l], a[r]);
            l++, r--;
        }
    }while (l <= r);
    quick_sort(a, left, r);
    quick_sort(a, l, right);
}

// 最大公约数（递归写法）
long long gcd(long long a, long long b)    {
    return b ? gcd(b, a%b) : a;
}
// 最大公约数（迭代写法）
long long gcd_1(long long a, long long b)    {
    long long t;
    while (a % b)    {
        t = a % b;
        a = b;
        b = t;
    }
    return b;
}
long long gcd_2(long long a, long long b)    {
    while (a % b)    {
        a = b ^ a % b;
        b = a ^ b;
        a = a ^ b;
    }
    return b;
}

// 二分（左闭右闭）
bool bin_s(vector<long long> v, long long x)    {
    int left = 0, right = v.size() - 1, mid;
    while (left <= right)    {
        mid = (left + right) / 2;
        if (v[mid] == x)    return true;
        else if (v[mid] < x)    left = mid + 1;
        else    right = mid - 1;
    }
    return false;
}

//  埃氏筛
const long long MAXN = (long long)(1e3)+10;
long long b[MAXN], cnt = 0;
bool vis[MAXN];
void a_sieve(long long n)    {
    memset(vis, true, sizeof(vis));
    for (int i = 2; i <= n; ++i)    {
        if (vis[i])    {
            b[++cnt] = i;
            for (int j = 2; j * i <= n; ++j)    vis[i * j] = false;
        }
    }
    for (int i = 1; i <= cnt; ++i)    cout << b[i] << " ";
    cout << '\n';
}

// 欧拉筛
void o_sieve(long long n)    {
    memset(vis, true, sizeof(vis));
    for (int i = 2; i <= n; ++i)    {
        if (vis[i])    b[++cnt] = i;
        for (int j = 1; j <= cnt; ++j)    {
            if (b[j] * i > n)    break;
            vis[b[j] * i] = false;
            if (i % b[j] == 0) break;
        }
    }
    for (int i = 1; i <= cnt; ++i)    cout << b[i] << ' ';
    cout << '\n';
}

int main(void)    {
    long long a[] = {5, 4, 3, 2, 1};
    quick_sort(a, 0, 4);
    for (int i = 0; i < 5; ++i)    cout << a[i] << " ";
    cout << "\n";

    // cout << gcd_2(18, 27) << "\n";

    // 不借助第三个变量来实现交换两数
    int m = 5, n = 3;
    m = m ^ n;
    n = m ^ n;
    m = m ^ n;
    cout << m << " " << n << '\n';

    vector<long long> v {4, 6, 8, 13, 17, 20};
    if (bin_s(v, 22))    cout << "find it\n";

    o_sieve(50);

    return 0;
}