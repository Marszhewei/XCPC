#include <bits/stdc++.h>
using namespace std;
#define i64 long long

bool m[105][105];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(m, 0, sizeof(m));
    i64 n; cin >> n;
    while (n--) {
        i64 x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2; ++i)
            for (int j = y1; j < y2; ++j)
                m[i][j] = true;
    }
    i64 cnt = 0;
    for (int i = 0; i <= 100; ++i) 
        for (int j = 0; j <= 100; ++j)
            if (m[i][j]) cnt++;
    cout << cnt << '\n';
    return 0;
}