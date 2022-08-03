#include <bits/stdc++.h>

using namespace std;
int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, l = 1, ll = 1, res = 0;
    cin >> n;
    for (int i = 2 ;i < n; ++i)    {
        res = ll + l;
        ll = l;
        l = res;
    }
    if (n < 3 && n > 0)     cout << "1.00\n";
    else cout << res << ".00\n";
    return 0;
}