#include <bits/stdc++.h>
using namespace std;
#define i64 unsigned long long
#define rep(i, a, b) for(int i=(a), __=(b); i<__; ++i)
i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a;}


i64 extend_gcd(i64 a, i64 b, i64 &x, i64 &y){
	if (b){
		i64 r = extend_gcd(b, a%b, y, x);
		y -= x*(a/b); return r;
	} else { x=1; y=0; return a; }
}
i64 foo(i64 a, i64 b, i64 mod){
	i64 x, y, r = extend_gcd(a, mod, x, y);
	if (b%r) return -1; else x = (x+mod)%mod*b/r;
	return x%(mod/r);
}

void operator+=(pair<i64, i64>& p1, pair<i64, i64>& p2) {
    p1.first = p1.first * p2.second + p1.second * p2.first;
    p1.second = p1.second * p2.second;
    i64 t = gcd(p1.first, p1.second);
    p1.first/=t, p1.second/=t;
}

void solve() {
    const i64 mod = 998244353;
    i64 n; cin >> n;
    i64 res = foo(1, 0, mod);
    rep(i, 0, n) {
        i64 ai, bi; cin >> ai >> bi;
        pair<i64, i64> ex {min(bi*(bi+1)/2-ai*(ai-1)/2, n), (bi-ai+1)*n};
        i64 x = foo(ex.second, ex.first, mod);
        res += x;
        res %= mod;
    }
    cout << res << '\n';
}

int main(int argc, char** argv)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}