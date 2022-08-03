#include <bits/stdc++.h>
#define _for(i, a, b) for (int i = a; i < b; ++i)

using namespace std;
vector<int> v(1005);
int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    _for(i, 0, n) cin >> v[i];
    // 偷首不偷尾
    int dp1 = 0, dp2 = v[0];
    _for(i, 2, n)    {
        dp1 = max(dp2, dp1+v[i-1]);
        swap(dp1, dp2);
    }

    // 偷尾不偷首
    reverse(v.begin(), v.end());
    int dp3 = 0, dp4 = v[0];
    _for(i, 2, n)    {
        dp3 = max(dp4, dp3+v[i-1]);
        swap(dp3, dp4);
    }
    cout << "res: " << max(dp2, dp4) << '\n';
    return 0;
}