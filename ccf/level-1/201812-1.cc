#include <bits/stdc++.h>
using namespace std;
#define i64 long long

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    i64 r, y, g, time = 0;
    cin >> r >> y >> g;
    i64 n;
    cin >> n;
    while (n--) {
        i64 k, t;
        cin >> k >> t;
        switch(k) {
            case 0: time += t; break;
            case 1: time += t; break;
            case 2: time += (t+r); break;
            case 3: break;
        }
    }
    cout << time << '\n';
    return 0;
}