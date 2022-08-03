#include <bits/stdc++.h>

using namespace std;

// 求一个数的所有因数
const int MAXN = 1 << 8;
vector<int> v;
void solve(int n)    {
    for (int i = 2; i * i <= n; ++i)    {
        if (n % i == 0)    {
            v.push_back(i);
            if (n / i != i)    v.push_back(n / i);
        }
    }
    // print
    for (auto i: v)    cout << i << " ";
    cout << '\n';
}

// 求一个数的所有质因数
void solve_prime(int n)   {
    for (int i = 2; i * i <= n; ++i)     {
        if (n % i == 0)    {
            v.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1)    v.push_back(n);
    // print
    for (auto i: v)    cout << i << ' ';
    cout << '\n';
}


int main(void)   {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(2 * 3 * 2 * 2);

    return 0;
}