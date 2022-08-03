#include <bits/stdc++.h>
using namespace std;
#define i64 long long

vector<i64> a;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, N, s = 0, t;
    cin >> n >> N;
    a.push_back(0);
    for (int i = 0; i < n; ++i) {
        cin >> t;
        a.push_back(t);
    }
    int i = 1;
    for ( ; i <= n; ++i) {
        s += (a[i]-a[i-1]) * (i-1);
    }
    s += (i-1) * (N - a.back());
    cout << s << '\n';
    return 0;
}