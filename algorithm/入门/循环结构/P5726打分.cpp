#include <bits/stdc++.h>
#define INF 11
using namespace std;
int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s = 0, minn = INF, maxn = -INF;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)    {
        cin >> v[i];s+=v[i];
        if (minn > v[i])    minn = v[i];
        if (maxn < v[i])    maxn = v[i];
    }
    cout << fixed << setprecision(2) << 1.0 * (s - minn - maxn) / (n - 2) << "\n";
    

    return 0;
}