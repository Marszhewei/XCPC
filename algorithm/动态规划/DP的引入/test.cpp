#include <bits/stdc++.h>

using namespace std;
int main(void)    {
    int n, m;
    cin >> n >> m;
    int v[105];
    for (int i = 0; i < n; ++i)    {
        cin >> v[i];
    }
    int res[105];
    for (int i = 0; i < n - m%n; ++i)    {
        res[i] = v[i+m%n];
    }
    for (int i = n - m%n, j = 0; i < n; ++i)    {
        res[i] = v[j++];
    }
    for (int i = 0; i < n; ++i)    {
        cout << res[i];
        if (i != n-1)    cout << ' ';
    }
    cout << '\n';

    return 0;
}