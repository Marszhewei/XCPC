#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector<long long> v;

void solve() { // 前缀和做法
    vector<long long> sm(n); v[0] = 0, sm[0] = 0;
    for (int i = 1; i < n; ++i) sm[i] = sm[i-1] + v[i];
    long long mx = sm[n-1];
    if (k >= n-1) {cout << 0 << '\n'; return;}
    for (int i = 1; i <= n-k; ++i) {
        if (sm[n-1] - (sm[i+k-1]-sm[i-1]) < mx) mx = sm[n-1] - (sm[i+k-1]-sm[i-1]);
    }
    cout << mx << '\n';
}

// dp做法
vector<vector<long long> > dp(1000010, vector<long long>(2));
void dp_solve() {
    for(int i = 2 ; i <= n; i++) {
		dp[i][0] = dp[i-1][0] + v[i-1];
		if (i > k) dp[i][1] = dp[i-k][0];
		dp[i][1] = min(dp[i-1][1] + v[i-1], dp[i][1]);//状态转移方程
	}
    cout << dp[n][1] << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    v.resize(n);
    for (int i = 1; i < n; ++i) cin >> v[i];
    // solve();
    dp_solve();
    return 0;
}