#include <bits/stdc++.h>

int a[105];
bool b[20005];

using namespace std;
int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(b, true, sizeof(b));
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)   cin >> a[i];
    sort(a, a+n, greater<int>());
    for (int i = 0; i < n - 2; ++i)    {
        for (int j = i + 1; j < n - 1; ++j)    {
            for (int k = j + 1; k < n; ++k)    {
                if (a[i] == (a[j] + a[k]) && a[j] != a[k] && b[a[i]])    {
                    b[a[i]] = false;
                    cnt++;
                    // cout << a[i] << " " << a[j] << " " << a[k] << '\n';
                }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}