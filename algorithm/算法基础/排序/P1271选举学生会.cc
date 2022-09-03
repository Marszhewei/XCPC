#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    int ar[2000005];
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> ar[i];
    sort(ar, ar+m);
    for (int i = 0; i < m; ++i)
        cout << ar[i] << ' ';
    cout << endl;
}

int main(void)
{
    solve();
    return 0;
}