#include <bits/stdc++.h>
using namespace std;
#define i64 long long

i64 B[105];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, maxs = 0, mins = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> B[i];
    maxs = mins = B[0];
    for (int i = 1; i < n; ++i) {
        if (B[i] == B[i-1]) maxs += B[i];
        else {
            maxs += B[i]; mins += B[i];
        }
    }
    cout << maxs << '\n' << mins << '\n';
    return 0;
}