#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m[1001];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> m[i];
    sort(m, m+n);
    int cnt  =0;
    for (int i = 1; i < n; ++i) {
        if (m[i]- m[i-1] == 1) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}