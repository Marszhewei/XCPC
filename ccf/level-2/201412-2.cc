#include <bits/stdc++.h>
using namespace std;
#define i64 long long

i64 m[505][505];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, k = 2; cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> m[i][j];
    while (k < n + 2) {
        if (k%2) {
            for (int i = 1; i < k; ++i) {
                cout << m[i][k-i] << ' ';
            }
        }
        else {
            for (int i = 1; i < k; ++i) {
                cout << m[k-i][i] << ' ';
            }
        }
        k++;
    }
    while (k < 2 * n + 1) {
        if (k%2) {
            for (int i = n; i >= k - n; i--) {
                cout << m[k-i][i] << ' ';
            }
        }
        else {
            for (int i = n; i >= k - n; i--) {
                cout << m[i][k-i] << ' ';
            }
        }
        k++;
    }
    return 0;
}

// i+j = 2
// i+j = 3
// ...
// i+j = n+1
// i+j = n+2
// ...
// i+j = n+n