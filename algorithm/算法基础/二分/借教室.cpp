#include <bits/stdc++.h>

#define LL long long
const LL maxn = 1e6+100;
LL Room[maxn], D[maxn], L[maxn], R[maxn], S[maxn], Diff[maxn];
LL n, m;


// O(n)
bool check(int idx)    {
    memset(Diff, 0, sizeof(Diff));
    memset(S, 0, sizeof(S));
    // 差分
    for (int i = 1; i <= idx; ++i)    {
        Diff[L[i]] += D[i];
        Diff[R[i] + 1] -= D[i];
    }
    // 前缀和
    for (int i = 1; i <= n; ++i)    {
        S[i] = S[i-1] + Diff[i];
        if (S[i] > Room[i])    return false;
    }
    return true;
}  


// O(mn)
bool check_1(int idx)    {
    memset(S, 0, sizeof(S));
    for (int i = 1; i <= idx; ++i)    {
        for (int j = L[i]; j <= R[i]; ++j)    {
            S[j] += D[i];
        }
    }
    for (int j = 1; j <= n; ++j)    {
        if (S[j] > Room[j])    {
            return false;
        }
    }
    return true;
}

using namespace std;
int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)    cin >> Room[i];
    for (int i = 1; i <= m; ++i)    cin >> D[i] >> L[i] >> R[i];

    // 暴力（40分）  O(mn)
    // memset(S, 0, sizeof(S));
    // for (int i = 1; i <= m; ++i)    {
    //     for (int j = L[i]; j <= R[i]; ++j)    {
    //         S[j] += D[i];
    //     }
    //     for (int j = 1; j <= n; ++j)    {
    //         if (S[j] > Room[j])    {
    //             cout << "-1\n" << i << "\n";
    //             return 0;
    //         }
    //     }
    // }

    // 二分 (左闭右闭区间)
    if (check(m))    {cout << 0 << "\n";return 0;}
    int left = 1, right = m+1, mid;
    while (left < right)    {
        mid = (left + right) / 2;
        if (check(mid))    left = mid+1;
        else    right = mid;
    }
    cout << "-1\n" << right << "\n";
    return 0;
}