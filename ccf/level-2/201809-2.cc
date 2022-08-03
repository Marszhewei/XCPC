#include <bits/stdc++.h>
using namespace std;
#define i64 long long

bool A[1000005], B[1000005];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(A, false, sizeof(A));
    memset(B, false, sizeof(B));
    i64 n, cnt = 0; cin >> n;
    for (int i = 0; i < n; ++i) {
        i64 a, b; cin >> a >> b;
        for (int j = a; j < b; ++j) A[j] = true;
    }
    for (int i = 0; i < n; ++i) {
        i64 c, d; cin >> c >> d;
        for (int j = c; j < d; ++j) B[j] = true;
    }
    for (int i = 1; i <= 1000005; ++i) {
        if (A[i] && B[i]) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}