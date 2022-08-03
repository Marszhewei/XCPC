#include <bits/stdc++.h>
using namespace std;
#define i64 long long

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M, T = 0, k, P = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        i64 a0, s1 = 0, a; cin >> a0;
        for (int j = 0; j < M; ++j) {
            cin >> a;
            s1 -= a;
            a0 += a;
        }
        T += a0;
        if (P < s1) {P = s1; k = i;}
    }
    cout << T << ' ' << k << ' ' << P << '\n';
    return 0;
}