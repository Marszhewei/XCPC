#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, p; cin >> n >> p;
    vector<int> inv(p);
    inv[1] = 1;
    for(int i = 2; i < p; ++ i) inv[i] = (p - p / i) * inv[p % i] % p;
    for (int i = 1; i <= n; ++i) cout << inv[i] << '\n';
    return 0;
}