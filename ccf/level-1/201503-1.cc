#include <bits/stdc++.h>
using namespace std;

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    int base[1001][1001];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> base[i][j];
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) cout << base[j][i] << ' ';
        cout << '\n';
    }
    return 0;
}