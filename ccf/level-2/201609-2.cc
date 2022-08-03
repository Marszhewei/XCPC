#include <bits/stdc++.h>
using namespace std;
#define i64 long long 

bool flag[20];
i64 rest[20];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(flag, false, sizeof(flag));
    memset(rest, 0, sizeof(rest));
    i64 n; cin >> n;
    while (n--) {
        i64 t; cin >> t;
        bool f = true;
        for (int i = 0; i < 20; ++i) {
            if (!flag[i]) {
                rest[i] = 5 - t;
                flag[i] = true;
                for (int j = 1; j <= t; ++j)
                    cout << i*5+j << ' ';
                cout << '\n';
                f = false;
                break;
            }
            else {
                if (rest[i] >= t) {
                    for (int j = (6-rest[i]); j <= (t+5-rest[i]); ++j) 
                        cout << i*5+j << ' ';
                    cout << '\n';
                    rest[i] -= t;
                    f = false;
                    break;
                }
            }
        }
        if (f) {
            for (int i = 0; i < 20; ++i) {
                if (rest[i] != 0) {
                    if (t >= rest[i]) {
                        for (int j = (6-rest[i]); j <= 5; ++j) cout << i*5+j << ' ';
                        cout << '\n';
                    }
                    else {
                        for (int j = (6-rest[i]); j <= (t+5-rest[i]); ++j) cout << i*5+j << ' ';
                        cout << '\n';
                    }
                    t -= rest[i];
                    rest[i] = 0;
                }
            }
        }
    }
    return 0;
}