#include <bits/stdc++.h>
using namespace std;
#define i64 long long

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, k; cin >> n >> k;
    bool b[1005];
    i64 cnt = n, i = 1, j = 0;
    memset(b, 0, sizeof(b));
    while (cnt != 0) {
        j = (j+1 > n) ? j-n+1 : j+1;
        if (!b[j]) {
            if (cnt == 1) {cout << j << '\n'; break;}
            if (!(i%k) || i%10==k) {
                b[j] = true; // out
                cnt--;
            }
            i++;
        }
    }
    return 0;
}